#ifndef TIMER_H
#define TIMER_H

#include "Entity.h"
#include <ctime>>

using namespace sf;

class Timer: Entity {
    private:
    std::time_t timer;
    sf::Text display; 
    bool started = false;
    public:
        void startTimer();
        void stopTimer();
        void resetTimer();
        void onLeftClick();
        void onRightClick();
        void draw(sf::RenderWindow *window);
        Timer(Minesweeper &game);
        ~Timer();
};

#endif