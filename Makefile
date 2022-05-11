CFLAGS = -std=c++11 -Wall -pedantic
CC = g++

test: test.o jeu.o grille.o population.o animal.o coord.o ensemble.o constantes.hpp
	$(CC) $(CFLAGS) -o test test.o jeu.o grille.o population.o animal.o coord.o ensemble.o
test.o: test.cpp jeu.hpp grille.hpp population.hpp animal.hpp coord.hpp ensemble.hpp constantes.hpp
	$(CC) $(CFLAGS) -c test.cpp
jeu.o: jeu.cpp grille.hpp population.hpp animal.hpp coord.hpp ensemble.hpp constantes.hpp
	$(CC) $(CFLAGS) -c jeu.cpp
grille.o: grille.cpp population.hpp animal.hpp coord.hpp ensemble.hpp constantes.hpp
	$(CC) $(CFLAGS) -c grille.cpp
population.o: population.cpp animal.hpp coord.hpp ensemble.hpp constantes.hpp
	$(CC) $(CFLAGS) -c population.cpp
animal.o: animal.cpp coord.hpp ensemble.hpp constantes.hpp
	$(CC) $(CFLAGS) -c animal.cpp
coord.o: coord.cpp ensemble.hpp constantes.hpp
	$(CC) $(CFLAGS) -c coord.cpp
ensemble.o: ensemble.cpp constantes.hpp
	$(CC) $(CFLAGS) -c ensemble.cpp

clean:
	rm -f core *.o

# tests: test.o coord.o animal.o populationt.o coord.o animal.o population.o grille.o jeu.o\
	tests: test.o coord.o animal.o populationt.o coord.o animal.o population.o grille.o jeu.o
