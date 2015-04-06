#include "DrawingFuncs.h"

bool isVisible(const Vector2 position, const Vector2 elementSize, RunEnvironment &environment) {
    return (position.x+elementSize.x>0 && position.y+elementSize.y>0 &&
            position.x < environment.getWindowResolution().x && position.y < environment.getWindowResolution().y);
}
