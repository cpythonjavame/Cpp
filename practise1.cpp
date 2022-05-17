#include <iostream>
#include <string>
using namespace std;


class CPU
{
public:
	virtual void cal() = 0;
};

class Vid
{
public:
	virtual void see() = 0;
};

class Save
{
public:
	virtual void sav() = 0;
};

class Computer
{
public:
	Computer(CPU* a,Vid* b,Save* c)
	{
		X = a;
		Y = b;
		Z = c;
		cout << "succed" << endl;
	}
	void work()
	{
		X->cal();
		Y->see();
		Z->sav();
	}
	~Computer()
	{
		if (X != NULL)
		{
			delete X;
			X = NULL;
		}
		if (Y != NULL)
		{
			delete Y;
			Y = NULL;
		}
		if (Z != NULL)
		{
			delete Z;
			Z = NULL;
		}
		cout << "ÊÍ·Å³É¹¦" << endl;
	}
	CPU* X;
	Vid* Y;
	Save* Z;
};

class InterCPU :public CPU
{
public:
	void cal()
	{
		cout << "cal" << endl;
	}
};

class InterVid :public Vid
{
public:
	void see()
	{
		cout << "see" << endl;
	}
};

class InterSave :public Save
{
public:
	void sav()
	{
		cout << "sav" << endl;
	}
};

class LenCPU :public CPU
{
public:
	void cal()
	{
		cout << "cal" << endl;
	}
};

class LenVid :public Vid
{
public:
	void see()
	{
		cout << "see" << endl;
	}
};

class LenSave :public Save
{
public:
	void sav()
	{
		cout << "sav" << endl;
	}
};

void test01()
{
	Computer* c=new Computer(new InterCPU, new InterVid, new InterSave);
	c->work();
	delete c;
	cout << "--------------" << endl;
	Computer* c1 = new Computer(new LenCPU, new LenVid, new LenSave);
	c1->work();
	delete c1;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
