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

#include "IsometricMath.hpp"



fe::Vector2 fe::toIsometricPosition(const fe::Vector3 coord,
                                    const fe::MapData &map_data) {
        return fe::Vector2(map_data.getPosition().x+(coord.x-coord.y-1)*map_data.getTileBaseHeight(),
                       map_data.getPosition().y+(coord.x+coord.y)*map_data.getTileBaseHeight()/2
                       -coord.z*(map_data.getTileSize().y-map_data.getTileBaseHeight()));
}

fe::Vector3 fe::getTileCoordAtPixels(const fe::Vector2 pixels,
                                     const unsigned int layer,
                                     const fe::MapData &map_data,
                                     const fe::Camera *camera) {
    if(camera==0)
    return fe::Vector3((static_cast<int>(pixels.y - map_data.getPosition().y) + (layer-1)*map_data.getTileBaseHeight() +                    static_cast<int>(pixels.x - map_data.getPosition().x)/2)/map_data.getTileBaseHeight(),
                   (static_cast<int>(pixels.y - map_data.getPosition().y) + (layer-1)*map_data.getTileBaseHeight() -                    static_cast<int>(pixels.x - map_data.getPosition().x)/2)/map_data.getTileBaseHeight(), layer);
    if(camera!=0)
    return fe::Vector3((static_cast<int>(pixels.y - map_data.getPosition().y+
camera->getViewCenter().y-camera->getViewDimensions().y/2) + (layer-1)*map_data.getTileBaseHeight() +
                    static_cast<int>(pixels.x - map_data.getPosition().x+camera->getViewCenter().x-camera->getViewDimensions().x/2)/2)/map_data.getTileBaseHeight(),
                   (static_cast<int>(pixels.y - map_data.getPosition().y+camera->getViewCenter().y-camera->getViewDimensions().y/2) + (layer-1)*map_data.getTileBaseHeight() -
                    static_cast<int>(pixels.x - map_data.getPosition().x+camera->getViewCenter().x-camera->getViewDimensions().x/2)/2)/map_data.getTileBaseHeight(), layer);
}
