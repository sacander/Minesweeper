#include "Timer.h"

void Timer::startTimer() {
    // start counting up
    timer = time(0); 
    display.setString(std::to_string(timer));

    int lastsecond;
    // while game is active run loop where every second the display 
    //is updated to display the new time
}

void Timer::resetTimer() {
    display.setString("000");
}

void Timer::stopTimer() {}
  //pause value 

void Timer::onLeftClick() {}

void Timer::onRightClick() {}

Timer::Timer(Minesweeper &game)
: Entity("./textures/mine.png", Vector2f(400,40), game) {}

Timer::~Timer() {}
