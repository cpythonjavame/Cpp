#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>


class Cube
{
public:
	void setcube(double l, double w, double h)
	{
		m_l = l;
		m_w = w;
		m_h = h;
	}
	double S()
	{
		return (m_l * m_w + m_l * m_h + m_w * m_h) * 2;
	}
	double V()
	{
		return m_l * m_w * m_h;
	}
private:
	double m_l;
	double m_w;
	double m_h;
};
int main()
{
	Cube c1;
	double l, w, h;
	cout << "�����볤" << endl;
	cin >> l;
	cout << "�������" << endl;
	cin >> w;
	cout << "�������" << endl;
	cin >> h;
	c1.setcube(l, w, h);
	cout << "�����Ϊ��" << c1.S() << endl;
	cout << "���Ϊ��" << c1.V() << endl;
	system("pause");
	return 0;
}