# The variable $@ represents the name of the target and $< represents the first prerequisite required to create the output file.

CXX=g++
CXXFLAGS=-g -std=c++14 -Wall
OBJS=obj/main.o
TARGET=run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS)

obj/main.o: main.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

clean:
	rm -f obj/*.o $(TARGET)
