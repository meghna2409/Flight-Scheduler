EXENAME = final
OBJS = main.o PNG.o HSLAPixel.o lodepng.o parse.o flights.o dijkstra.o

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

main.o: classes/main.cpp classes/flights.cpp classes/parse.cpp classes/dijkstra.cpp
	$(CXX) $(CXXFLAGS) classes/main.cpp

dijkstra.o: classes/dijkstra.cpp
	$(CXX) $(CXXFLAGS) classes/dijkstra.cpp

flights.o: classes/flights.cpp
	$(CXX) $(CXXFLAGS) classes/flights.cpp

parse.o: classes/parse.cpp
	$(CXX) $(CXXFLAGS) classes/parse.cpp

PNG.o : classes/cs225/PNG.cpp classes/cs225/PNG.h classes/cs225/HSLAPixel.h classes/cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) classes/cs225/PNG.cpp

HSLAPixel.o : classes/cs225/HSLAPixel.cpp classes/cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) classes/cs225/HSLAPixel.cpp

lodepng.o : classes/cs225/lodepng/lodepng.cpp classes/cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) classes/cs225/lodepng/lodepng.cpp



tests: output_msg dijkstra.o PNG.o HSLAPixel.o lodepng.o classes/catch/catchmain.cpp classes/tests/tests.cpp classes/flights.cpp classes/parse.cpp
	$(LD) dijkstra.o PNG.o HSLAPixel.o lodepng.o classes/catch/catchmain.cpp classes/tests/tests.cpp classes/flights.cpp classes/parse.cpp $(LDFLAGS) -o tests

clean:
	-rm -f *.o $(EXENAME) tests