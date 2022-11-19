CC = g++
CFLAGS = -g -w -Wall

main: main.o graph.o airport.o
	$(CC) $(CFLAGS) -o main main.o graph.o airport.o

graph.o: src/graph.cpp
	$(CC) $(CFLAGS) -c src/graph.cpp

airport.o: src/airport.cpp
	$(CC) $(CFLAGS) -c src/airport.cpp

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

clean:
	rm -f core *.o main