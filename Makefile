# Makefile
CXX_FLAG = --std=c++11 -g

game: main.o cards.o
	g++ -c $(CXX_FLAG) -o game main.o cards.o

testcards: cards.o testcards.o
	g++ -c $(CXX_FLAG) -o testcards cards.o testcards.o

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

testcards.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

clean:
	rm -f game testcards *.o
