#ifndef ENTITY_H
#define ENTITY_H

class Minesweeper; // "Minesweeper.h" not included to avoid circular dependencies between Entity and Minesweeper
#include <SFML/Graphics.hpp>

// Abstract entity class
class Entity {
    private:
        // Pure virtual functions to define behaviour on left/right click
        virtual void onLeftClick() = 0;
        virtual void onRightClick() = 0;

    protected:
        // Texture of entity used to create its sprite
        sf::Texture texture;
        sf::Sprite sprite;
        // Reference to global game object
        Minesweeper &game;

    public:
        Entity(std::string textureFilepath, sf::Vector2f pos, Minesweeper &game);
        ~Entity();
        // Called for every entity whenever a click occurs
        void onClickEvent(sf::RenderWindow *window, sf::Event &event);
        // Draws entity to the window
        virtual void draw(sf::RenderWindow *window);
};

#endif