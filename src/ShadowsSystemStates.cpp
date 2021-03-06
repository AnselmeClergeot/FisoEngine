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

#include "ShadowsSystemStates.hpp"



fe::ShadowsSystemStates::ShadowsSystemStates() : m_status(fe::Status::Off),
                                                 m_initialized(false)
{ }

void fe::ShadowsSystemStates::setStatus(const fe::Status status) {
    if(m_initialized)
        m_status = status;
}

void fe::ShadowsSystemStates::setInitialized() {
    m_initialized = true;
}

fe::Status fe::ShadowsSystemStates::getStatus() const {
    return m_status;
}

bool fe::ShadowsSystemStates::isInitialized() const {
    return m_initialized;
}
