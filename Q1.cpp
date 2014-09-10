/*       Name: JongHoon Choi
*       Date: September 9, 2014
*      Class: CSC 340.01
* Assignment: Homework 1
*/
#include <iostream>
#include <string>
#include <locale>
#include <sstream>
#include <algorithm>
using namespace std;
void getFreqLetter(string stringPara);

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
	cin.ignore();
	int i = 0;

	char c;
	while (stringPara[i])
	{
		c = stringPara[i];
		stringPara[i] = (tolower(c));
		i++;
	}
	replace(stringPara.begin(), stringPara.end(), ',', ' ');
	replace(stringPara.begin(), stringPara.end(), '.', ' ');

	cout << stringPara << endl;
	getFreqLetter(stringPara);

	wordFreq wordArray[100];
	for (i = 0; i < 100; i++)
	{
		wordArray[i].word = "";
		wordArray[i].cnt = 0;
	}

	istringstream iss(stringPara);
	string word;
	while (iss >> word)
	{
		int i = 0;
		while (i < 100)
		{
			if (word == wordArray[i].word)
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
				if (wordArray[i].word == "")
				{
					wordArray[i].word = word;
					wordArray[i].cnt++;
					break;
				}
			}
		}
	}
	//test unique word array
	for (i = 0; i < 100; i++)
	{
		cout << wordArray[i].word << " : " << wordArray[i].cnt << endl;
		if (wordArray[i].word == "")
		{
			break;
		}
	}
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