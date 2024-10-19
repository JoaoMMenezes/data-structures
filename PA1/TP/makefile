CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11
SRC = src/mat.cpp src/matop.cpp
OBJ = obj/mat.o obj/matop.o
BIN = bin/matop

all: $(BIN)

$(BIN): $(OBJ)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./bin/matop -s -x 5 -y 5
	./bin/matop -m -x 5 -y 5
	./bin/matop -t -x 5 -y 5

clean:
	rm -rf bin obj
