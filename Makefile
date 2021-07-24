CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

SRC		:= src
INCLUDE	:= include
EXECUTABLE	:= tp02


all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@