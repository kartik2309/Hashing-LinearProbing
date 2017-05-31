#pragma once
#include"Associative.h"

class Hash
{
	typedef struct item {
		string name;
		string balance;
	}*itemptr;
	itemptr hashtable[SIZE];
	int HashFunction(string);
	int LinearProbingFunction(int);
public:
	Hash();
	~Hash();
	int FreeSpaceLeft();
	void AddItem(string, string);
	void DeleteName(string);
	void SearchName(string);
	void ChangeDetails(string, string);
	void PrintHashTable();
};

