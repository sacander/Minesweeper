#include "Timer.h"

void Timer::startTimer() {
    started = true;
}

void Timer::resetTimer() {
    timer = time(0); 
    display.setString("000");
}

void Timer::stopTimer() {
    started = false;
}

void Timer::onLeftClick() {}

void Timer::onRightClick() {}

Timer::Timer(Minesweeper &game)
: Entity("./textures/mine.png", Vector2f(400,40), game) {}

Timer::~Timer() {}

void Timer::draw(sf::RenderWindow *window) {
  Entity::draw(window);
  if (started == true) {
    display.setString(std::to_string(time(0) - timer));
  }
}
