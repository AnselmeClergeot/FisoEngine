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

#include "Animator.hpp"

fe::Animator::Animator(fe::MapData &mapData,
                       fe::TileGroup &mapTilegroup,
                       fe::DynamicShader &shader,
                       fe::ShadowsSystemStates &shadowsStates,
                       fe::Camera &camera) : m_tileAnimationsData(),
                                             m_mapData(mapData),
                                             m_timer(),
                                             m_speed(150),
                                             m_animations(),
                                             m_mapTilegroup(mapTilegroup),
                                             m_shader(shader),
                                             m_shadowsStates(shadowsStates),
                                             m_camera(camera)
{ }

void fe::Animator::resizeTileAnimDataList() {
    m_tileAnimationsData.resize(m_mapData.getTempConf().getW(),
                                m_mapData.getTempConf().getH(),
                                m_mapData.getTempConf().getD());

    for(int x(0); x<m_tileAnimationsData.getW(); x++)
        for(int y(0); y<m_tileAnimationsData.getH(); y++)
            for(int z(0); z<m_tileAnimationsData.getD(); z++)
            updateTileAt(fe::Vector3(x, y, z));
}

void fe::Animator::setAnimation(const unsigned tile, const unsigned int length) {
    m_animations.push_back(fe::Vector3(tile, length, 0));

    for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
        {
            m_tileAnimationsData.at(i).setLength(length);
            m_tileAnimationsData.at(i).setKind(fe::AnimKind::Global);
        }
    }
}

void fe::Animator::setSpeed(const unsigned int speed) {
    m_speed = speed;
}

void fe::Animator::next() {
    if(m_timer.getElapsedTime() > m_speed)
    {
        m_timer.restart();

        for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
            m_tileAnimationsData.at(i).updateX();
    }
    apply();
}

void fe::Animator::setSingleAnimKind(const unsigned int tile) {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
            m_animations[i].z = 1;
    }

    for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData.at(i).setKind(fe::AnimKind::Single);
    }
}

void fe::Animator::setGlobalAnimKind(const unsigned int tile) {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
            m_animations[i].z = 0;
    }

    for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData.at(i).setKind(fe::AnimKind::Global);
    }
}

void fe::Animator::setDirectionOf(const fe::Vector3 coord, fe::AnimDirection direction) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setDirection(direction);
}

void fe::Animator::setDirectionOf(const unsigned int x, const unsigned int y, const unsigned int z,
                                  fe::AnimDirection direction) {
    setDirectionOf(fe::Vector3(x, y, z), direction);
}

void fe::Animator::setKindOf(const fe::Vector3 coord, fe::AnimKind kind) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setKind(kind);
}

void fe::Animator::setKindOf(const unsigned int x, const unsigned int y, const unsigned int z, fe::AnimKind kind) {
    setKindOf(fe::Vector3(x, y, z), kind);
}

void fe::Animator::launchAnimation(const fe::Vector3 coord) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setStatus(fe::AnimStatus::On);
}

void fe::Animator::launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    launchAnimation(Vector3(x, y, z));
}

void fe::Animator::stopAnimation(const fe::Vector3 coord) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setStatus(fe::AnimStatus::Off);
}

void fe::Animator::stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    stopAnimation(Vector3(x, y, z));
}

void fe::Animator::apply() {
    for(int x(0); x<m_tileAnimationsData.getW(); x++)
        for(int y(0); y<m_tileAnimationsData.getH(); y++)
            for(int z(0); z<m_tileAnimationsData.getD(); z++)
    {
        if(m_mapData.getTempConf().at(x, y, z)!=m_mapData.getInvisibleTile() &&
           m_tileAnimationsData.at(x, y, z).getLength()>1)
        {
            m_mapTilegroup.setTileTilesetX(fe::Vector3(x, y, z),
                                           fe::Vector2(m_tileAnimationsData.at(x, y, z).getX(),
                                                       m_mapData.getTempConf().at(x, y, z)));

            if(m_shadowsStates.isOn())
                m_shader.updateTileFromAnim(fe::Vector3(x, y, z), m_tileAnimationsData.at(x, y, z).getX());
        }
    }
}

unsigned int fe::Animator::getSpeed() const {
    return m_speed;
}

void fe::Animator::updateTileAt(const fe::Vector3 coord) {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==m_mapData.getTempConf().at(coord.x, coord.y, coord.z))
        {
            if(m_animations[i].z==0)
                m_tileAnimationsData.at(coord.x, coord.y, coord.z).setKind(fe::AnimKind::Global);

            if(m_animations[i].z==1)
                m_tileAnimationsData.at(coord.x, coord.y, coord.z).setKind(fe::AnimKind::Single);

            m_tileAnimationsData.at(coord.x, coord.y, coord.z).setLength(m_animations[i].y);
            m_tileAnimationsData.at(coord.x, coord.y, coord.z).setDirection(fe::AnimDirection::Right);

            return;
        }
    }

    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setLength(1);
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setDirection(fe::AnimDirection::Right);
}

unsigned int fe::Animator::getFrameAt(const fe::Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getX();
}

unsigned int fe::Animator::getFrameAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getFrameAt(fe::Vector3(x, y, z));
}

bool fe::Animator::getStatusAt(const fe::Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getStatus();
}

bool fe::Animator::getStatusAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getStatusAt(fe::Vector3(x, y, z));
}

fe::AnimKind fe::Animator::getKindAt(const Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getKind();
}

fe::AnimKind fe::Animator::getKindAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getKindAt(Vector3(x, y, z));
}

fe::AnimDirection fe::Animator::getDirectionAt(const Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getDirection();
}

fe::AnimDirection fe::Animator::getDirectionAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getDirectionAt(fe::Vector3(x, y, z));
}

unsigned int fe::Animator::getAnimLengthOfTile(const unsigned int tile) const {
    assert(tileIsAnimated(tile));

    for(std::size_t i(0); i<m_animations.size(); i++)
        if(m_animations[i].x==tile)
            return m_animations[i].y;
}

fe::AnimKind fe::Animator::getAnimKindOfTile(const unsigned int tile) const {
    assert(tileIsAnimated(tile));

    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
        {
            if(m_animations[i].z==0)
                return fe::AnimKind::Global;
            else
                return fe::AnimKind::Single;
        }
    }
}

bool fe::Animator::tileIsAnimated(const unsigned int tile) const {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
            return true;
    }

    return false;
}
