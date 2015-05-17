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
   m_interposing(m_entityContainer),
   m_animator(m_data, m_tileGroup, m_dynamicShader, m_shadowsStates, m_camera)
{
    m_camera.setTileGroups(m_tileGroup, m_shadowsTilegroup);
    m_camera.setEntitiesContainer(m_entityContainer);
}

void fe::Map::create() {
    m_configsLoader.load();
    m_tileGroup.initialize();
    m_tileGroup.configureWith(m_data.getTempConf());

    m_tileGroup.reloadOpacities();
    m_animator.resizeTileAnimDataList();
}

void fe::Map::reload() {
    create();

    m_tileGroup.setGroupOpacity(255);
    m_tileGroup.reloadOpacities();

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

void fe::Map::setTileOpacity(const fe::Vector3 coord, const unsigned int opacity) {
    m_tileGroup.setTileOpacity(coord, opacity);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfSpecific(coord);
}

void fe::Map::setTileOpacity(const unsigned int x,const unsigned int y,const unsigned int z,
                             const unsigned int opacity) {
    setTileOpacity(fe::Vector3(x, y, z), opacity);
}

void fe::Map::setOpacityOfType(const unsigned int tile, const unsigned int opacity) {
    m_tileGroup.setTypeOpacity(tile, opacity);

    if(m_shadowsStates.isInitialized())
        m_dynamicShader.updateOpacityOfType(tile);
}

void fe::Map::setMapOpacity(const unsigned int opacity) {
    m_tileGroup.setGroupOpacity(opacity);

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
    for(int layer(0); layer<m_data.getSize().y; layer++)
    {
        m_tileGroup.draw(target, layer, &m_interposing);

        if(m_shadowsStates.isOn())
            m_shadowsTilegroup.draw(target, layer);

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

unsigned int fe::Map::getMapOpacity() const {
    return m_tileGroup.getGroupOpacity();
}

unsigned int fe::Map::getTileOpacity(const fe::Vector3 coord) {
    return m_tileGroup.getTileOpacity(coord);
}

unsigned int fe::Map::getTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getTileOpacity(fe::Vector3(x, y, z));
}

unsigned int fe::Map::getOpacityOfType(const unsigned int type) const {
    return m_tileGroup.getOpacityOfType(type);
}

fe::Vector2 fe::Map::getTileCoordAtPixels(const fe::Vector2 pixels, const unsigned int layer) const {
    return fe::getTileCoordAtPixels(pixels, layer, m_data, &m_camera);
}

fe::Vector2 fe::Map::getTileCoordAtPixels(const unsigned int px, const unsigned int py, const unsigned int layer) const
{
    return getTileCoordAtPixels(fe::Vector2(px, py), layer);
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
