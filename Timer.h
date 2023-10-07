#ifndef TIMER_H
#define TIMER_H

#include "Entity.h"
#include <ctime>>

using namespace sf;

class Timer: Entity {
    private:
    std::time_t Time;
    //display text;
    public:
        void startTimer();
        void stopTimer();
        void resetTimer();
        void onLeftClick();
        void onRightClick();
};

#endif