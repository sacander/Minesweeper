#include "Entity.h"
#include <iostream>

Entity::Entity(std::string textureFilepath) {
    if (!texture.loadFromFile(textureFilepath)) {
        std::cout << "Texture not found" << std::endl;
    }
    sprite.setTexture(texture);
}

Entity::~Entity() {}

void Entity::onClickEvent(RenderWindow *window, Event &event) {
    Vector2i mousePos = Mouse::getPosition(*window);
    Vector2f mouseCoords = window->mapPixelToCoords(mousePos);
    if (sprite.getGlobalBounds().contains(mouseCoords)) {
        if (event.mouseButton.button == Mouse::Left) {
            onLeftClick();
        }
        if (event.mouseButton.button == Mouse::Right) {
            onRightClick();
        }
    }

}

void Entity::draw(RenderWindow *window) {
    window->draw(sprite);
}