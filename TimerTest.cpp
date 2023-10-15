// Tests the behaviour of the timer class

#include <ctime>
#include <iostream>

#include "Minesweeper.h"
#include "Timer.h"

class TimerTest {
    public:
        void tests() {
            testStartTimer(); // tests if timer starts
            testResetTimer(); // tests if timer is reset successfully
            testStopTimer();  // tests if timer stops
            testTimerMax();   // tests timer stops at 999
            testDraw();       // tests timer display works in general
        }

    private:
        void testStartTimer() {
            std::cout << "\ntestStartTimer():" << std::endl;
            // creating game so functions can be run
            Minesweeper game(100, "Timer test");

            // create timer object
            Timer test1(sf::Vector2f(0, 0), game);
            bool beforeTest1 = test1.getStarted();
            std::cout << "Timer state before startTimer(): " << beforeTest1
                      << std::endl;

            // start timer
            test1.startTimer();

            bool afterTest1 = test1.getStarted();
            std::cout << "Timer state after startTimer(): " << afterTest1 << std::endl;

            // see if timer successfully started
            if (afterTest1 && afterTest1 != beforeTest1) {
                std::cout << "Timer started successfully" << std::endl;
            }
        }

        void testResetTimer() {
            std::cout << "\ntestResetTimer():" << std::endl;
            // creating game so functions can be run
            Minesweeper game(100, "Timer test");

            // create timer object
            Timer test1(sf::Vector2f(0, 0), game);
            test1.setInitialTime(time(0) - 10);
            time_t setTest1 = test1.getGameTime();
            std::cout << "Time elapsed set to " << setTest1 << std::endl;

            // reset timer
            test1.resetTimer();

            time_t resetTest1 = test1.getGameTime();
            std::cout << "Time elapsed after reset: " << resetTest1 << std::endl;

            // see if timer successfully started
            if (resetTest1 == 0) {
                std::cout << "Timer reset successfully" << std::endl;
            }
        }

        void testStopTimer() {
            std::cout << "\ntestStopTimer():" << std::endl;
            // creating game so functions can be run
            Minesweeper game(100, "Timer test");

            // create timer object
            Timer test1(sf::Vector2f(0, 0), game);
            bool beforeTimerStart = test1.getStarted();
            std::cout << "Timer state before startTimer(): " << beforeTimerStart
                      << std::endl;

            // start timer
            test1.startTimer();

            bool afterTimerStart = test1.getStarted();
            std::cout << "Timer state after startTimer(): " << afterTimerStart
                      << std::endl;

            // stop timer
            test1.stopTimer();

            bool afterTest1 = test1.getStarted();
            std::cout << "Timer state after stopTimer(): " << afterTest1 << std::endl;

            // see if timer successfully started
            if (!afterTest1 && afterTest1 != afterTimerStart) {
                std::cout << "Timer stopped successfully" << std::endl;
            }
        }

        void testTimerMax() {
            std::cout << "\ntestTimerMax(): (Testing that timer will stop at maximum)"
                      << std::endl;
            // creating game so functions can be run
            Minesweeper game(100, "Timer test");
            sf::RenderWindow window(sf::VideoMode(0, 0), "Timer Test");

            // create timer object
            {
                Timer test1(sf::Vector2f(0, 0), game);
                test1.setInitialTime(time(0) - 995);
                time_t reference1 = time(0) - 995;

                std::cout << "Timer set to " << test1.getGameTime();
                std::cout << "\nWaiting for timer to pass 999" << std::endl;

                test1.startTimer();

                while (true) {
                    test1.draw(&window);

                    if (test1.getGameTime() > 999) {
                        std::cout << "Test 1 fail" << std::endl;
                        break;
                    } else if (test1.getGameTime() == 999 && (time(0) - reference1)) {
                        std::cout << "Test 1 pass" << std::endl;
                        break;
                    }
                }
            }

            {
                Timer test2(sf::Vector2f(0, 0), game);
                test2.setInitialTime(time(0) - 999);
                time_t reference2 = time(0) - 999;

                std::cout << "Timer set to " << test2.getGameTime();
                std::cout << "\nWaiting for timer to pass 999" << std::endl;

                test2.startTimer();

                while (true) {
                    test2.draw(&window);

                    if (test2.getGameTime() > 999) {
                        std::cout << "Test 2 fail" << std::endl;
                        break;
                    } else if (test2.getGameTime() == 999 && (time(0) - reference2)) {
                        std::cout << "Test 2 pass" << std::endl;
                        break;
                    }
                }
            }
        }

        void testDraw() {
            std::cout << "\ntestDraw(): Refer to game window to see if test works"
                      << std::endl;
            // creating game so functions can be run
            Minesweeper game(100, "Timer test");
            sf::RenderWindow window(sf::VideoMode(100, 100), "Timer Test");

            // create timer object
            Timer test1(sf::Vector2f(0, 0), game);

            test1.startTimer();

            while (window.isOpen()) {
                sf::Event event;

                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }

                window.clear();
                // Tests timer draw function
                test1.draw(&window);
                window.display();
            }
        }
};

int main() {
    TimerTest timerTest;
    timerTest.tests();
}