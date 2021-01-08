# The variable $@ represents the name of the target and $< represents the first prerequisite required to create the output file.

CXX=g++
CXXFLAGS=-g -std=c++14 -Wall
OBJS=obj/main.o obj/token.o obj/variable.o obj/util.o
TARGET=run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS)

obj/main.o: main.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

obj/token.o: token.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

obj/variable.o: variable.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

obj/util.o: util.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

clean:
	rm -f obj/*.o $(TARGET)
