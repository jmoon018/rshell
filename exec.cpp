#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

bool printErrors = false;

void prnt(string s)
{
	if(printErrors)
		cout << s << endl;
}

// responsible for splitting up the input into words
char** tokenize(string input)
{
	vector<string>  v;

	int cnt = 0, wordCnt = 0;
	string word;	
	for(string::iterator it=input.begin(); it != input.end(); it++)// not null
	{
		//cout << "Cnt: " << cnt << endl;
		//cout << "swg" << endl;
		if(input.at(cnt) == ' ')
		{
			prnt("Found a space");

			v.push_back(word);	
			word = "";

			prnt("Delete worked fine");
		}
		else
		{
			prnt("Found a normal character");

		   word += input.at(wordCnt);	
		}
			cnt++;
			wordCnt++;	
	}
	
	v.push_back(word);

   int	words = v.size();
	char** cArray = new char*[words];

	for(int i = 0; i < words; i++)
	{
		char* curWord = new char[v.at(i).size()];
		for(int b = 0; b < v.at(i).size(); b++)
		{
			curWord[b] = v.at(i).at(b);
		}
		cArray[i] = curWord;
		//cout << "curword: " << v.at(i) << endl;
	}

	return cArray;
}


int main(int argc, char** argv)
{
	cout << "Initializing command prompt.." << endl;
	string input;
	bool cont = true;
	while(cont) // perpetual until a break (when last cmd is used)
	{
		// Print prompt
		cout << "$ ";

		// Wait for input
		std::getline (std::cin, input);

		char** words = tokenize(input);
		
		//cout << "test..: " <<  *words << "..." << *(words+1) << endl;
		
		while(true) // break when we reach ;
		{
				int error = execvp(words[0], words);
				if(error  == -1)
				{
					perror("ERROR");
				}
				else
				{

					cout << "swag" << endl;
				}
				break;
		}	
		break;
	}
	return 0;
}
