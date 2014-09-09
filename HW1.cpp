/*       Name: JongHoon Choi
*       Date: September 6, 2014
*      Class: CSC 340.01
* Assignment: Homework 1
*/
#include <iostream>
#include <string>
using namespace std;
void getFreqLetter(string stringPara);
int main()
{
	string stringPara;
	cout << "Enter the paragraph string: ";
	cin >> stringPara;
	getFreqLetter(stringPara);

	return 0;
}

void getFreqLetter(string stringPara)
{
//Use 65 - 122 in ASCII for upper and lower case alphbet
	char letterArray[57];
	int i;
	for (i = 0; i < 56; i++)
		letterArray[i] = 0;

	for (i = 0; i < stringPara.length(); i++)
	{
		letterArray[stringPara[i]-65]++;
	}

	int index;
	int count = 0;
	int countLetter = 0;
	for (index = 0; index < 56; index++)
	{
		if (letterArray[index] > count)
		{
			count = letterArray[index];
			countLetter = index + 65;
		}
	}



	cout << "Most common letter, " << (char)countLetter << " is used " << count << " times." << endl;
}