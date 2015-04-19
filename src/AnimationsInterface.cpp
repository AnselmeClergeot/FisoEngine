#include "AnimationsInterface.h"

AnimationsInterface::AnimationsInterface(Animator &animator) : m_animator(animator)
{

}

void AnimationsInterface::setSpeed(const unsigned int speed) {
    m_animator.setSpeed(speed);
}

void AnimationsInterface::setAnimation(const unsigned tile, const unsigned int length) {
    m_animator.setAnimation(tile, length);
}

void AnimationsInterface::next() {
    m_animator.next();
}

void AnimationsInterface::setSingleAnimKind(const unsigned int tile) {
    m_animator.setSingleAnimKind(tile);
}

void AnimationsInterface::setDirectionOf(const Vector3 coord, AnimDirection direction) {
    m_animator.setDirectionOf(coord, direction);
}

void AnimationsInterface::setDirectionOf(const unsigned int x, const unsigned int y, const unsigned int z,                                          AnimDirection direction) {
    setDirectionOf(Vector3(x, y, z), direction);
}

void AnimationsInterface::setKindOf(const Vector3 coord, AnimKind kind) {
    m_animator.setKindOf(coord, kind);
}

void AnimationsInterface::setKindOf(const unsigned int x, const unsigned int y, const unsigned int z, AnimKind kind){
    setKindOf(Vector3(x, y, z), kind);
}

void AnimationsInterface::launchAnimation(const Vector3 coord) {
    m_animator.setAnimStatus(coord, true);
}

void AnimationsInterface::launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    launchAnimation(Vector3(x, y, z));
}

void AnimationsInterface::stopAnimation(const Vector3 coord) {
    m_animator.setAnimStatus(coord, false);
}

void AnimationsInterface::stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    stopAnimation(Vector3(x, y, z));
}
