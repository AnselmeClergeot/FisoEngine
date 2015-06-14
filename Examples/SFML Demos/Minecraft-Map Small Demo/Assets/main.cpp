//This file is a demo showing different features of FisoEngine.

#include <Camera.hpp> //Including the Camera header
#include <Map.hpp> //Including the Map header

using namespace fe; //Using the namespace fe to simplify main.cpp

int main()
{

    Camera cam(800, 600); //Declaring a Camera with a view of 800*600

    Map map(cam); //Declaring the Map using our Camera
    map.setTileset("Images/tileset.png"); //Setting the tileset image path
    map.setTileSize(134, 148); //Setting the tile size
    map.setTileBaseHeight(66); //Setting the tile base height
    map.addLayerFile("Layers/layer1.map"); //Adding the first layer of the Map
    map.addLayerFile("Layers/layer2.map"); //Adding the second layer of the Map
    map.addLayerFile("Layers/layer3.map"); //Adding the third layer of the Map
    map.addLayerFile("Layers/layer4.map"); //Adding the fourth layer of the Map
    map.addLayerFile("Layers/layer5.map"); //Adding the fifth layer of the Map
    map.addLayerFile("Layers/layer6.map"); //Adding the sixth layer of the Map
    map.create(); //And finally, creating our Map !
    map.setPosition(-150, -400); //Setting the position of the Map

    map.animator().setAnimation(2, 2); //Setting the water animation

    map.setInvisibleTile(0); //Setting the invisible tile number to prepare shadows system
    map.addTranslucentTile(2); //Adding the water tile to the list of translucent tiles for the shadows system
    map.shadows().setTileset("Images/shadowsTex.png"); //Setting the tileset of the shadows system
    map.shadows().setOpacity(200); //Setting the opacity value of the shadows
    map.shadows().init(); //Call calculation of map shadows
    map.shadows().setStatus(Status::On); //And finally, setting the shadows to On.

    sf::RenderWindow window(sf::VideoMode(800, 600), "FisoEngine Demo"); //Declaring a SFML window of size of 800*600

    //Setting up some basics sprites-------------------------
    sf::Texture bgTex;
    bgTex.loadFromFile("Images/background.png");
    sf::Sprite bgSprite;
    bgSprite.setTexture(bgTex);
    sf::Texture titleTex;
    titleTex.loadFromFile("Images/explanation.png");
    sf::Sprite titleSprite;
    titleSprite.setTexture(titleTex);
    //-------------------------------------------------------

    map.entities().createEntity(); //Adding an entity to the world (entities.at(0))
    map.entities().entityAt(0).setImagePath("Images/steve.png"); //Setting the image of the entity
    map.entities().entityAt(0).setBaseCoord(41, 173); //Setting the base coordinates of the entity
    map.entities().entityAt(0).setDimensions(82, 173); //Setting the dimensions of the entity
    map.entities().entityAt(0).setLayer(1); //Setting the active layer of the entity
    map.entities().entityAt(0).setDrawStatus(Status::On); //Setting the entity draw status to On
    map.entities().entityAt(0).setPosition(100, 400); //Setting the position of the entity

    Vector2 moveRate(0, 0); //Declaring a fe::Vector2 to move the entity each frame
    bool moving(false); //Moving or not moving the entity

    //SFML events loop---------------------------------------------------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Preparing entity movement with keys--------------------------
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    moving = true;
                    moveRate = Vector2(-2, -1);
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    moving = true;
                    moveRate = Vector2(2, 1);
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    moving = true;
                    moveRate = Vector2(2, -1);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    moving = true;
                    moveRate = Vector2(-2, 1);
                }
            }

            if (event.type == sf::Event::KeyReleased)
                moving = false;
            //--------------------------------------------------------------
        }

        if(moving==true)
            map.entities().entityAt(0).move(moveRate); //Moving the entity each frame if moving==true

        cam.setViewCenter(map.entities().entityAt(0).getPosition()); //Setting the camera looking at the character

        map.animator().next(); //Updating animation system, each frame

        window.clear();

        window.draw(bgSprite); //Drawing the background
        window.draw(map); //Drawing our Map !
        window.draw(titleSprite); //Drawing the explanation image

        window.display();
    }
    //-------------------------------------------------------------------------

    return 0;
}
