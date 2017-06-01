#include "stdafx.h"
#include "Hash.h"


int Hash::HashFunction(string Name)
{
	int hashindex = 0;
	for (int i = 0; i != Name.length(); i++)
		hashindex = hashindex + (int)Name[i];
	int index = hashindex%SIZE;
	return index;
}

int Hash::LinearProbingFunction(int index)
{
	index++;
	if (index >= SIZE) {
		index = 0;
	}
	return index;
}

Hash::Hash()
{
	for (int i = 0; i != SIZE; i++) {
		hashtable[i] = new item;
		hashtable[i]->name = "NULL";
		hashtable[i]->balance = "NULL";
	}
}


Hash::~Hash()
{
}

int Hash::FreeSpaceLeft()
{
	int count = 0;
	for (int i = 0; i != SIZE; i++) {
		if (hashtable[i]->name == "NULL")
			count++;
	}
	return count;
}

void Hash::AddItem(string Name, string Balance)
{
	if (hashtable[HashFunction(Name)]->name == "NULL") {
		hashtable[HashFunction(Name)]->name = Name;
		hashtable[HashFunction(Name)]->balance = Balance;
	}
	else {
		int index = HashFunction(Name);
		while (hashtable[index]->name != "NULL") {
			index = LinearProbingFunction(index);
			if (index == HashFunction(Name))
				break;
		}
		if (index == HashFunction(Name))
			cout << "Sorry!The Hashtable is Full!Delete few records to add more!" << endl;
		else {
			hashtable[index]->name = Name;
			hashtable[index]->balance = Balance;
		}
	}
}

void Hash::DeleteName(string Name)
{
	if (hashtable[HashFunction(Name)]->name == "NULL") {
		hashtable[HashFunction(Name)]->name = "NULL";
		hashtable[HashFunction(Name)]->balance = "NULL";
	}
	else {
		int index = HashFunction(Name);
		while (hashtable[index]->name != Name) {
			index = LinearProbingFunction(index);
			if (index == HashFunction(Name))
				break;
		}
		if (index == HashFunction(Name))
			cout << "Sorry!Your item wasn't found in the HashTable to be deleted" << endl;
		else {
			hashtable[index]->name = "NULL";
			hashtable[index]->balance = "NULL";
		}
	}
}

void Hash::SearchName(string Name)
{
	if (hashtable[HashFunction(Name)]->name == Name) {
		cout << "Name is:" << hashtable[HashFunction(Name)]->name << endl;
		cout << "Balance is:" << hashtable[HashFunction(Name)]->balance << endl;
	}
	else {
		int index = HashFunction(Name);
		while (hashtable[index]->name != Name) {
			index = LinearProbingFunction(index);
			 if(index == HashFunction(Name)) {
				break;
			}
		}
		if (index == HashFunction(Name)) {
			cout << "Sorry!Given Name wasn't found in the Hashtable" << endl;
		}
		else {
			cout << "Name is:" << hashtable[index]->name << endl;
			cout << "Balance is:" << hashtable[index]->balance << endl;
		}
	}
}

void Hash::ChangeDetails(string Name, string Balance)
{
	DeleteName(Name);
	AddItem(Name, Balance);
}

void Hash::PrintHashTable()
{
	for (int i = 0; i != SIZE; i++) {
		if (hashtable[i]->name != "NULL") {
			cout << "--------------------" << endl;
			cout << "At Index:" << i << endl;
			cout << "Name is:" << hashtable[i]->name << endl;
			cout << "Balance is:" << hashtable[i]->balance << endl;
			cout << "--------------------" << endl;
		}
	}
}

