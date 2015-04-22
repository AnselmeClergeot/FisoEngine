#include "DrawingFuncs.h"

bool isVisible(const Vector2 position, const Vector2 elementSize, ScreenInfos &screenInfos) {
    return (position.x+elementSize.x>0 && position.y+elementSize.y>0 &&
            position.x < screenInfos.getWindowResolution().x && position.y < screenInfos.getWindowResolution().y);
}
