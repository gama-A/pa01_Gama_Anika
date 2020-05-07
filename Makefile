# Makefile
CXX_FLAG = --std=c++11 -g

game: main.o cards.o
	g++ $(CXX_FLAG) -o game main.o cards.o

testcards: cards.o testcards.o
	g++ $(CXX_FLAG) -o testcards cards.o testcards.o

cards.o: cards.cpp cards.h
	g++ $(CXX_FLAG) cards.cpp -c

main.o: main.cpp cards.h
	g++ $(CXX_FLAG) main.cpp -c

testcards.o: testcards.cpp testcards.h cards.h
	g++ $(CXX_FLAG) testcards.cpp -c

clean:
	rm -f game testcards *.o
