EXENAME = final
OBJS = main.o PNG.o HSLAPixel.o lodepng.o parse.o flights.o dijkstra.o pagerank.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

.PHONY: all tests clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: src/main.cpp src/flights.cpp src/parse.cpp src/dijkstra.cpp src/pagerank.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp

dijkstra.o: src/dijkstra.cpp
	$(CXX) $(CXXFLAGS) src/dijkstra.cpp

flights.o: src/flights.cpp
	$(CXX) $(CXXFLAGS) src/flights.cpp

parse.o: src/parse.cpp
	$(CXX) $(CXXFLAGS) src/parse.cpp

pagerank.o: src/pagerank.cpp
	$(CXX) $(CXXFLAGS) src/pagerank.cpp

PNG.o : src/cs225/PNG.cpp src/cs225/PNG.h src/cs225/HSLAPixel.h src/cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) src/cs225/PNG.cpp

HSLAPixel.o : src/cs225/HSLAPixel.cpp src/cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) src/cs225/HSLAPixel.cpp

lodepng.o : src/cs225/lodepng/lodepng.cpp src/cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) src/cs225/lodepng/lodepng.cpp



tests: output_msg dijkstra.o PNG.o HSLAPixel.o lodepng.o src/catch/catchmain.cpp src/tests/tests.cpp src/flights.cpp src/parse.cpp src/pagerank.cpp
	$(LD) dijkstra.o PNG.o HSLAPixel.o lodepng.o src/catch/catchmain.cpp src/tests/tests.cpp src/flights.cpp src/parse.cpp src/pagerank.cpp $(LDFLAGS) -o tests

clean:
	-rm -f *.o $(EXENAME) tests