//Christopher Bird
//Hao Chen, ECS 60
//Homework #3
//Huffman Compression and Decompression

//main.cpp

#include<iostream>
#include<cstring>
#include "huffman.h"
using namespace std;

int main(int argc, char** argv)
{
	huffman Huffman;
	//string encodings[258];
	if(argc < 2)// if not -d 
	{
		Huffman.compress();
		//Compress input, and write compressed data to output
	}
	
	else if (!strcmp(argv[1], "-d")) // if -d
	{
		Huffman.decompress();
		//Decompress the input, and write decompressed data to output
	}
	
	else //if not -d
	{
		Huffman.compress();
		//Compress input, 
	}
	//cout << "DEAD" << endl;
	
	return 0;
}