for(int i = 1; i < 8; i++) //Reads in 8 bits from the stream, stores into currInp
		{
			cin >> currInp[i];
		}
		
		eightBits = convertB2BB(currInp); //eightBits contains numerical value of ascii char
		treeNode TreeNode;
		TreeNode.setEightBit(eightBits);
		int found = 0;
		for(int i = 0; i < QPosition; i++)
		{
			if(listOfEight[i].getEightBit() == eightBits)
			{
				listOfEight[i].incFreq();
				found = 1;
				break;
			}
			//Go through listOfEight, ONLY QPOSITION TIMES
			//If similar character found, increment frequency and return
			//Else store at end with freq = 1 and increment QPosition
		}
		
		if(found == 0)
		{
			listOfEight[QPosition] = TreeNode;
			QPosition++;
		}
		else if(found == 1)
		{
			found = 0;
		}
	} //After this, listOfEight is populated with different values and their frequencies

	for(int i = 0; i < QPosition; i++)
	{
		//cout << listOfEight[i].getFreq() << ": Freq --- eightBit: " << listOfEight[i].getEightBit() << endl;
	}
	
	quickSort(listOfEight, 0, QPosition-1);
	
	for(int i = 0; i < QPosition; i++)
	{
		cout << listOfEight[i].getFreq() << ": Freq --- eightBit: " << listOfEight[i].getEightBit() << endl;
	}
	
	//Now to create the huffman tree
	huffTree(listOfEight);
	
	
void huffman::quickSort(treeNode array[], int left, int right)
{
	//ASK ALEX ABOUT QUICK SORT WITH 2 PARAMETERS
	int i = left;
	int j = right;
	//cout << "Left: " << left << endl;
	//cout << "Right: " << right << endl;
	treeNode temp;
	int pivot = array[(left + right) / 2].getFreq();
	
	while(i <= j)
	{
		while(array[i].getFreq() < pivot)
		{
			i++;
		}
		while(array[j].getFreq() > pivot)
		{
			j--;
		}
		if(i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if(left < j)
	{
		quickSort(array, left, j);
	}
	if(i < right)
	{
		quickSort(array, i, right);
	}
}

	void quickSort(treeNode array[], int left, int right);

	
	
	
// dat pseudocode

if (encodedMessage[i] & 1)
	cout << "1";
else 
	cout << "0";
	
encodedMessage[i] <<= 1;

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
