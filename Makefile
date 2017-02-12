CC=g++
all: mygame
FLAGS= -lGL -lglfw -ldl
mygame: main.o controls.o glad.o not_useful.o variables.o tiles.o
	$(CC) -o mygame main.o controls.o glad.o not_useful.o variables.o tiles.o $(FLAGS)

not_useful.o: not_useful.h not_useful.cpp
	$(CC) -c not_useful.cpp $(FLAGS)

main.o: main.cpp main.h
	$(CC) -c main.cpp $(FLAGS)

controls.o: controls.cpp controls.h
	$(CC) -c controls.cpp $(FLAGS)

tiles.o: tiles.cpp tiles.h
	$(CC) -c tiles.cpp $(FLAGS)

glad.o: glad.c
	gcc -c glad.c $(FLAGS)

variables.o: variables.cpp
	$(CC) -c variables.cpp $(FLAGS)

clean:
	rm *.o
