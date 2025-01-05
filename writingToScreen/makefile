main: writingToScreen.o basicfunctions.o
	g++ writingToScreen.o basicfunctions.o -D_REENTRANT -lSDL2 -o main

helloSDL.o: writingToScreen.cpp
	g++ -c writingToScreen.cpp -o writingToScreen.o

basicfunctions.o: basicfunctions.cpp
	g++ -c basicfunctions.cpp -o writingToScreen.o
clean:
	rm -f *.o main