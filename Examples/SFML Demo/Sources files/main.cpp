#include <iostream>
#include <SFML/Graphics.hpp>

#include "RunEnvironment.h"
#include "Map.h"

int main()
{
    RunEnvironment environment;
    environment.setWindowResolution(800, 600);

    Map carte(environment);

    carte.addLayerFile("layer1.map");
    carte.addLayerFile("layer2.map");
    carte.addLayerFile("layer3.map");
    carte.addLayerFile("layer4.map");

    carte.setTileset("texture.png");

    carte.setTileSize(Vector2(64, 72));
    carte.setTileBaseHeight(32);

    carte.setPosition(300, 100);

    carte.init();

    carte.shadows().setTileset("shadowsTex.png");
    carte.shadows().init();
    carte.shadows().setOpacity(130);
    carte.shadows().setOn(true);

    carte.setInvisibleTile(0);

    sf::RenderWindow window(sf::VideoMode(800, 600), "[SFML] FisoEngine entities + shadows demo");
    window.setFramerateLimit(60);

    carte.entities().createEntity();
    carte.entities().setImagePathOf(0, "entity.png");
    carte.entities().setDimensionsOf(0, Vector2(21, 44));
    carte.entities().setBaseCoordOf(0, Vector2(10, 43));
    carte.entities().setLayerOf(0, 1);
    carte.entities().updatePixelPositionOf(0, Vector2(315, 180));
    carte.entities().setDrawStateOf(0, true);

    carte.entities().createEntity();
    carte.entities().setImagePathOf(1, "entity.png");
    carte.entities().setDimensionsOf(1, Vector2(21, 44));
    carte.entities().setBaseCoordOf(1, Vector2(10, 43));
    carte.entities().setLayerOf(1, 1);
    carte.entities().updatePixelPositionOf(1, Vector2(260, 179));
    carte.entities().setDrawStateOf(1, true);

    carte.entities().getSpriteOf(1).setColor(sf::Color(255, 0, 0, 128));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    carte.entities().move(0, Vector2(-2, -1));

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    carte.entities().move(0, Vector2(2, 1));

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    carte.entities().move(0, Vector2(-2, 1));

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    carte.entities().move(0, Vector2(2, -1));

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    carte.entities().move(1, Vector2(-2, -1));

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    carte.entities().move(1, Vector2(2, 1));

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    carte.entities().move(1, Vector2(-2, 1));

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    carte.entities().move(1, Vector2(2, -1));
        }

        window.clear(sf::Color(255, 128, 255, 255));
        window.draw(carte);
        window.display();
    }

    return 0;
}
