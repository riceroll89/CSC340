/*
*       Date: September 10, 2014
*      Class: CSC 340.01
* Assignment: Homework 1
*/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
void getFreqLetter(string stringPara);
void countWordFreq(string stringPara);

struct wordFreq
{
	string word;
	int cnt;
};

int main()
{
	string stringPara;
	cout << "Enter the paragraph string: ";
	getline(cin, stringPara);

	int i = 0;
	char c;
	while (stringPara[i])
	{
		c = stringPara[i];
		stringPara[i] = (tolower(c)); //string is put into lowercase letter by letter
		i++;
	}

	replace(stringPara.begin(), stringPara.end(), ',', ' ');
	replace(stringPara.begin(), stringPara.end(), '.', ' ');
	replace(stringPara.begin(), stringPara.end(), ';', ' ');
	replace(stringPara.begin(), stringPara.end(), '?', ' ');
	replace(stringPara.begin(), stringPara.end(), '!', ' ');

	//cout << stringPara << endl; //test if string is converted correctly
	getFreqLetter(stringPara);
	countWordFreq(stringPara);
}

void getFreqLetter(string stringPara)
{
//Use 97 - 122 in ASCII for lower case alphabet
	char letterArray[26];
	int i;
	for (i = 0; i < 26; i++) //initialize array
	{
		letterArray[i] = 0;
	}
	for (i = 0; i < stringPara.length(); i++)
	{
		letterArray[stringPara[i]-97]++; //97 is subtracted from the ASCII lower case chars to fit into index 0-25
	}									 //the ordered chars are then counted by occurance

	int index;
	int count = 0;
	int countLetter = 0;
	for (index = 0; index < 26; index++)
	{
		if (letterArray[index] > count)//sort by most used letter
		{
			count = letterArray[index];
			countLetter = index + 97; //the index is converted into lowercase chars
		}
	}
	cout << "Most common letter, " << (char)countLetter << " is used " << count << " times." << endl;
}

void countWordFreq(string stringPara)
{
	int i;
	wordFreq wordArray[100];
	for (i = 0; i < 100; i++)
	{
		wordArray[i].word = "";
		wordArray[i].cnt = 0;
	}

	istringstream iss(stringPara); //string is separated into individual words using blank space as delimiter
	string word;
	while (iss >> word)
	{
		int i = 0;
		while (i < 100)
		{
			if (word == wordArray[i].word) //if word already exists in the array, increment word count by 1
			{
				wordArray[i].cnt++;
				break;
			}
			i++;
		}
		if (i == 100)
		{
			for (i = 0; i < 100; i++)
			{
				if (wordArray[i].word == "") //if the word is not currently in the array, add to the first available
				{							 //slot, then increment the count by 1
					wordArray[i].word = word;
					wordArray[i].cnt++;
					break;
				}
			}
		}
	}

	//sorts the words by most used first
	int j;
	int index;
	int count = 0;
	string countWord;
	for (j = 0; j < 100; j++)
	{
		for (i = 0; i < 100; i++)
		{
			if (wordArray[i].cnt > count)
			{
				count = wordArray[i].cnt;
				countWord = wordArray[i].word;
				index = i;
			}
		}
		if (count == 0)
		{
			break;
		}
		cout << countWord << " : " << count << endl;
		wordArray[index].cnt = 0;
		wordArray[index].word = ""; //removes most used word after its printed
		count = 0; //resets the counter to select the next most used word
	}
}
