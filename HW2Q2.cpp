#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void threesort(int &a, int &b, int &c) {
	if (a > b) swap(&a, &b);
	if (a > c) swap(&a, &c);
	if (b > c) swap(&b, &c);
}

int main() {

	//step 1: ask user for file names

	//declare files to reading
	ifstream file, file2, file3;

	//declare files to write
	//ofstream merged("merged.txt");
	string filename, filename2, filename3;
	cout << "Enter the name of the first file: ";
	cin >> filename;
	file.open(filename.c_str());
	if (file.fail()){
		cout << "File not found" << endl;
		exit(1);
	}
	cout << "Enter the name of the second file: ";
	cin >> filename2;
	file2.open(filename2.c_str());
	if (file2.fail()){
		cout << "File not found" << endl;
		exit(1);
	}
	cout << "Enter the name of the third file: ";
	cin >> filename3;
	file3.open(filename3.c_str());
	if (file3.fail()){
		cout << "File not found" << endl;
		exit(1);
	}
	ofstream merged;
	merged.open("merged.txt");

	//step 2: call merge function to merge and sort data
	int a; int b; int c;
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;

	while (!file.eof() || !file2.eof() || !file3.eof())
	{
		file >> a;
		file2 >> b;
		file3 >> c;
		threesort(a, b, c);
		cout << a << endl << b << endl << c << endl;
		/*
		vec1.push_back(i);
		vec2.push_back(j);
		vec3.push_back(k);
		*/
	}
	/*
	while (!file2.eof())
	{
		file2 >> j;
		
	}
	while (!file3.eof())
	{
		file3 >> k;
		
	}
	*/
	//test vectors
	/*
	for (vector<int>::const_iterator i = vec1.begin(); i != vec1.end(); ++i)
		cout << *i << endl;
	for (vector<int>::const_iterator i = vec2.begin(); i != vec2.end(); ++i)
		cout << *i << endl;
	for (vector<int>::const_iterator i = vec3.begin(); i != vec3.end(); ++i)
		cout << *i << endl;
	*/
	//sizeof(int)

	//step 3: print the name of the merged file
	cout << "The title of the merged file is merged.txt" << endl;

	file.close();
	file2.close();
	file3.close();
	merged.close();

	return 0;
}