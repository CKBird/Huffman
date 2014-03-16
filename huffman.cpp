//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
//Christopher Bird
//Hao Chen, ECS 60
//Homework #3
//Huffman Compression and Decompression

//huffman.cpp

#include<iostream>
#include<string>
#include <iomanip>
#include "huffman.h"

using namespace std;

huffman::huffman()
{
	Heap = new minHeap(257);
} //Constructor

huffman::~huffman()
{
	delete Heap;
}

void huffman::compress()
{
	readUncom();
	//quickSort(listOfEight, 0, QPosition);
	//When Given uncompressed data, compress it, then spit it out compressed
	//Given sequence of 8-bit chars, no more than 2^32-1
	
}

void huffman::readUncom() //READS IN NORMAL CHARACTERS AND GETS FREQUENCIES
{
	int found = 0;
	unsigned char currInp;
	int QPosition = 0;
	treeNode elements[257];
	while(cin >> noskipws >> currInp) //Read until currInp is EOF
	{
		treeNode temp;
		temp.setEightBit(currInp);
		for(int i = 0; i < QPosition; i++) //Increment through elements
		{
			if(elements[i].getEightBit() == temp.getEightBit())
			{
				elements[i].incFreq();
				found = 1;
				break;
			}
		}
		
		if(found == 0)
		{
			elements[QPosition] = temp;
			QPosition++;
		}
		else if(found == 1)
		{
			found = 0;
		}
	}
	for(int i = 0; i < QPosition; i++)
	{
		//cout << "Element: " << i << " " << "Value: " << elements[i].getEightBit() << " Freq: " << elements[i].getFreq() << endl;
		Heap->push(elements[i]);
	}
	
	makeHuff();
	buildInt();
	
} //WORKS, STORES ALL INPUT INTO ELEMENTS[I] WITH CORRECT FREQUENCIES AND CHARACTERS

void huffman::makeHuff()
{
	
	if(Heap->returnSize() != 1)
	{
		treeNode temp, temp1, temp2;
		temp = Heap->returnRoot();
		Heap->pop();
		temp1 = Heap->returnRoot();
		Heap->pop(); //Pull two off of min heap
	
		temp2.setFreq(temp.getFreq() + temp1.getFreq());
		if (temp.getEightBit() > temp1.getEightBit())
			temp2.setEightBit(temp1.getEightBit());
		else
			temp2.setEightBit(temp.getEightBit());
		
		
		if(temp.getFreq() < temp1.getFreq())
		{
			temp2.setLeftChild(&temp);
			temp2.setRightChild(&temp1);
		}
		else if(temp.getFreq() == temp1.getFreq())
		{
			if(temp.getEightBit() < temp1.getEightBit())
			{
				temp2.setLeftChild(&temp);
				temp2.setRightChild(&temp1);
			}
			else
			{
				temp2.setLeftChild(&temp1);
				temp2.setRightChild(&temp);
			}
		}
		else
		{
			temp2.setLeftChild(&temp1);
			temp2.setRightChild(&temp);
		}
		finalNode = temp2;
		Heap->push(temp2);
		makeHuff();
	}
	else
	{
		makeCodeBook(&finalNode);
	}
}

void huffman::makeCodeBook(treeNode* root)
{
	//Makes code book
	if(root->getLeftChild() != NULL)
	{
		tempString.append("1");
		makeCodeBook(root->getLeftChild());
	}
	if(root->getRightChild() != NULL)
	{
		tempString.append("0");
		makeCodeBook(root->getRightChild());
	}
	else
	{
		root->setString(tempString);
		
		cout << setw(10) << root->getString();
		cout << " char: " << root->getEightBit() << endl; // " | freq: " << root->getFreq() << endl;
		
	}
	
	tempString = tempString.substr(0, tempString.size()-1);
	return;
}

void huffman::buildInt()
{
	cout << "I Like Cake!" << endl;
	//We have array of encodings stored in encodings;
}

void huffman::decompress()
{
	cout << "Decompression" << endl;
	//When given compressed data, decompress it, then spit it out decompressed
	//Input is in format: Magic cookie: 8 chars; "HUFFMA5" then '\0'
	//Frequency lists all ASCII 0-255 how many times they appear in uncompressed data
		//Write as 4-byte little endian unsigned int
	//Compressed contains codes if all chars in same order as they appear in uncompressed
		//convert bits into bytes, if not mult of 8, pad end with 0s
		//first bit is least significant
}

unsigned int huffman::convertB2BL(unsigned char *bits) //CONVERTS LITTLE ENDIAN BITS TO BYTES
{
	unsigned int temp = 0;
	for(int i = 7; i >= 0; i--)
	{
		temp >>= 1;
		temp += bits[i] - '0';
	}
	return temp;
}

unsigned int huffman::convertB2BB(unsigned char *bits)
{
	unsigned int temp = 0;
	for(int i = 0; i < 8; i++)
	{
		temp <<= 1;
		temp += bits[i] - '0';
	}
	return temp;
}

treeNode::treeNode()
{
	freq = 1;
	rightChild = NULL;
	leftChild = NULL;
	parent = NULL;
} //treeNode Constructor

minHeap::minHeap(int theCapacity)
{
	capacity = theCapacity;
	heapSize = 0;
	root = NULL;
	heap = new treeNode[capacity + 1]; //Heap[0] is not used
}

void minHeap::push(treeNode temp)
{
	//Insert changeSize here if needed
	int currentNode = ++heapSize;
	while((currentNode != 1) && (heap[currentNode/2].getFreq() >= temp.getFreq()))
	{
		if(heap[currentNode/2].getFreq() == temp.getFreq())
		{
			if(heap[currentNode/2].getEightBit() < temp.getEightBit())
			{
				treeNode placeH;
				placeH = heap[currentNode/2];
				heap[currentNode/2] = temp;
				temp = placeH;
				continue;
			}
		}
		heap[currentNode] = heap[currentNode/2];
		currentNode /= 2;
	}
	heap[currentNode] = temp;
}

void minHeap::pop()
{
	//cout << heap[1].getFreq() << ": is freq of char: " << heap[1].getEightBit() << endl;
	treeNode lastE = heap[heapSize--];
	
	int currentNode = 1;
	int child = 2;
	while(child <= heapSize)
	{
		if(child < heapSize && heap[child].getFreq() >= heap[child+1].getFreq())
		{
			if(heap[child].getFreq() == heap[child+1].getFreq())
			{
				if(heap[child].getEightBit() < heap[child+1].getEightBit())
				{
					child--;
				}
			}
			child++;
		}
		if(lastE.getFreq() <= heap[child].getFreq())
		{
			if(lastE.getFreq() == heap[child].getFreq())
			{
				if(heap[child].getEightBit() < lastE.getEightBit())
				{
					heap[currentNode] = heap[child];
					currentNode = child;
					child *= 2;
					continue;
				}
			}
			break;
		}
		heap[currentNode] = heap[child]; 	//Move child up
		currentNode = child;
		child *= 2;							//Move down a level
	}
	heap[currentNode] = lastE;
	return;
}