CXX = g++
CXXFLAGS = -std=c++11 -Wall
RM = rm -rf

OBJ = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

.PHONY: all
all: test_all
test_all : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJ) test_all
.PHONY: distclean
distclean: clean
