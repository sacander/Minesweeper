#include "Entity.h"
// #include "Minesweeper.h"
#include <iostream>

// Constructor sets texture and prints error if not found
Entity::Entity(std::string textureFilepath, Minesweeper &game) : game(game) {
    if (!texture.loadFromFile(textureFilepath)) {
        std::cout << "Texture not found" << std::endl;
    }
    sprite.setTexture(texture);
}

// No memory cleaning neccessary
Entity::~Entity() {}

void Entity::onClickEvent(sf::RenderWindow *window, sf::Event &event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    // Convert mouse position to window coordinates
    sf::Vector2f mouseCoords = window->mapPixelToCoords(mousePos);
    // Calls left/right click if mouse is over the entity
    if (sprite.getGlobalBounds().contains(mouseCoords)) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            onLeftClick();
        }
        if (event.mouseButton.button == sf::Mouse::Right) {
            onRightClick();
        }
    }
}

// Draws sprite to the game window
void Entity::draw(sf::RenderWindow *window) {
    window->draw(sprite);
}