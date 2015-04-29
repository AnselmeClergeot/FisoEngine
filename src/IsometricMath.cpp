#include "IsometricMath.h"

Vector2 toIsometricPosition(const Vector3 coord, const MapData &map_data) {
    return Vector2(map_data.getPosition().x+(coord.x-coord.y-1)*map_data.getTileBaseHeight(),
                   map_data.getPosition().y+(coord.x+coord.y)*map_data.getTileBaseHeight()/2
                   -coord.z*(map_data.getTileSize().y-map_data.getTileBaseHeight()));
}

Vector2 getTileCoordAtPixels(const Vector2 pixels, const unsigned int layer, const MapData &map_data) {
    return Vector2((static_cast<int>(pixels.y - map_data.getPosition().y) + (layer-1)*map_data.getTileBaseHeight() +                    static_cast<int>(pixels.x - map_data.getPosition().x)/2)/map_data.getTileBaseHeight(),
                   (static_cast<int>(pixels.y - map_data.getPosition().y) + (layer-1)*map_data.getTileBaseHeight() -                    static_cast<int>(pixels.x - map_data.getPosition().x)/2)/map_data.getTileBaseHeight());
}
