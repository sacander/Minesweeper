#include "Timer.h"

//function to start time, sets started to true to indicate timer has started
void Timer::startTimer() {
    started = true;
}

//function to reset timer, sets the display to 000 seconds, sets the initial time to 0
void Timer::resetTimer() {
    initialTime = time(0); 
    display.setString("000");
}

//function to stop timer, sets started to false
void Timer::stopTimer() {
    started = false;
}

//redefine onLeftClick
void Timer::onLeftClick() {}

//redefine onRightClick
void Timer::onRightClick() {}

//sets position and the texture for the timer 
Timer::Timer(Vector2f pos, Minesweeper &game)
: Entity("./textures/timerbase.png", pos, game) {
    display.setString("000");
    display.setFillColor(Color::Black);
    sf::Font textFont; 
    textFont.loadFromFile("timerFont.tff");
    display.setFont(textFont);
    display.setCharacterSize(30);
}

Timer::~Timer() {}

void Timer::draw(sf::RenderWindow *window) {
  Entity::draw(window);
  //if the timer has started, then the display will update everytime Timer is drawn to display the current game length in seconds
  if (started == true) {
    display.setString(std::to_string(time(0) - initialTime));
  }
}

std::time_t Timer::getGameTime() {
  return (time(0) - initialTime);
}