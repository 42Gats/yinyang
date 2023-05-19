##
## EPITECH PROJECT, 2023
## yinyang
## File description:
## Makefile
##

EXECUTABLE = jam

SOURCES = $(shell find ./src -name "*.cpp")

OBJETS = $(SOURCES:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJETS)
	$(CXX) $(CXXFLAGS) $(OBJETS) -o $(EXECUTABLE) $(LDLIBS)

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re