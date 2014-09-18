/*
*       Date: September 8, 2014
*      Class: CSC 340.01
* Assignment: Homework 1
*/
#include <iostream>
#include <string>
#include <locale>
using namespace std;
void getFreqLetter(string stringPara);
void wordFreq(string stringPara);

int main()
{
	string stringPara;
	cout << "Enter the paragraph string: ";
	getline(cin, stringPara);
	cin.ignore();
	int i = 0;

	char c;
	while (stringPara[i])
	{
		c = stringPara[i];
		stringPara[i] = (tolower(c));
		i++;
	}

	cout << stringPara << endl;
	getFreqLetter(stringPara);
	wordFreq(stringPara);
	return 0;
}

void getFreqLetter(string stringPara)
{
//Use 97 - 122 in ASCII for lower case alphabet
	char letterArray[26];
	int i;
	for (i = 0; i < 26; i++)
		letterArray[i] = 0;

	for (i = 0; i < stringPara.length(); i++)
	{
		letterArray[stringPara[i]-97]++;
	}

	int index;
	int count = 0;
	int countLetter = 0;
	for (index = 0; index < 26; index++)
	{
		if (letterArray[index] > count)
		{
			count = letterArray[index];
			countLetter = index + 97;
		}
	}
	cout << "Most common letter, " << (char)countLetter << " is used " << count << " times." << endl;
}

void wordFreq(string stringPara)
{

}
