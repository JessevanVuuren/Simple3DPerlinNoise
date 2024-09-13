CC = gcc

CFLAGS = -I./lib/raylib/
LDFLAGS = -L./lib/raylib/

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

FLAGS = -Werror

SRC = main.c

TARGET = out

# Target to compile the program
$(TARGET): $(SRC)
	-mkdir $(OUTPUT)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LIBS) $(FLAGS)

# Clean up build files
clean:
	-rm -fr $(TARGET)