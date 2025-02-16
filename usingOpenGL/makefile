main: usingOpenGL.o basic_sdl_functions.o glad.o
	g++ usingOpenGL.o basic_sdl_functions.o glad.o -D_REENTRANT -lSDL2 -lSDL2_image -o main

usingOpenGL.o: usingOpenGL.cpp
	g++ -c usingOpenGL.cpp -o usingOpenGL.o

basic_sdl_functions.o: ../common/includes/basic_sdl_functions.cpp
	g++ -c ../common/includes/basic_sdl_functions.cpp -o basic_sdl_functions.o 

glad.o: ../common/includes/glad.c
	gcc -c ../common/includes/glad.c -o glad.o

clean:
	rm -f *.o main
