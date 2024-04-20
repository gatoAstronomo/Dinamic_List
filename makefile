all:
		clear
		g++ -c list.cpp
		g++ -c main.cpp

		g++ -o ejecutable list.o main.o
		rm *.o
		./ejecutable