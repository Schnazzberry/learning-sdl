main: loadingPNGs.o basic_sdl_functions.o
	g++ loadingPNGs.o basic_sdl_functions.o -D_REENTRANT -lSDL2 -lSDL2_image -o main

loadingPNGs.o: loadingPNGs.cpp
	g++ -c loadingPNGs.cpp -o loadingPNGs.o

basic_sdl_functions.o: ../common/includes/basic_sdl_functions.cpp
	g++ -c ../common/includes/basic_sdl_functions.cpp -o basic_sdl_functions.o 

clean:
	rm -f *.o main
