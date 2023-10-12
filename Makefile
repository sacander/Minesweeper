all:
	make compile
	make run

# sudo spctl --master-disable and sudo spctl --master-enable may be necessary
mac:
	make compile_mac
	make run

compile: main.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o
	g++ main.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o game.out

compile_mac: main.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o
	g++ main.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o game.out -Wl,-rpath,/usr/local/lib

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

NewGameButton.o: NewGameButton.cpp
	g++ -c NewGameButton.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o NewGameButton.o

SaveButton.o: SaveButton.cpp
	g++ -c SaveButton.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o SaveButton.o

LoadButton.o: LoadButton.cpp
	g++ -c LoadButton.cpp -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o LoadButton.o

EntityTest: EntityTest.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o
	g++ EntityTest.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o test.out -Wl,-rpath,/usr/local/lib
	./test.out

EntityTestMac: EntityTest.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o
	g++ EntityTest.cpp Minesweeper.o Entity.o Tile.o Mine.o Number.o Board.o Timer.o NewGameButton.o SaveButton.o LoadButton.o -lsfml-graphics -lsfml-window -lsfml-system -Wall -std=c++17 -o test.out
	./test.out

clean:
	rm -f *.out
	rm -f *.o