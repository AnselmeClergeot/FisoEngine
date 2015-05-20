#ifndef TILEGROUPCOLORS_HPP
#define TILEGROUPCOLORS_HPP

#include "Color.hpp"
#include "MapData.hpp"
#include "TileGroupData.hpp"

namespace fe {

class TileGroupColors
{
    public:
        /**
        * \fn TileGroupColors(fe::MapData &mapData, fe::TileGroupData &tilegroupData)
        * \brief The default constructor
        *
        * \param mapData Reference to the MapData
        * \param tilegroupData Reference to the TileGroupData
        */
        TileGroupColors(fe::MapData &mapData, fe::TileGroupData &tilegroupData);

        /**
        * \fn fe::Matrix3d<fe::Color> &getColors()
        * \brief To get a reference to the tile opacities values
        *
        * \return The Matrix3d of tiles colors values
        */
        fe::Matrix3d<fe::Color> &getColors();

        /**
        * \fn void setTileColor(const fe::Vector3 coord, const fe::Color color)
        * \brief To set the color of a specific tile from 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \param color The color
        * \return void
        */
        void setTileColor(const fe::Vector3 coord, const fe::Color color);

         /**
        * \fn void setTileOpacity(const fe::Vector3 coord, const unsigned int opacity)
        * \brief To set the opacity of a specific tile from 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \param opacity The opacity value
        * \return void
        */
        void setTileOpacity(const fe::Vector3 coord, const unsigned int opacity);

        /**
        * \fn void setTypeColor(const unsigned int tile, const fe::Color color)
        * \brief To set the color of all the tiles of the same type
        *
        * \param tile The tile number
        * \param color The color
        * \return void
        */
        void setTypeColor(const unsigned int tile, const fe::Color color);

        /**
        * \fn void setGroupColor(const fe::Color color)
        * \brief To set the color of all the tiles of the TileGroup
        *
        * \param color The color
        * \return void
        */
        void setGroupColor(const fe::Color color);

        /**
        * \fn fe::Color getGroupColor() const
        * \brief To get the group color
        *
        * \return The color
        */
        fe::Color getGroupColor() const;

        /**
        * \fn void applyColorOfTile(const fe::Vector3 coord)
        * \brief To apply the opacity value of the Matrix3d on a tile
        *
        * \param coord The tile 3D coordinates
        * \return void
        */
        void applyColorOfTile(const fe::Vector3 coord);

        /**
        * \fn void checkForColor(const fe::Vector3 coord, const unsigned int tile)
        * \brief To eventually set the color of the tile which was set
        *
        * \param coord The tile 3D coordinates
        * \param tile The tile number
        * \return void
        */
        void checkForColor(const fe::Vector3 coord, const unsigned int tile);

        /**
        * \fn void reloadColors()
        * \brief To reload the colors from the types list
        *
        * \return void
        */
        void reloadColors();

        /**
        * \fn fe::Color getTileColor(const fe::Vector3 coord)
        * \brief To get the color of a specific tile at 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \return The color of the tile
        */
        fe::Color getTileColor(const fe::Vector3 coord);

        /**
        * \fn void resetColorOf(const fe::Vector3 coord)
        * \brief To reset the color of a specific tile at 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \return void
        */
        void resetColorOf(const fe::Vector3 coord);

        /**
        * \fn fe::Color getColorOfType(const unsigned int type) const
        * \brief To get the color of a specific tile type
        *
        * \param type The tile color
        * \return The color
        */
        fe::Color getColorOfType(const unsigned int type) const;

    private:

        fe::Matrix3d<fe::Color> m_tilesColors; /*!< The Matrix3d of tiles colors values*/

        std::vector<unsigned int> m_types; /*!< The tile types numbers for specific colors*/

        std::vector<fe::Color> m_typesColors; /*!< The tile colors corresponding to the specific numbers */

        fe::Color m_groupColor; /*!< The group color */

        fe::MapData &m_mapData; /*!< The reference to the MapData */

        fe::TileGroupData &m_tilegroupData; /*!< The reference to the TileGroupData */
};

}

#endif // TILEGROUPCOLORS_HPP
