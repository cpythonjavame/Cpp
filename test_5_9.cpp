#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>
#define MAX 5


struct hero
{
	string name;
	int age;
	string sex;
}s[MAX]={{"Áõ±¸",23,"ÄÐ"},{"¹ØÓð",22,"ÄÐ"}, {"ÕÅ·É",20,"ÄÐ"}, {"ÕÔÔÆ",21,"ÄÐ"}, {"õõ²õ",19,"Å®"} };

int main()
{
	int i = 0, j = 0;
	for (i = 0; i < MAX-1; i++)
	{
		for (j = 0; j < MAX - i - 1; j++)
		{
			if (s[j].age > s[j + 1].age)
			{
				struct hero x = s[j];
				s[j] = s[j + 1];
				s[j + 1] = x;
			}
		}
	}
	for (i = 0; i < MAX; i++)
	{
		cout << s[i].name << "  " << s[i].age << "  " << s[i].sex << endl;
	}
	system("pause");
	return 0;
}