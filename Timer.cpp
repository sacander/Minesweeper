#include "Timer.h"

// function to start time, sets started to true to indicate timer has started
void Timer::startTimer() { started = true; }

// function to reset timer, sets the display to 000 seconds, sets the initial
// time to 0
void Timer::resetTimer() {
    initialTime = time(0);
    display.setString("000");
}

// function to stop timer, sets started to false
void Timer::stopTimer() { started = false; }

// redefine onLeftClick
void Timer::onLeftClick() {}

// redefine onRightClick
void Timer::onRightClick() {}

// sets position and the texture for the timer, also sets all details of the
// display
Timer::Timer(Vector2f pos, Minesweeper &game)
    : Entity("./textures/timerbase.png", pos, game) {
    initialTime = time(0);
    display.setString("000");
    display.setFillColor(Color::Black);
    display.setPosition(pos + Vector2f(18, 2));
    textFont.loadFromFile("./textures/timerFont.ttf");
    display.setFont(textFont);
    display.setCharacterSize(20);
}

// deconstructor
Timer::~Timer() {}

// draws the timer and constantly updates the timer display
void Timer::draw(sf::RenderWindow *window) {
    Entity::draw(window);
    std::string timeElapsed;
    // if the timer has started, then the display will update everytime Timer is
    // drawn to display the current game length in seconds
    if (started == true) {
        // timer stops at 999
        if ((time(0) - initialTime) <= 999) {
            // three digit display
            if ((time(0) - initialTime) < 10) {
                timeElapsed = "00" + std::to_string(time(0) - initialTime);
            } else if ((time(0) - initialTime) < 100) {
                timeElapsed = "0" + std::to_string(time(0) - initialTime);
            } else {
                timeElapsed = std::to_string(time(0) - initialTime);
            }
            display.setString(timeElapsed);
        }
    }
    // draw the display
    window->draw(display);
}

// returns the game time
std::time_t Timer::getGameTime() { return (time(0) - initialTime); }

// returns started
bool Timer::getStarted() { return started; }

// sets the initialTime
void Timer::setInitialTime(std::time_t _initialTime) {
    initialTime = _initialTime;
}
