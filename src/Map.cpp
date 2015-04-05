#include "Map.h"

Map::Map(RunEnvironment &environment) : m_environment(environment),
                                        m_data(),
                                        m_configsLoader(m_data), m_configsSaver(m_data),
                                        m_tileGroup(m_data, m_environment), m_shadowsTilegroup(m_data, m_environment),
                                        m_shadowsStates(),
                                        m_shadowsInitializer(m_shadowsTilegroup, m_shadowsStates, m_data),
                                        m_shadowsInterface(m_shadowsInitializer, m_shadowsStates, m_shadowsTilegroup),
                                        m_dynamicShader(m_data, m_tileGroup, m_shadowsTilegroup),
                                        m_entityContainer(m_data, m_environment), m_entityInterface(m_entityContainer), m_interposing(m_entityContainer)
{}

void Map::init() {
    m_configsLoader.load();
    m_tileGroup.setConfiguration(m_data.getTempConf());
    m_tileGroup.initialize();
}

void Map::save() {
    m_configsSaver.save();
}

void Map::addLayerFile(const std::string path) {
    m_configsLoader.addLoadFile(path);
    m_configsSaver.addLoadFile(path);
}

void Map::setTileset(const std::string path) {
    m_tileGroup.setTilesetPath(path);
}

void Map::setTileSize(const Vector2 size) {
    m_data.setTileSize(size);
}

void Map::setTileSize(const unsigned int w, const unsigned int h) {
    setTileSize(Vector2(w, h));
}

void Map::setTileBaseHeight(const unsigned int h) {
    m_data.setTileBaseHeight(h);
}

void Map::setInvisibleTile(const unsigned int tile) {
    m_data.setInvisibleTile(tile);
}

void Map::addTranslucentTile(const unsigned int tile) {
    m_data.addTranslucentTile(tile);
}

void Map::setTileAt(const Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw) {
    if(modifConf)
        m_data.getPermConf().at(coord.x, coord.y, coord.z) = tile;

    if(modifDraw)
    {
        m_data.getTempConf().at(coord.x, coord.y, coord.z) = tile;
        m_tileGroup.setTileAt(coord, tile);

        if(m_shadowsStates.isInitialized())
            m_dynamicShader.updateShading(coord);
    }
}

void Map::setTileAt(const unsigned int x, const unsigned int y, const unsigned int z, const unsigned int tile,                    bool modifConf, bool modifDraw) {
    setTileAt(Vector3(x, y, z), tile, modifConf, modifDraw);
}

void Map::setSpecificOpacity(const Vector3 coord, const unsigned int opacity) {
    m_tileGroup.setSpecificOpacity(m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z), opacity);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfSpecific(coord);
}

void Map::setSpecificOpacity(const unsigned int x,const unsigned int y,const unsigned int z,const unsigned int opacity) {
    setSpecificOpacity(Vector3(x, y, z), opacity);
}

void Map::setTypeOpacity(const unsigned int tile, const unsigned int opacity) {
    m_tileGroup.setTypeOpacity(tile, opacity);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfType(tile);
}

void Map::setGroupOpacity(const unsigned int opacity) {
    m_tileGroup.setGroupOpacity(opacity);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfAll();
}

void Map::setPosition(const Vector2 pos) {
    m_data.setPosition(pos);
    m_tileGroup.updatePosition();

    if(m_shadowsStates.isInitialized())
      m_shadowsTilegroup.updatePosition();
}

void Map::setPosition(const unsigned int x, const unsigned int y) {
    setPosition(Vector2(x, y));
}

void Map::move(const Vector2 rate) {
    m_data.move(rate);
    m_tileGroup.updatePosition();

    if(m_shadowsStates.isInitialized())
        m_shadowsTilegroup.updatePosition();
}

void Map::move(const unsigned int rx, const unsigned int ry) {
    move(Vector2(rx, ry));
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(int layer(0); layer<m_data.getSize().y; layer++)
    {
        m_tileGroup.draw(target, states, layer, &m_interposing);

        if(m_shadowsStates.isOn())
            m_shadowsTilegroup.draw(target, states, layer);
    }
}

Vector3 Map::getDimensions() const {
    return Vector3(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y);
}

Vector2 Map::getPosition() const {
    return m_data.getPosition();
}

Vector2 Map::getTileSize() const {
    return m_data.getTileSize();
}

unsigned int Map::getTileBaseHeight() const {
    return m_data.getTileBaseHeight();
}

unsigned int Map::getInvisibleTile() const {
    return m_data.getInvisibleTile();
}

bool Map::isTranslucent(const unsigned int tile) const {
    return m_data.isTranslucent(tile);
}

unsigned int Map::getTileAt(const Vector3 coord) {
    return m_data.getPermConf().at(coord.x, coord.y, coord.z);
}

unsigned int Map::getTileAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getTileAt(Vector3(x, y, z));
}

unsigned int Map::getGroupOpacity() const {
    return m_tileGroup.getGroupOpacity();
}

unsigned int Map::getTileOpacity(const Vector3 coord) {
    return m_tileGroup.getTileOpacity(m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z));
}

unsigned int Map::getTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getTileOpacity(Vector3(x, y, z));
}

Vector2 Map::getTileCoordAtPixels(const Vector2 pixels, const unsigned int layer) const {
    return ::getTileCoordAtPixels(pixels, layer, m_data);
}

ShadowsInterface &Map::shadows() {
    return m_shadowsInterface;
}

EntitiesInterface &Map::entities() {
    return m_entityInterface;
}
