all: Minesweeper.o Entity.o Tile.o Mine.o Number.o
	g++ Minesweeper.o Entity.o Tile.o Mine.o Number.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o game.out
	./game.out

compile:
	g++ Minesweeper.o Entity.o Tile.o Mine.o Number.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o game.out

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

clean:
	rm -f *.out
	rm -f *.o