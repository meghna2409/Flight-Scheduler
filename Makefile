CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/

main: bin/main
tests: bin/tests

bin/main: main.cpp src/Airport.cpp src/Dijkstra.cpp src/Graph.cpp src/Route.cpp 
	${CXX} ${CXX_FLAGS} main.cpp src/Airport.cpp src/Dijkstra.cpp src/Graph.cpp src/Route.cpp -o bin/main

bin/tests: tests/tests.cpp src/Airport.cpp src/Dijkstra.cpp src/Graph.cpp src/Route.cpp
	${CXX} ${CXX_FLAGS} tests/tests.cpp src/Airport.cpp src/Dijkstra.cpp src/Graph.cpp src/Route.cpp -o bin/tests

.DEFAULT_GOAL := main
.PHONY: clean main tests


clean:
	rm -fr bin/*