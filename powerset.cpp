//Author: Debjit Sarkar
//Description: Finds the powerset of an inputted set of integers

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

int main()
{
	//ENTER 0.5 TO STOP ENTERING INPUTS
	vector <int> input;
	vector <vector <int> > powerset;
	double holding = 0;
	int size = 0;
	int bin_size = 0;
	string bin_inc = "";
	string shorten = "";
	
	while(holding != 0.5)
	{
		cin >> holding;
		input.push_back((holding));
	}
	
	size = input.size() - 1;
	cout << "Size of input: " << size << endl;

	for(int i = 0; i < pow(2, size); i++)
	{
		vector <int> vec;
		
		bin_inc = bitset<32>(i).to_string(); //32 bit

		bin_size = bin_inc.size() - size; //32 - size

		shorten = bin_inc.substr(bin_size); //from 32 - size to 32
		
		for(int j = 0; j < size; j++)
		{
			string bit = shorten.substr(j, 1); //single bit
			if(bit == "1") //if bit = 1
				vec.push_back(input[j]); //add input int to vec
		}
		
		powerset.push_back(vec);
	}
	
	cout << "Inputs: " << endl;
	for(int i = 0; i < input.size() - 1; i++)
	{
		cout << input[i] << "\t";
	}
	
	cout << endl << "Powerset: " << endl;
	for(int i = 0; i < powerset.size(); i++)
	{
		for(int j = 0; j < powerset[i].size(); j++)
			cout << powerset[i][j] << "\t";
		
		cout << endl;
	}
	
	return 0;
}
