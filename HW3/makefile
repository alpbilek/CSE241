hw3: main.o header.o
	g++ header.o main.o -o exe

main.o:main.cpp header.h
	g++ -c main.cpp

header.o:header.cpp header.h
	g++ -c header.cpp
clean:
	rm *.o exe
