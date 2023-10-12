#ifndef TIMER_H
#define TIMER_H

#include "Entity.h"
#include <ctime>

using namespace sf;

class Timer: public Entity {
    private:
    std::time_t initialTime; //initial time at which timer and game begins 
    sf::Text display; //text to be displayed on the timer 
    bool started = false; //reflects whether the timer and game has started 
    public:
        void startTimer();
        void stopTimer();
        void resetTimer();
        void onLeftClick();
        void onRightClick();
        void draw(sf::RenderWindow *window);
        Timer(Vector2f pos, Minesweeper &game);
        ~Timer();
};

#endif