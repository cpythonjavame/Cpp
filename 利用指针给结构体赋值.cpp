#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>


struct student
{
	string stu_name;
	int score;
};

struct teacher
{
	string tea_name;
	struct student s[5];
}t1,t2,t3;

void fun(struct teacher* p[3], string tea[], string stu[][5], int sco[][5])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		p[i]->tea_name = tea[i];
		for (j = 0; j < 5; j++)
		{
			p[i]->s[j].stu_name = stu[i][j];
			p[i]->s[j].score = sco[i][j];
		}
	}
}

int main()
{
	int j = 0;
	struct teacher* p1[3] = {&t1,&t2,&t3};
	string tea[3] = { "zhangsan","lisi","wangwu" };
	string stu[3][5] = { {"a","b","c","d","e"},{"0","1","2","3","4"}, {"5","6","7","8","9"} };
	int sco[3][5]= { {88,78,99,45,66},{88,88,95,74,91}, {64,54,54,64,6} };
	fun(p1, tea, stu, sco);
	cout << t1.tea_name << endl;
	for (j = 0; j < 5; j++)
	{
		cout << t1.s[j].stu_name << ": " << t1.s[j].score << endl;
	}
	cout << t2.tea_name << endl;
	for (j = 0; j < 5; j++)
	{
		cout << t2.s[j].stu_name << ": " << t2.s[j].score << endl;
	}
	cout << t1.tea_name << endl;
	for (j = 0; j < 5; j++)
	{
		cout << t3.s[j].stu_name << ": " << t3.s[j].score << endl;
	}
	system("pause");
	return 0;
}
