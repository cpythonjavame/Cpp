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
}s[MAX]={{"刘备",23,"男"},{"关羽",22,"男"}, {"张飞",20,"男"}, {"赵云",21,"男"}, {"貂蝉",19,"女"} };

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
