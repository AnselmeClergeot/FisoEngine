/*
This file is part of the FisoEngine sources : a simple C++ tile-based isometric engine.
For more informations about FisoEngine, see : https://github.com/AnselmeClergeot/FisoEngine.
You can contact Anselme Clergeot, the developer, at: anselmedu25@hotmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Map.hpp"

fe::Map::Map(fe::Camera &camera)
 : m_camera(camera),
   m_data(),
   m_configsLoader(m_data), m_configsSaver(m_data),
   m_tileGroup(m_data, m_camera), m_shadowsTilegroup(m_data, m_camera),
   m_shadowsStates(),
   m_dynamicShader(m_data, m_tileGroup, m_shadowsTilegroup),
   m_shadowsInitializer(m_shadowsTilegroup, m_shadowsStates, m_data, m_dynamicShader),
   m_shadowsInterface(m_shadowsInitializer, m_shadowsStates, m_shadowsTilegroup),
   m_entityContainer(m_data, m_camera),
   m_interposing(m_entityContainer, m_data),
   m_animator(m_data, m_tileGroup, m_dynamicShader, m_shadowsStates, m_camera)
{
    m_camera.setTileGroups(m_tileGroup, m_shadowsTilegroup);
    m_camera.setEntitiesContainer(m_entityContainer);
}

void fe::Map::create() {
    m_configsLoader.load();
    m_tileGroup.initialize();
    m_tileGroup.configureWith(m_data.getTempConf());

    m_tileGroup.reloadColors();
    m_animator.resizeTileAnimDataList();
}

void fe::Map::reload() {
    create();

    m_tileGroup.setGroupColor(fe::Color());
    m_tileGroup.reloadColors();

    if(m_shadowsStates.isInitialized())
        m_shadowsInterface.init();
}

void fe::Map::save() {
    m_configsSaver.save();
}

void fe::Map::addLayerFile(const std::string path) {
    m_configsLoader.addLoadFile(path);
    m_configsSaver.addLoadFile(path);
}

void fe::Map::resetLayerFiles() {
    m_configsLoader.resetLayerList();
    m_configsSaver.resetLayerList();
}

void fe::Map::setTileset(const std::string path) {
    m_tileGroup.setTilesetPath(path);
}

void fe::Map::setTileSize(const fe::Vector2 size) {
    m_data.setTileSize(size);
}

void fe::Map::setTileSize(const unsigned int w, const unsigned int h) {
    setTileSize(fe::Vector2(w, h));
}

void fe::Map::setTileBaseHeight(const unsigned int h) {
    m_data.setTileBaseHeight(h);
}

void fe::Map::setInvisibleTile(const unsigned int tile) {
    m_data.setInvisibleTile(tile);
    addTranslucentTile(tile);
}

void fe::Map::addTranslucentTile(const unsigned int tile) {
    m_data.addTranslucentTile(tile);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateShadingOfAll();
}

void fe::Map::removeTranslucentTile(const unsigned int tile) {
    m_data.removeTranslucentTile(tile);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateShadingOfAll();
}

void fe::Map::setTileAt(const fe::Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw) {
    if(modifConf)
        m_data.getPermConf().at(coord.x, coord.y, coord.z) = tile;

    if(modifDraw)
    {
        m_data.getTempConf().at(coord.x, coord.y, coord.z) = tile;
        m_tileGroup.setTileAt(coord, tile);

        m_animator.updateTileAt(coord);

        if(m_shadowsStates.isInitialized())
            m_dynamicShader.updateShading(coord);
    }
}

void fe::Map::setTileAt(const unsigned int x, const unsigned int y, const unsigned int z, const unsigned int tile,                        bool modifConf, bool modifDraw) {
    setTileAt(fe::Vector3(x, y, z), tile, modifConf, modifDraw);
}

void fe::Map::setTileColor(const fe::Vector3 coord, const fe::Color color) {
    m_tileGroup.setTileColor(coord, color);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfSpecific(coord);
}

void fe::Map::setTileColor(const unsigned int x,const unsigned int y,const unsigned int z,
                             const fe::Color color) {
    setTileColor(fe::Vector3(x, y, z), color);
}

void fe::Map::setTileOpacity(const fe::Vector3 coord, const unsigned int opacity) {
    m_tileGroup.setTileOpacity(coord, opacity);
}

void fe::Map::setTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z,
                             const unsigned int opacity) {
    setTileOpacity(fe::Vector3(x, y, z), opacity);
}

void fe::Map::setColorOfType(const unsigned int tile, const fe::Color color) {
    m_tileGroup.setTypeColor(tile, color);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfType(tile);
}

void fe::Map::setMapColor(const fe::Color color) {
    m_tileGroup.setGroupColor(color);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfAll();
}

void fe::Map::setPosition(const fe::Vector2 pos) {
    fe::Vector2 tempPos;
    tempPos = m_data.getPosition();

    m_data.setPosition(pos);
    m_tileGroup.updatePosition();

    for(std::size_t i(0); i<m_entityContainer.getEntitiesNumber(); i++)
        m_entityContainer.entityAt(i).move(m_data.getPosition()-tempPos);

    if(m_shadowsStates.isInitialized())
        m_shadowsTilegroup.updatePosition();
}

void fe::Map::setPosition(const unsigned int x, const unsigned int y) {
    setPosition(fe::Vector2(x, y));
}

void fe::Map::move(const fe::Vector2 rate) {
    m_data.move(rate);
    m_tileGroup.updatePosition();

    for(std::size_t i(0); i<m_entityContainer.getEntitiesNumber(); i++)
        m_entityContainer.entityAt(i).move(rate);

    if(m_shadowsStates.isInitialized())
        m_shadowsTilegroup.updatePosition();
}

void fe::Map::move(const unsigned int rx, const unsigned int ry) {
    move(fe::Vector2(rx, ry));
}

void fe::Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(int x(0); x<m_data.getSize().x; x++)
        for(int y(0); y<m_data.getSize().x; y++)
            for(int z(0); z<m_data.getSize().y; z++)
    {
        m_tileGroup.drawTile(fe::Vector3(x, y, z), target, &m_interposing);

        if(m_shadowsStates.getStatus()==fe::Status::On)
            m_shadowsTilegroup.drawTile(fe::Vector3(x, y, z), target);
    }
}

fe::Vector3 fe::Map::getDimensions() const {
    return fe::Vector3(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y);
}

fe::Vector2 fe::Map::getPosition() const {
    return m_data.getPosition();
}

fe::Vector2 fe::Map::getTileSize() const {
    return m_data.getTileSize();
}

unsigned int fe::Map::getTileBaseHeight() const {
    return m_data.getTileBaseHeight();
}

unsigned int fe::Map::getInvisibleTile() const {
    return m_data.getInvisibleTile();
}

bool fe::Map::isTranslucent(const unsigned int tile) const {
    return m_data.isTranslucent(tile);
}

unsigned int fe::Map::getTileAt(const fe::Vector3 coord) {
    return m_data.getPermConf().at(coord.x, coord.y, coord.z);
}

unsigned int fe::Map::getTileAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getTileAt(fe::Vector3(x, y, z));
}

fe::Color fe::Map::getMapColor() const {
    return m_tileGroup.getGroupColor();
}

fe::Color fe::Map::getTileColor(const fe::Vector3 coord) {
    return m_tileGroup.getTileColor(coord);
}

fe::Color fe::Map::getTileColor(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getTileColor(fe::Vector3(x, y, z));
}

fe::Color fe::Map::getColorOfType(const unsigned int type) const {
    return m_tileGroup.getColorOfType(type);
}

fe::Vector3 fe::Map::getTileCoordAtPixels(const fe::Vector2 pixels, const unsigned int layer) const {
    return fe::getTileCoordAtPixels(pixels, layer, m_data, &m_camera);
}

fe::Vector3 fe::Map::getTileCoordAtPixels(const unsigned int px, const unsigned int py, const unsigned int layer) const
{
    return getTileCoordAtPixels(fe::Vector2(px, py), layer);
}

fe::Vector2 fe::Map::getPositionOfTile(const fe::Vector3 coord) const {
    return fe::toIsometricPosition(coord, m_data);
}

fe::Vector2 fe::Map::getPositionOfTile(const unsigned int x, const unsigned int y, const unsigned int z) const {
    return getPositionOfTile(fe::Vector3(x, y, z));
}

fe::ShadowsInterface &fe::Map::shadows() {
    return m_shadowsInterface;
}

fe::EntitiesContainer &fe::Map::entities() {
    return m_entityContainer;
}

fe::Animator &fe::Map::animator() {
    return m_animator;
}
