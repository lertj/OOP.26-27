#include <iostream>
using namespace std;

enum ProductCategory {
	DAIRY, SNACK, BEVERAGE, PASTRY
};

class Product {
private:
	const int ID;
	string name;
	string description;
	float* priceHistory = nullptr;
	int noOfPrices = 0;
	ProductCategory type = DAIRY;
	static int count;
public:
	void setPriceHistory(float* priceHistory, int noOfPrices) // deep copy
	{
		if (this->priceHistory != nullptr) {
			delete[] this->priceHistory;
			this->priceHistory = nullptr;
		}
		if (noOfPrices < 0)
			throw "Invalid length";
		//return;
		this->noOfPrices = noOfPrices;
		
		
		this->priceHistory = new float[this->noOfPrices];
		for (int i = 0; i < this->noOfPrices; i++) {
			this->priceHistory[i] = priceHistory[i];
		}

	}

    float* getPriceHistory() { // deep copy
        float* copy = new float[this->noOfPrices];
        for (int i = 0; i < this->noOfPrices; i++) {
            copy[i] = this->priceHistory[i];
        }
        return copy;
    }

	void print()
	{
		cout << endl << "ID: " << this->ID;
		cout << endl << "Name: " << this->name;
		cout << endl << "Description: " << this->description;
		cout << endl << "Type: " << this->type;
		cout << endl << "Price History: \n";
		for (int i = 0; i < this->noOfPrices; i++)
		{
			cout << this->priceHistory[i] << ' ';
		}
		
	}

	Product (/* Product* this, */ int ID, string name, string itemDescription, float* priceHistory, int noOfPrices, ProductCategory type)
		: ID(ID), name(name), description(itemDescription){
		//this->ID = ID; will not work
		//this->name = name;
		//this->description = sescription;
		//this->priceHistory = priceHistory;  shallow copy
		this->type = type;
		//this->noOfPrices = noOfPrices;
		this->setPriceHistory(priceHistory, noOfPrices);
		cout << endl << "Calling constructor";
	}
	/*Product() {
		this is the default constructor
	}*/

	~Product()
	{
		if (priceHistory != nullptr)
		{
			delete[] priceHistory;
			priceHistory = nullptr;
		}
		cout << endl << "Calling destructor";
	}

};

int Product::count = 0;

int main()
{
	//Product p; this will create a product with the default constructor
	
	Product p1(1, "Milk", "Good for bones", new float[]{15,20,21,25.5,27.8}, 5, ProductCategory::DAIRY );
	{ Product p2(2, "Milk", "Good for bones", new float[] {15, 20, 21, 25.5, 27.8}, 5, ProductCategory::DAIRY); }
	p1.print();

}