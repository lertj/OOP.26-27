
#include <stdio.h>
#include <iostream>
using namespace std;

void sum(int a, int b, int sum2) /// passing by value
{
	sum2 = a + b;
	a = 0; b = 0;
}
//printf("%d", a + b);

void sumRef(int a, int b, int &sum2) /// passing by reference (C++ ONLY)
{
	sum2 = a + b;
	a = 0; b = 0;
}

void sumAdress(int* a, int* b, int* sum2) /// passing by Adress
{
	*sum2 = *a + *b;
	*a = 0; *b = 0;
}

void main()
{
	int a, b, sum2;
	sum2 = 0;
	printf("a = "); scanf_s("%d", &a);
	printf("b = "); scanf_s("%d", &b);
	sumAdress(&a, &b, &sum2);
	cout << "a= " << a;
	cout << "b = " << b;
	printf("sum 2=");
	printf("%d", sum2);
}

