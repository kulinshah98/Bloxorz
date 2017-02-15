CC=g++
all: mygame
FLAGS= -lGL -lglfw -ldl
OPTS=-I"irrKlang-64bit-1.5.0/include" -L"/usr/lib" irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so -pthread
mygame: main.o controls.o glad.o not_useful.o variables.o tiles.o block.o
	$(CC) -o mygame main.o controls.o glad.o not_useful.o variables.o tiles.o block.o $(FLAGS) $(OPTS)

not_useful.o: not_useful.h not_useful.cpp
	$(CC) -c not_useful.cpp $(FLAGS)

main.o: main.cpp main.h
	$(CC) -c main.cpp $(FLAGS) $(OPTS)

controls.o: controls.cpp controls.h
	$(CC) -c controls.cpp $(FLAGS)

tiles.o: tiles.cpp tiles.h
	$(CC) -c tiles.cpp $(FLAGS)

block.o: block.cpp block.h
	$(CC) -c block.cpp $(FLAGS)

glad.o: glad.c
	gcc -c glad.c $(FLAGS)

variables.o: variables.cpp
	$(CC) -c variables.cpp $(FLAGS)

clean:
	rm *.o
