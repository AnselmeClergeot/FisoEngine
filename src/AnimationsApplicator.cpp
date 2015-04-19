#include "AnimationsApplicator.h"

AnimationsApplicator::AnimationsApplicator(TileGroup &mapTilegroup, TileGroup &shadowsTilegroup, Animator &animator) :
m_mapTilegroup(mapTilegroup), m_shadowsTilegroup(shadowsTilegroup), m_animator(animator)
{

}
