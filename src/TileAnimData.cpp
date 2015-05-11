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

#include "TileAnimData.h"

using namespace fe;

TileAnimData::TileAnimData() : m_kind(Global),
                               m_direction(Right),
                               m_x(0),
                               m_status(false),
                               m_waitStatus(false),
                               m_length(0)
{ }

void TileAnimData::setKind(const AnimKind kind) {
    m_kind = kind;

    if(m_kind==Single)
        m_waitStatus = false;
    if(m_kind==Global)
        m_waitStatus = true;

    resetX();
}

void TileAnimData::setDirection(const AnimDirection direction) {
    m_direction = direction;

    resetX();
}

void TileAnimData::setStatus(const bool status) {
    m_waitStatus = status;
    if(status==false)
        m_status = false;

    resetX();
}

void TileAnimData::setLength(const unsigned int length) {
    m_length = length;
}

AnimKind TileAnimData::getKind() const {
    return m_kind;
}

AnimDirection TileAnimData::getDirection() const {
    return m_direction;
}

unsigned int TileAnimData::getLength() const {
    return m_length;
}

unsigned int TileAnimData::getX() const {
    return m_x;
}

bool TileAnimData::getStatus() const {
    return m_status;
}

void TileAnimData::updateX() {
    if(m_status==true)
        if(m_length>1)
        {
            if(m_direction==Right)
            {
                if(m_x+1<m_length)
                    m_x++;
                else
                {
                    if(m_kind==Global)
                        resetX();
                    else if(m_kind==Single)
                        m_waitStatus = false;
                }

            }

            if(m_direction==Left)
            {
                if(m_x>0)
                    m_x--;
                else
                {
                    if(m_kind==Global)
                        resetX();
                    else if(m_kind==Single)
                        m_waitStatus = false;
                }

            }
        }

    m_status = m_waitStatus;
}

void TileAnimData::resetX() {
    if(m_direction==Left)
        m_x = m_length-1;

    if(m_direction==Right)
        m_x = 0;
}
