
CFLAGS = -std=c++11 -Wall
CC = g++

tests: test.o coord.o animal.o populationt.o coord.o animal.o population.o grille.o jeu.o
	tests: test.o coord.o animal.o populationt.o coord.o animal.o population.o grille.o jeu.o
testCoord: test_coord.o coord.o
	$(CC) $(CFLAGS) -o testCoord test_coord.o coord.o
test_coord.o: test_coord.cpp
	$(CC) $(CFLAGS) -c test_coord.cpp
coord.o: coord.cpp
	$(CC) $(CFLAGS) -c coord.cpp
clean:
	rm -f core *.o


