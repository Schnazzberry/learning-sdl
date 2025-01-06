main: writingToScreen.o
	g++ writingToScreen.o -D_REENTRANT -lSDL2 -o main

writingToScreen.o: writingToScreen.cpp
	g++ -c writingToScreen.cpp -o writingToScreen.o

clean:
	rm -f *.o main
