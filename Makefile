all:
	make compile
	make run

# sudo spctl --master-disable and sudo spctl --master-enable may be necessary
mac: Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o
	make compile_mac
	make run

compile: Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o
	g++ Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o game.out

compile_mac: Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o
	g++ Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o game.out -Wl,-rpath,/usr/local/lib

run:
	./game.out

Minesweeper.o: Minesweeper.cpp
	g++ -c Minesweeper.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o Minesweeper.o

Entity.o: Entity.cpp
	g++ -c Entity.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o Entity.o

Tile.o: Tile.cpp
	g++ -c Tile.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o Tile.o

Mine.o: Mine.cpp
	g++ -c Mine.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o Mine.o

Number.o: Number.cpp
	g++ -c Number.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o Number.o

Board.o: Board.cpp
	g++ -c Board.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o Board.o

Timer.o: Timer.cpp
	g++ -c Timer.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o Timer.o

clean:
	rm -f *.out
	rm -f *.o