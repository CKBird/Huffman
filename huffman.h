//Christopher Bird
//Hao Chen, ECS 60
//Homework #3
//Huffman Compression and Decompression

//huffman.h

#include<iostream>
#include <string>

using namespace std;

class treeNode
{
public:
	treeNode();
	void setEightBit(unsigned char byte) 	{ eightBit = byte; }
	unsigned char getEightBit()				{ return eightBit; }
	void incFreq()							{ freq++; }
	void setFreq(int value)					{ freq = value; }
	int getFreq()							{ return freq; }
	void setParent(treeNode* temp)			{ parent = temp; }
	treeNode* getParent()					{ return parent; }
	void setRightChild(treeNode* temp)		{ rightChild = temp; }
	void setLeftChild(treeNode* temp)		{ leftChild = temp; }
	treeNode* getLeftChild()				{ return leftChild; }
	treeNode* getRightChild()				{ return rightChild; }
	string getString()						{ return codeString; }
	void setString(string temp)				{ codeString = temp; }
	
private:
	unsigned char eightBit;
	int freq;
	treeNode *parent;
	treeNode *leftChild;
	treeNode *rightChild;
	string codeString;
};

class minHeap
{
public:
	minHeap(int theCapacity);
	void push(treeNode temp);
	void pop();
	int returnSize()			{ return heapSize; }
	treeNode returnRoot()		{ return heap[1]; }

private:
	
	treeNode *root;
	int heapSize;		//Number of elements in heap
	int capacity; 		//Size of array heap
	treeNode *heap;
	//treeNode elements[257];
};

class huffman
{
public:
	huffman();
	~huffman();
	void compress();
	void readUncom();
	void makeHuff();
	void makeCodeBook(treeNode* root);
	void buildInt();
	void decompress();
	unsigned int convertB2BL(unsigned char *bits);
	unsigned int convertB2BB(unsigned char *bits);
	

private:
	minHeap* Heap;
	treeNode codeBook[257];
	treeNode finalNode;
	string tempString;
	
};	