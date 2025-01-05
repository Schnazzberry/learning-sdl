main: helloSDL.o
	g++ helloSDL.o -D_REENTRANT -lSDL2 -o main

helloSDL.o: helloSDL.cpp
	g++ -c helloSDL.cpp -o helloSDL.o

clean:
	rm -f helloSDL.o main