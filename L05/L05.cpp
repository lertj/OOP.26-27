// seminar 5
#include <iostream>
using namespace std;

struct BankAccount
{
    string IBAN;
    char *holderName;
    float *transaction;
    int numberOfTransactions;
    void print()
    {
        cout << "This is a bank account";
        cout << this->IBAN;
    }
};

class SuperBankAccount
{
private:
    string IBAN = "Default IBAN";
    char *holderName;
    float *transactions;
    int numberOfTransactions;

public:
    void print()
    {
        cout << "This is a bank account";
        cout << this->IBAN;
    }
    void currentStatus()
    {
        float sum = 0;
        for (int i = 0; i < this->numberOfTransactions; i++)
        {
            sum += this->transactions[i];
        }
        cout << endl
             << "Current status = " << sum;
    }
    string getIBAN() const
    {
        // IBAN = "ROBZ"; <-this will not work because of const
        return this->IBAN;
    }

    int getNumberOfTransactions()
    {
        return this->numberOfTransactions;
    }

    void setIBAN(string IBAN)
    {
        this->IBAN = IBAN;
    }

    SuperBankAccount(string name, string id, float *transactions, int nrTransactions)
    {

        this->holderName = new char[strlen(name.c_str()) + 1];
        strcpy_s(this->holderName, name.length() + 1, name.c_str());
        this->IBAN = id; // uuid generator - extra stuf

        this->numberOfTransactions = nrTransactions;
        this->transactions = new float[nrTransactions];
        for (int i = 0; i < this->numberOfTransactions; i++)
        {
            this->transactions[i] = transactions[i];
        }
    }
};

class Class2
{
    void currentStatus()
    {
    }
};

int main()
{
    BankAccount ba;
    SuperBankAccount sba("Rares", "RO123456", new float[]{30, 7, 8, 3, 45}, 5);
    /*ba.transaction[0];
    sba.transaction[0];
    ba.print();
    sba.print();*/

    sba.currentStatus();
    cout << endl
         << sba.getIBAN();
    // sba.getIBAN = "IBAN";

    sba.setIBAN("RO734510659");
    cout << endl
         << sba.getIBAN();

    /*BankAccount* pba;
    pba->IBAN;*/
}
