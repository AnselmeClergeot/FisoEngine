/* This demo shows map initialization, shadows setting and map entity adding. Feel free to modify.*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "RunEnvironment.h"
#include "Map.h"

int main()
{
    RunEnvironment environment;
    environment.setWindowResolution(800, 600);
	
    Map myMap(environment);

    myMap.addLayerFile("layer1.map");
    myMap.addLayerFile("layer2.map");
    myMap.addLayerFile("layer3.map");
    myMap.addLayerFile("layer4.map");

    myMap.setTileset("texture.png");

    myMap.setTileSize(Vector2(64, 72));
    myMap.setTileBaseHeight(32);

    myMap.setPosition(300, 100);

    myMap.init();

    myMap.shadows().setTileset("shadowsTex.png");
    myMap.shadows().init();
    myMap.shadows().setOpacity(130);
    myMap.shadows().setOn(true);

    myMap.setInvisibleTile(0);

    myMap.entities().createEntity();
    myMap.entities().entityAt(0).setImagePath("entity.png");
    myMap.entities().entityAt(0).setLayer(1);
    myMap.entities().entityAt(0).setDimensions(21, 44);
    myMap.entities().entityAt(0).setBaseCoord(10, 44);
    myMap.entities().entityAt(0).updatePixelPosition(180, 140);
    myMap.entities().entityAt(0).setDrawState(true);

    sf::RenderWindow window(sf::VideoMode(800, 600), "[SFML] FisoEngine entities + shadows demo");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 128, 255, 255));
        window.draw(myMap);
        window.display();
    }
    return 0;
}
