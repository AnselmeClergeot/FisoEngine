#include "IsometricMath.h"

Vector2 toIsometricPosition(const Vector3 coord, const MData &map_data)
{
    return Vector2(map_data.getPosition().x+(coord.x-coord.y-1)*map_data.getTileBaseHeight(),
                   map_data.getPosition().y+(coord.x+coord.y)*map_data.getTileBaseHeight()
                    /2-coord.z*(map_data.getTileSize().y-map_data.getTileBaseHeight()));
}
