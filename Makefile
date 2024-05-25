CC = g++
CXXFLAGS = -std=c++11 -Wall -I./sdl/include
LIBRARIES = -L./sdl/lib -lSDL2

all: game

game: src/main.o
	$(CC) src/main.o $(LIBRARIES) -o game

src/main.o: src/main.cpp
	$(CC) $(CXXFLAGS) -c src/main.cpp -o src/main.o

clean:
	rm -f game src/main.o
