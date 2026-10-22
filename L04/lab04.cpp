// data - variables and behaviour - functions
// model a class = a req (stud, bank acc) and implement a class which has behav and data -> represent the real life thing into the code 
#include <iostream>

using namespace std;

struct BankAccount
{
	char* name = nullptr;
	string id = "default id";
	float* transactions = nullptr;
	int nrTransactions = 0;
};

BankAccount initBankAccount(string name, string id, float* transactions, int nrTransactions)
{
	BankAccount ba;
	ba.name = new char[strlen(name.c_str()) + 1];
	strcpy_s(ba.name, name.length() + 1, name.c_str());
	ba.id = id; //uuid generator - extra stuf

	ba.nrTransactions = nrTransactions;
	ba.transactions = new float[nrTransactions];
	for (int i = 0; i < ba.nrTransactions; i++)
	{
		ba.transactions[i] = transactions[i];
	}

	return ba;
}

void printBankAccount(BankAccount ba)
{
	if (ba.name != nullptr)	// how to avoid crashing the program; it's a guard
		cout << ba.name;
	cout << endl;
	cout << ba.id << endl;
	cout << ba.nrTransactions << endl;   // garbage values or 0 
	for (int i = 0; i < ba.nrTransactions; i++)
	{
		cout << ba.transactions[i] << ' ';
	}
	cout << endl;
}

void topUp(BankAccount ba, float amount)
{
	for (int i = 0; i < ba.nrTransactions;i++)
	{
		if(ba.transactions[i] == 0)
		{
			ba.transactions[i] = amount;
			break;
		}
	}
}

void incrementId(BankAccount& ba)
{
	ba.id = ba.id + "1";
}

int main()
{
	string name = "Catalin Popescu";
	string name2 = "Manole Ion";
	BankAccount ba;
	BankAccount ba2;

	int nrTransactions = 10;
	float* transactions = new float[nrTransactions];
	
	for (int i = 0; i < nrTransactions; i++)
	{
		transactions[i] = 0;
	}

	//ba.name = new char[strlen(name.c_str()) + 1];
	//strcpy_s(ba.name, name.length() + 1, name.c_str());
	//ba.id = "b3aeb6fc-3eeb-48e6-b938-c6a5cc1a8ca7"; //uuid generator - extra stuff
	//

	//ba.nrTransactions = nrTransactions;
	//ba.transactions = new float[nrTransactions];
	//for (int i = 0; i < ba.nrTransactions; i++)
	//{
	//	ba.transactions[i] = transactions[i];
	//}

	ba = initBankAccount(name, "b3aeb6fc-3eeb-48e6-b938-c6a5cc1a8ca7", transactions, 
		nrTransactions);
	ba2 = initBankAccount(name2, "2a565b1f-9eb8-4ba5-9f83-e4def2b262dc", transactions,
		nrTransactions);
	//if(ba.name != nullptr)	// how to avoid crashing the program; it's a guard
	//	cout << ba.name;
	//cout << endl;
	//cout << ba.id << endl;
	//cout << ba.nrTransactions << endl;   // garbage values or 0 
	//for (int i = 0; i < ba.nrTransactions; i++)
	//{
	//	cout<< ba.transactions[i] << ' ';
	//}
	//cout << endl;

	printBankAccount(ba);
	cout << endl;
	printBankAccount(ba2);
	cout << endl;
	topUp(ba2, 100);
	printBankAccount(ba2);
	cout << endl;
	incrementId(ba2);
	printBankAccount(ba2);

	return 0;
}