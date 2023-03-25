CC = g++
CPPFLAGS = -std=c++17 -g -Wall

main: main.o concept.o introductory.o intermediate.o advanced.o node.o client.o

main.o: main.h concept.h introductory.h intermediate.h advanced.h node.h client.h

client.o: concept.h introductory.h intermediate.h advanced.h node.h client.h

node.o: node.h concept.h introductory.h intermediate.h advanced.h

concept.o: concept.h

introductory.o: concept.h introductory.h

intermediate.o: concept.h intermediate.h

advanced.o: concept.h advanced.h

.PHONY: clean
clean:
	$(info -- cleaning the directory --)
	rm -f *.o main a.out
