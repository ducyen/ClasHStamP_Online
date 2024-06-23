SRC_DIR=.

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall $(addprefix -I,$(shell find $(SRC_DIR) -type d)) -I./include -I/usr/local/include/SDL2 -D_REENTRANT $(shell sdl2-config --cflags)

# Linker flags
LDFLAGS = $(shell sdl2-config --libs) -L/usr/local/lib -lSDL2_gfx -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm -lchipmunk

# Source files
SRC_FILES = $(shell find $(SRC_DIR) -name "*.c")
# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Target executable
TARGET = my_program

# Default target
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(TARGET)
