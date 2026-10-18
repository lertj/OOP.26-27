//exercise 1
 #include <iostream>
#include <string>
using namespace std;

int main() {
//in: word
//out: word with vowels removed

char s[20];
int i;
cin.getline(s, 20);

for (i = 0; i < strlen(s); i++)
{
if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
{
strcpy_s(s + i,strlen(s), s + i + 1);
i--;

}

}
cout << s;
return 0;
}

//exercise 2
#include <iostream>
#include <string>
using namespace std;

int main() {
	//in: sentence
	//out: count of words inside of a sentence
	char s[100];
	int i, cnt = 0;
	char* p;
	char* context = NULL;
	cin.getline(s, 100);
	p = strtok_s(s, " ", &context);
	while (p != NULL)
	{
		cnt++;
		p = strtok_s(NULL, " ", &context);
	}
	cout << "The number of words in the sentences is " << cnt;
	return 0;
}