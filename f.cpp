#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;
	fout.open("Data.txt");
	fout << "  I am File " << endl;
	fout.close();
	fin.open("Data.txt",ios::in);
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
	fin.close();
}
