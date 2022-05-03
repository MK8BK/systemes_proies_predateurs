CFLAGS = -std=c++11 -Wall
CC = g++

test: test.o coord.o
	$(CC) $(CFLAGS) -o test test.o coord.o
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
coord.o: coord.cpp
	$(CC) $(CFLAGS) -c coord.cpp
clean:
	rm -f core *.o

# tests: test.o coord.o animal.o populationt.o coord.o animal.o population.o grille.o jeu.o\
	tests: test.o coord.o animal.o populationt.o coord.o animal.o population.o grille.o jeu.o
