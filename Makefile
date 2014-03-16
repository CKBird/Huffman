#ckbird; Bird, Christopher

huffman : main.o huffman.o
	g++ -o huffman main.o huffman.o -Wall -g
main.o : main.cpp
	g++ -c main.cpp -Wall -g -o main.o
huffman.o : huffman.cpp huffman.h
	g++ -c huffman.cpp -Wall -g -o huffman.o