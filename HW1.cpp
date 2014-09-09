/*       Name: JongHoon Choi
*       Date: September 6, 2014
*      Class: CSC 340.01
* Assignment: Homework 1
*/
#include <iostream>
#include <vector>
using namespace std;
char *stringPara;
int getFreqLetter();
int max;

int main()
{
	cout << "Enter the paragraph string: ";
	cin >> *stringPara;
	getFreqLetter();
	cout << "Most common letter is used " << max << " times." << endl;
	return 0;
}

int getFreqLetter()
{
	int array[26];
	char temp;
	while (temp = *stringPara++){
		switch (temp)
		{
		case 'A':
			array[0]++;
			break;
		case 'a':
			array[0]++;
			break;
		case 'B':
			array[1]++;
			break;
		case 'b':
			array[1]++;
			break;
		case 'C':
			array[2]++;
			break;
		case 'c':
			array[2]++;
			break;
		case 'D':
			array[3]++;
			break;
		case 'd':
			array[3]++;
			break;
		case 'E':
			array[4]++;
			break;
		case 'e':
			array[4]++;
			break;
		case 'F':
			array[5]++;
			break;
		case 'f':
			array[5]++;
			break;
		case 'G':
			array[6]++;
			break;
		case 'g':
			array[6]++;
			break;
		case 'H':
			array[7]++;
			break;
		case 'h':
			array[7]++;
			break;
		case 'I':
			array[8]++;
			break;
		case 'i':
			array[8]++;
			break;
		case 'J':
			array[9]++;
			break;
		case 'j':
			array[9]++;
			break;
		case 'K':
			array[10]++;
			break;
		case 'k':
			array[10]++;
			break;
		case 'L':
			array[11]++;
			break;
		case 'l':
			array[11]++;
			break;
		case 'M':
			array[12]++;
			break;
		case 'm':
			array[12]++;
			break;
		case 'N':
			array[13]++;
			break;
		case 'n':
			array[13]++;
			break;
		case 'O':
			array[14]++;
			break;
		case 'o':
			array[14]++;
			break;
		case 'P':
			array[15]++;
			break;
		case 'p':
			array[15]++;
			break;
		case 'Q':
			array[16]++;
			break;
		case 'q':
			array[16]++;
			break;
		case 'R':
			array[17]++;
			break;
		case 'r':
			array[17]++;
			break;
		case 'S':
			array[18]++;
			break;
		case 's':
			array[18]++;
			break;
		case 'T':
			array[19]++;
			break;
		case 't':
			array[19]++;
			break;
		case 'U':
			array[20]++;
			break;
		case 'u':
			array[20]++;
			break;
		case 'V':
			array[21]++;
			break;
		case 'v':
			array[21]++;
			break;
		case 'W':
			array[22]++;
			break;
		case 'w':
			array[22]++;
			break;
		case 'X':
			array[23]++;
			break;
		case 'x':
			array[23]++;
			break;
		case 'Y':
			array[24]++;
			break;
		case 'y':
			array[24]++;
			break;
		case 'Z':
			array[25]++;
			break;
		case 'z':
			array[25]++;
			break;
		default:
			break;



		}
	}
	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}