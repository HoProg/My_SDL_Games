# Compiler options
CC = gcc
CFLAGS = -g -Wall -Wextra -I include
LDFLAGS = -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image


# Files
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))
EXEC = bin/game.exe

# My Header files
HEADERS = src/defs.h

# Default target
all: $(EXEC)

# Linking the executable
$(EXEC): $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $@

# Compiling source files
obj/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the object files and executable
clean:
	rm -f obj/*.o bin/.exe
