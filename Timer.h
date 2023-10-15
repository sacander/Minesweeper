#ifndef TIMER_H
#define TIMER_H

#include "Entity.h"
#include <ctime>

using namespace sf;

class Timer : public Entity {
    private:
        std::time_t initialTime; // initial time at which timer and game begins
        sf::Text display;        // text to be displayed on the timer
        bool started = false;    // reflects whether the timer and game has started
        sf::Font textFont;       // font
    public:
        void startTimer();                   // starts timer, sets started to true
        void stopTimer();                    // stops timer, sets started to false
        void resetTimer();                   // resets timer, sets display to "000" and resets initialTime to now
        void onLeftClick();                  // called on left click, does nothing
        void onRightClick();                 // called on right click, does nothing
        void draw(sf::RenderWindow *window); // draws and updates the value displayed on the timer
        Timer(Vector2f pos, Minesweeper &game);
        ~Timer();
        std::time_t getGameTime();                     // returns game time
        bool getStarted();                             // returns started
        void setInitialTime(std::time_t _initialTime); // sets the initial time
};

#endif