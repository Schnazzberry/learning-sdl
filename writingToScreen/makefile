main: writingToScreen.o basic_sdl_functions.o
	g++ writingToScreen.o basic_sdl_functions.o -D_REENTRANT -lSDL2 -lSDL2_image -o main

writingToScreen.o: writingToScreen.cpp
	g++ -c writingToScreen.cpp -o writingToScreen.o

basic_sdl_functions.o: ../common/includes/basic_sdl_functions.cpp
	g++ -c ../common/includes/basic_sdl_functions.cpp -o basic_sdl_functions.o

clean:
	rm -f *.o main
