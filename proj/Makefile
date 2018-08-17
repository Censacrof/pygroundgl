LIB=../lib/

CPP=g++
CPPFLAGS=-I/usr/include/SDL2 -I$(LIB)
LDLIBS=-lSDL2 -lGLEW -lGL
LDFLAGS=-g

all: main


main: $(LIB)Display.o #$(LIB)Shader.o $(LIB)Mesh.o $(LIB)Texture.o $(LIB)Transform.h $(LIB)Camera.h $(LIB)obj_loader.o

run: main
	@./main

clean:
	rm -f main $(LIB)*.o

.PHONY: all run clean