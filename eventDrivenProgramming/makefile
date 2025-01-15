main: keyPresses.o basic_sdl_functions.o
	g++ keyPresses.o basic_sdl_functions.o -D_REENTRANT -lSDL2 -o main

keyPresses.o: keyPresses.cpp
	g++ -c keyPresses.cpp -o keyPresses.o

basic_sdl_functions.o: ../common/includes/basic_sdl_functions.cpp
	g++ -c ../common/includes/basic_sdl_functions.cpp -o basic_sdl_functions.o 

clean:
	rm -f *.o main
