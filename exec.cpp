#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

bool printErrors = true;

void prnt(string s)
{
	if(printErrors)
		cout << s << endl;
}

// responsible for splitting up the input into words
char** tokenize(string input)
{
	vector<char*>  v;

	int cnt = 0, wordCnt = 0;
	for(string::iterator it=input.begin(); it != input.end(); it++)// not null
	{
		char*  word;
		cout << "Cnt: " << cnt << endl;
		if(input.at(cnt) == ' ')
		{
			prnt("Found a space");
			v[wordCnt] = word;
			wordCnt++;
		}
		else
		{
			prnt("Found a normal character");
			word += input.at(cnt);
			cout << "Word is.." << word << endl;
		}

		cnt++;
	}

	char* cArray[5] = new char[5] = {'' };
	for(int i = 0; i < v.size(); i++)
	{
		cArray[i] = v.at(i);
	}

	return cArray;
}


int main(int argc, char** argv)
{
	cout << "Initializing command prompt.." << endl;
	string input;

	while(true)
	{
		// Print prompt
		cout << "$ ";

		// Wait for input
		std::getline (std::cin, input);

		char* words[] = tokenize(input);
		delete words[];
		

		break;
	}
	return 0;
}
