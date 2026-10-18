#include<iostream>

using namespace std;

int sumArray(int arr[], int nrElem)
{
	int sum = 0;

	for (int i = 0; i < nrElem; i++)
	{
		sum = sum + arr[i];
	}

	return sum;
}

int main()
{
	int staticArray[10], sumMain = 0; // const int* pointer
	//staticArray = new int[10]; NONO because it's a ct pointer
	const int* dynamicArray2 = new int[10]; // pointer to constant integer, elements cannot be changed, but you can assign a new address to the pointer
	int* const dynamicArray = new int[10]; // constant pointer, can't point to a new address (value of the pointer is constant), but the elements can be changed
	const int* const dynamicArray3 = new int[10]; // least modifiable
	//dynamicArray2[0]++;
	dynamicArray2 = new int[10];

	for (int i = 0; i < 10; i++)
	{
		staticArray[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		dynamicArray[i] = i * 2;
	}

	sumMain = sumArray(staticArray, 10);
	cout << "The sum of numbers from 1 to 10 is: " << sumMain << endl;

	int sum2 = 0;
	sum2 = sumArray(dynamicArray, 10);
	cout << sum2 << endl;
	
	cout << "dynamicArray: " << dynamicArray << endl; // the address of the 1st elem
	cout << "dynamicArray: " << *dynamicArray << endl; // the *s value of the 1st elem
	cout << "dynamicArray: " << *(dynamicArray + 1) << endl; // the *s value of the 2nd elem
	cout << "dynamicArray: " << 1[dynamicArray] << endl; // commutativity of the sum -> same as dynamicArray[1]

	return 0;
}