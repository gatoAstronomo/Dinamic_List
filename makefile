all:
		clear
		g++ -c list.cpp
		g++ -c main.cpp

		g++ -o main.exe list.o main.o
		rm *.o
		./main.exe