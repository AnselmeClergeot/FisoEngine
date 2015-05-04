#include "Animator.h"

Animator::Animator(MapData &mapData,
                   TileGroup &mapTilegroup,
                   DynamicShader &shader,
                   ShadowsSystemStates &shadowsStates,
                   ScreenInfos &screenInfos) : m_tileAnimationsData(),                                               m_mapData(mapData),
                                               m_timer(),
                                               m_speed(150),
                                               m_animations(),
                                               m_mapTilegroup(mapTilegroup),                                               m_shader(shader),
                                               m_shadowsStates(shadowsStates),
                                               m_screenInfos(screenInfos)
{ }

void Animator::resizeTileAnimDataList() {
    m_tileAnimationsData.resize(m_mapData.getTempConf().getW(),
                                m_mapData.getTempConf().getH(),
                                m_mapData.getTempConf().getD());

    for(int x(0); x<m_mapData.getSize().x; x++)
        for(int y(0); y<m_mapData.getSize().x; y++)
            for(int z(0); z<m_mapData.getSize().y; z++)
            updateTileAt(Vector3(x, y, z));
}

void Animator::setAnimation(const unsigned tile, const unsigned int length) {
    m_animations.push_back(Vector3(tile, length, 0));

    for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
        {
            m_tileAnimationsData.at(i).setLength(length);
            m_tileAnimationsData.at(i).setKind(Global);
        }
    }
}

void Animator::setSpeed(const unsigned int speed) {
    m_speed = speed;
}

void Animator::next() {
    if(m_timer.getElapsedTime() > m_speed)
    {
        m_timer.restart();

        for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
            m_tileAnimationsData.at(i).updateX();
    }
    apply();
}

void Animator::setSingleAnimKind(const unsigned int tile) {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
            m_animations[i].z = 1;
    }

    for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData.at(i).setKind(Single);
    }
}

void Animator::setGlobalAnimKind(const unsigned int tile) {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
            m_animations[i].z = 0;
    }

    for(std::size_t i(0); i<m_tileAnimationsData.getSize(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData.at(i).setKind(Global);
    }
}

void Animator::setDirectionOf(const Vector3 coord, AnimDirection direction) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setDirection(direction);
}

void Animator::setDirectionOf(const unsigned int x, const unsigned int y, const unsigned int z,
                              AnimDirection direction) {
    setDirectionOf(Vector3(x, y, z), direction);
}

void Animator::setKindOf(const Vector3 coord, AnimKind kind) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setKind(kind);
}

void Animator::setKindOf(const unsigned int x, const unsigned int y, const unsigned int z, AnimKind kind) {
    setKindOf(Vector3(x, y, z), kind);
}

void Animator::launchAnimation(const Vector3 coord) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setStatus(true);
}

void Animator::launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    launchAnimation(Vector3(x, y, z));
}

void Animator::stopAnimation(const Vector3 coord) {
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setStatus(false);
}

void Animator::stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    stopAnimation(Vector3(x, y, z));
}

void Animator::apply() {
    for(int x(0); x<m_mapData.getSize().x; x++)
        for(int y(0); y<m_mapData.getSize().x; y++)
            for(int z(0); z<m_mapData.getSize().y; z++)
    {
        if(m_mapData.getTempConf().at(x, y, z)!=m_mapData.getInvisibleTile() &&
           m_tileAnimationsData.at(x, y, z).getLength()>1 &&
           isVisible(toIsometricPosition(Vector3(x, y, z), m_mapData), m_mapData.getTileSize(), m_screenInfos))
        {
            m_mapTilegroup.setTileTilesetX(Vector3(x, y, z), Vector2(m_tileAnimationsData.at(x, y, z).getX(),
                                                                     m_mapData.getTempConf().at(x, y, z)));

            if(m_shadowsStates.isOn())
                m_shader.updateTileFromAnim(Vector3(x, y, z), m_tileAnimationsData.at(x, y, z).getX());
        }
    }
}

unsigned int Animator::getSpeed() const {
    return m_speed;
}

void Animator::updateTileAt(const Vector3 coord) {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==m_mapData.getTempConf().at(coord.x, coord.y, coord.z))
        {
            if(m_animations[i].z==0)
                m_tileAnimationsData.at(coord.x, coord.y, coord.z).setKind(Global);

            if(m_animations[i].z==1)
                m_tileAnimationsData.at(coord.x, coord.y, coord.z).setKind(Single);

            m_tileAnimationsData.at(coord.x, coord.y, coord.z).setLength(m_animations[i].y);
            m_tileAnimationsData.at(coord.x, coord.y, coord.z).setDirection(Right);

            return;
        }
    }

    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setLength(1);
    m_tileAnimationsData.at(coord.x, coord.y, coord.z).setDirection(Right);
}

unsigned int Animator::getFrameAt(const Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getX();
}

unsigned int Animator::getFrameAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getFrameAt(Vector3(x, y, z));
}

bool Animator::getStatusAt(const Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getStatus();
}

bool Animator::getStatusAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getStatusAt(Vector3(x, y, z));
}

AnimKind Animator::getKindAt(const Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getKind();
}

AnimKind Animator::getKindAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getKindAt(Vector3(x, y, z));
}

AnimDirection Animator::getDirectionAt(const Vector3 coord) {
    return m_tileAnimationsData.at(coord.x, coord.y, coord.z).getDirection();
}

AnimDirection Animator::getDirectionAt(const unsigned int x, const unsigned int y, const unsigned int z) {
    return getDirectionAt(Vector3(x, y, z));
}

unsigned int Animator::getAnimLengthOfTile(const unsigned int tile) const {
    assert(tileIsAnimated(tile));

    for(std::size_t i(0); i<m_animations.size(); i++)
        if(m_animations[i].x==tile)
            return m_animations[i].y;
}

AnimKind Animator::getAnimKindOfTile(const unsigned int tile) const {
    assert(tileIsAnimated(tile));

    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
        {
            if(m_animations[i].z==0)
                return Global;
            else
                return Single;
        }
    }
}

bool Animator::tileIsAnimated(const unsigned int tile) const {
    for(std::size_t i(0); i<m_animations.size(); i++)
    {
        if(m_animations[i].x==tile)
            return true;
    }

    return false;
}
