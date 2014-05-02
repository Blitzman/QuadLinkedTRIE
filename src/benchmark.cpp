#include <iostream> 
#include <string>
#include <list> 
#include <fstream>
#include <unordered_map>
#include <sys/resource.h>

#include "QuadLinkedTrie.h"

#define WORDS_FILE "resources/words.txt"

using namespace std;

double getcputime(void) 
{
	struct timeval tim;
	struct rusage ru;
	getrusage(RUSAGE_SELF, &ru);
	tim=ru.ru_utime;
	double t=(double)tim.tv_sec + (double)tim.tv_usec / 1000000.0;
	tim=ru.ru_stime;
	t+=(double)tim.tv_sec + (double)tim.tv_usec / 1000000.0;
	return t;
}

void loadWords(list<string> & words)
{
	ifstream fi;
	fi.open(WORDS_FILE);

	if (!fi)
	{
		cerr << "ERROR: File ";
		cerr << WORDS_FILE;
		cerr << " not found." << endl;
	}
	else
	{
		string word; 

		while (!fi.eof())
		{
			word = "";
			getline(fi, word, '\n');
			words.push_back(word);
		}

		fi.close();
	}
}

int main(void)
{
	QuadLinkedTrie<string> qltrie;
	unordered_map<string, string> hashmap;

	list<string> words;
	loadWords(words);
	string t = "benchmark";

	double i = getcputime();
	list<string>::iterator it;
	for (it = words.begin(); it != words.end(); ++it)
	{
		std::pair<std::string, string> word(*it, t);
		hashmap.insert(word);
	}
	double f = getcputime();
	cout << "[UnorderedMap]::insert took: " << (f-i) << " seconds." << endl;

	double i2 = getcputime();
	list<string>::iterator it2;
	for (it2 = words.begin(); it2 != words.end(); ++it2)
	{
		std::pair<std::string, string> word(*it2, t);
		qltrie.insert(word);
	}
	double f2 = getcputime();
	cout << "[QuadLinkedTrie]::insert took: " << (f2-i2) << " seconds." << endl;

	cout << endl;
	cout << endl;

	double il = getcputime();
	list<string>::iterator itl;
	for (itl = words.begin(); itl != words.end(); ++itl)
	{
		hashmap.at(*itl);
	}
	double fl = getcputime();
	cout << "[UnorderedMap]::at took: " << (fl-il) << " seconds." << endl;

	double il2 = getcputime();
	list<string>::iterator itl2;
	for (itl2 = words.begin(); itl2 != words.end(); ++itl2)
	{
		qltrie.at(*itl2);
	}
	double fl2 = getcputime();
	cout << "[QuadLinkedTrie]::at took: " << (fl2-il2) << " seconds." << endl;
}
