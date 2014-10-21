#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

bool printErrors = false;
int totalWordCount = 0;
void prnt(string s)
{
	if(printErrors)
		cout << s << endl;
}

/* 
	char** tokenize(string)
	===================================================================================
	responsible for splitting up the input into words
	creates a vector of strings (size of char** is undetermined until
		parsing is done, so I use vectors because of their dynami size
	
	loops through all the letters of the input, and once a delimiter(space, etc)
		is found, it will merge the letters into a word, add it to the vector,
		and reset the word (word = "")

	when finished, a char** is made because the final size is finally known (v.size())
		Loop through the vector and through each of its children and add its contents
		to the new char**. 

	return char** (cArray)
	
*/
/*
char**  tokenize(string input)
{
	vector<string>  v; // contains all the words delimited by spaces and ;

	int cnt = 0, wordCnt = 0; // cnt=index in input string, wordCnt = current word length
	string word; // add letters from input to this string, then add it to vector when delim. found	

	for(string::iterator it=input.begin(); it != input.end(); it++)// not null
	{
		if(input.at(cnt) == ' ') // delimiter #1 - space
		{
			prnt("Found a space");
			
			// add the word we have and reset it
			v.push_back(word);	
			word = "";

			prnt("Delete worked fine");
		}
		else if(input.at(cnt) == ';') // delimiter #2 - semicolon
		{
			v.push_back(word); // push back w/e word we have
			v.push_back(";"); // then add a semicolon [as a new 'word' or element in the vector]
			word = ""; // reset word
		}
		else
		{
			prnt("Found a normal character");

		   word += input.at(wordCnt);	
		}
			cnt++;
			wordCnt++;	
	}
	
	// add the last word (since it wasnt proccessed by the for loop above)
	v.push_back(word);

	// create char** and copy elements into it
   int	words = v.size();
	totalWordCount = words;
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

*/

vector<string>  tokenize(string input)
{
	vector<string>  v; // contains all the words delimited by spaces and ;

	int cnt = 0, wordCnt = 0; // cnt=index in input string, wordCnt = current word length
	string word; // add letters from input to this string, then add it to vector when delim. found	

	for(string::iterator it=input.begin(); it != input.end(); it++)// not null
	{
		if(input.at(cnt) == ' ') // delimiter #1 - space
		{
			prnt("Found a space");
			
			// add the word we have and reset it
			v.push_back(word);	
			word = "";
			totalWordCount++;
			prnt("Delete worked fine");
		}
		else if(input.at(cnt) == ';') // delimiter #2 - semicolon
		{
			v.push_back(word); // push back w/e word we have
			v.push_back(";"); // then add a semicolon [as a new 'word' or element in the vector]
			word = ""; // reset word
			totalWordCount+= 2;
		}
		else
		{
			prnt("Found a normal character");

		   word += input.at(wordCnt);	
		}
			cnt++;
			wordCnt++;	
	}
	
	// add the last word (since it wasnt proccessed by the for loop above)
	v.push_back(word);
	totalWordCount++;

	return v;
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

		vector<string> words = tokenize(input);
		
		//for(int i = 0; i < totalWordCount; i++) { cout << words[i]  << " " << endl; }

		//cout << "wordcnt: " << totalWordCount << endl;
		char* h[totalWordCount];
		for(int i = 0; i < totalWordCount; i++) 
		{
			h[i] = new char[words[i].size()+1];
			copy(words[i].begin(), words[i].end(), h[i]);
			h[i][words[i].size()] = '\0';
		} 

		h[totalWordCount] = NULL;
		while(true) // break when we reach ;
		{
				cout << "swag" << endl;
				int error = execvp(h[0], h);
				if(error  == -1)
				{
					perror("ERROR");
					exit(1);
				}
				else
				{

					cout << "swag" << endl;
				}
				break;
		}	
		delete [] h; // free mem
		break;
	}
	return 0;
}
