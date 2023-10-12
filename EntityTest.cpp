// Tests general behaviour of the Entity class.
// All functions of Entity must be manually tested.
// Creates game window for this purpose with a test entity.

#include "Entity.h"
#include "Minesweeper.h"
#include <iostream>

// Makes class non-abstract
class ConcreteEntity: public Entity {
    private:
        void onLeftClick();
        void onRightClick();
    public:
        ConcreteEntity(std::string textureFilepath, sf::Vector2f pos, Minesweeper &game);
};

// Implements test behaviour for left and right click methods
void ConcreteEntity::onLeftClick() {std::cout << "Left click" << std::endl;}
void ConcreteEntity::onRightClick() {std::cout << "Right click" << std::endl;}

ConcreteEntity::ConcreteEntity(std::string textureFilepath, sf::Vector2f pos, Minesweeper &game)
: Entity(textureFilepath, pos, game) {}

int main() {
    // Creates test game instance and window
    Minesweeper game(500, "Entity Test");
    sf::RenderWindow window(sf::VideoMode(500, 500), "Entity Test");
    ConcreteEntity testEntity1("textures/tile.png", sf::Vector2f(200, 150), game);
    // Tests that error is logged if filepath does not exist
    ConcreteEntity testEntity2("testfilepath", sf::Vector2f(400, 150), game);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                // Tests click events
                // Should try left/right clicking around object to ensure correct click is logged only when over entity
                testEntity1.onClickEvent(&window, event);
                testEntity2.onClickEvent(&window, event);
            }
        }

        window.clear();
        // Tests draw function
        testEntity1.draw(&window);
        testEntity2.draw(&window);
        window.display();
    }

    return 0;
}