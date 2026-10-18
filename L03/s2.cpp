#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
	int age;
	string name;
	int* grades;
};

int main()
{
	// ex1: in: input a word 
	// out: and we have to take out all the vowels
	//char s[20], res[20];
	//cout << "Input a word: ";
	//cin.getline(s, 20);

	//int j = 0;
	//for (int i = 0; i < strlen(s); i++)
	//{
	//	if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
	//	{
	//		res[j] = s[i];		
	//		j++;
	//	}
	//}

	//res[j] = '\0';

	//cout << "The resulted word without voewls is: " << res << endl;

	// ex 2: 
	// in: insert a phrase
	// out: count the words
	//char phrase[100];
	//cout << "Insert a phrase: ";
	//int i = 0, countWords = 0;
	//char* p; 
	//char* context = NULL;
	//cin.getline(phrase, 100);
	//p = strtok_s(phrase, " ", &context);
	//while (p != NULL)
	//{
	//	countWords++;
	//	p = strtok_s(NULL, " ", &context);
	//}

	// orrrr not really ok, check at home!!
	//while (phrase[i] != '\0')
	//{
	//	if (phrase[i] == ' ' && phrase[i + 1] != ' ' && phrase[i + 1] != '\0' && phrase[i - 1] != ' ')
	//	{
	//		countWords++;
	//	}
	//	i++;
	//}
	
	//cout << "The number of words within the phrase is: " << countWords << endl;

	// structs
	Student stud;
	stud.name = "Marcel";
	stud.age = 20;
	stud.grades = new int[5] {10, 8, 9, 10, 6};

	// next class

	return 0;
}