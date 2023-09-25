#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
    protected:
        Texture texture;
        Sprite sprite;
        virtual void onLeftClick() = 0;
        virtual void onRightClick() = 0;

    public:
        Entity(std::string textureFilepath);
        ~Entity();
        void onClickEvent(RenderWindow *window, Event &event);
        void draw(RenderWindow *window);
};

#endif