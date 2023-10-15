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
    sf::Font textFont; // font 
    public:
        void startTimer();
        void stopTimer();
        void resetTimer();
        void onLeftClick();
        void onRightClick();
        void draw(sf::RenderWindow *window);
        Timer(Vector2f pos, Minesweeper &game);
        ~Timer();
        std::time_t getGameTime();
        //getters and setters for testing purposes 
        bool getStarted(); 
        void setInitialTime(std::time_t _initialTime);
        //sf::Text getDisplay(); 
};

#endif