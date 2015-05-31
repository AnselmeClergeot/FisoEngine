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

/**
 * \file Entity.hpp
 * \brief Definition of Entity class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Entity.hpp defines the Entity class
 *
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Camera.hpp"
#include "MapData.hpp"
#include "Status.hpp"

namespace fe {
/**
 * \class Entity
 * \brief Class that contains all entity data
 *
 * Entity class is the class manipulated by the user to interact with this same entity.
 * Entity class contains all entity data from position, size, to the image of this entity...
 */
class Entity
{
    friend class EntitiesInterposing;
    public:

        /**
        * \fn Entity(fe::MapData &mapData, fe::Camera *&camera)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful data
        * \param camera Reference to the map camera
        */
        Entity(fe::MapData &mapData, fe::Camera *&camera);

        /**
        * \fn void setDimensions(const fe::Vector2 dim)
        * \brief To set the entity dimensions
        *
        * \param dim The entity dimensions in pixels
        * \return void
        */
        void setDimensions(const fe::Vector2 dim);

        /**
        * \fn void setDimensions(const unsigned int w, const unsigned int h)
        * \brief To set the entity dimensions
        *
        * \param w The entity width in pixel
        * \param h The entity height in pixel
        * \return void
        */
        void setDimensions(const unsigned int w, const unsigned int h);

        /**
        * \fn void setBaseCoord(const fe::Vector2 coord)
        * \brief To set the base coordinate of the entity
        *
        * \param coord The entity base coordinates relative to the top-left entity corner
        * \return void
        */
        void setBaseCoord(const fe::Vector2 coord);

        /**
        * \fn void setBaseCoord(const unsigned int x, const unsigned int y)
        * \brief To set the base coordinate of the entitym_container.entityAt(i).getTilePosition().x==coord.x
        *
        * \param x The entity base x coordinate relative to the left entity border
        * \param y The entity base y coordinate relative to the top entity border
        * \return void
        */
        void setBaseCoord(const unsigned int x, const unsigned int y);

        /**
        * \fn void move(const fe::Vector2 rate)
        * \brief To move the entity relatively from its position
        *
        * \param rate The move rate in pixels
        * \return void
        */
        void move(const fe::Vector2 rate);

        /**
        * \fn void move(const unsigned int rx, const unsigned int ry)
        * \brief To move the entity relatively from its position
        *
        * \param rx The move x rate in pixel
        * \param ry The move y rate in pixel
        * \return void
        */
        void move(const unsigned int rx, const unsigned int ry);

        /**
        * \fn void setImagePath(const std::string path)
        * \brief To set the entity image path
        *
        * \param path The image path
        * \return void
        */
        void setImagePath(const std::string path);

        /**
        * \fn void setDrawStatus(const fe::Status status)
        * \brief To set the draw state of the entity (if it have to be drawn or not)
        *
        * \param status The draw status
        * \return void
        */
        void setDrawStatus(const fe::Status status);

        /**
        * \fn void setLayer(const unsigned int layer)
        * \brief To set the layer on which the entity is laying
        *
        * \param layer The layer number (counting from bottom)
        * \return void
        */
        void setLayer(const unsigned int layer);

        /**
        * \fn fe::Vector3 getTilePosition() const
        * \brief To get the entity tile position
        *
        * \return The entity position in tile coordinates relative to the map, into a Vector3
        */
        fe::Vector3 getTilePosition() const;

        /**
        * \fn fe::Vector2 getBaseCoord() const
        * \brief To get the entity base coordinates
        *
        * \return The entity base coordinates in a Vector2
        */
        fe::Vector2 getBaseCoord() const;

        /**
        * \fn fe::Vector2 getDimensions() const
        * \brief To get the entity dimensions
        *
        * \return The entity dimensions in pixels in a Vector2
        */
        fe::Vector2 getDimensions() const;

        /**
        * \fn fe::Vector2 getPosition() const
        * \brief To get the entity position
        *
        * \return The entity position in a Vector2
        */
        fe::Vector2 getPosition() const;

        /**
        * \fn sf::Sprite &getSprite()
        * \brief To get a reference to the entity sprite (image) [SPECIFIC TO SFML]
        *
        * \return A reference to the entity sprite
        */
        sf::Sprite &getSprite();

        /**
        * \fn fe::Status getDrawStatus() const
        * \brief To get the draw status of the entity
        *
        * \return The entity draw status
        */
        fe::Status getDrawStatus() const;

        /**
        * \fn void setPosition(const fe::Vector2 pos)
        * \brief To set the position of the entity
        *
        * \param pos The position in pixels
        * \return void
        */
        void setPosition(const fe::Vector2 pos);

        /**
        * \fn void setPosition(const unsigned int x, const unsigned int y)
        * \brief To set the position of the entity
        *
        * \param x The x position in pixel
        * \param y The y position in pixel
        * \return void
        */
        void setPosition(const unsigned int x, const unsigned int y);

        /**
        * \fn void calculateTilePosition()
        * \brief To update, calculate the entity tile position from its pixels position
        *
        * \return void
        */
        void calculateTilePosition();

    private:

        /**
        * \fn void draw(sf::RenderTarget& target) const
        * \brief To draw the entity
        *
        * \param target The target to draw the entity on [SPECIFIC TO SFML]
        * \return void
        */
        void draw(sf::RenderTarget& target) const;

        fe::Vector3 m_tilePosition; /* !< The entity tile position*/

        fe::Vector2 m_pixelPosition; /* !< The entity pixels position*/

        fe::Vector2 m_dimensions; /* !< The entity dimensions*/

        fe::Vector2 m_baseCoord; /* !< The entity base coordinates*/

        sf::Texture m_texture; /* !< The entity texture [SPECIFIC TO SFML]*/

        sf::Sprite m_sprite; /* !< The entity sprite [SPECIFIC TO SFML]*/

        fe::Status m_drawStatus; /* !< The entity draw state*/

        fe::MapData& m_mapData; /* !< The pointer to the MapData to get useful data*/

        fe::Camera*& m_camera; /* !< The pointer to the map camera */
};
}

#endif // ENTITY_HPP
