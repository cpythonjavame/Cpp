#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyArr
{
public:
	MyArr(T x)
	{
		cout << "�вι���" << endl;
		this->m_Capa = x;
		this->m_size = 0;
		this->arr = new T[this->m_Capa];
	}
	MyArr(const MyArr& p)
	{
		cout << "��������" << endl;
		this->m_Capa = p.m_Capa;
		this->m_size = p.m_size;
		this->arr = new T[this->m_Capa];
		for (int i = 0; i < this->m_size; i++)
		{
			this->arr[i] = p.arr[i];
		}
	}
	MyArr& operator=(const MyArr& p)
	{
		cout << "operator=" << endl;
		if (this->arr != NULL)
		{
			delete[] this->arr;
			this->arr = NULL;
			this->m_Capa = 0;
			this->m_size = 0;
		}
		this->m_Capa = p.m_Capa;
		this->m_size = p.m_size;
		this->arr = new T[p.m_Capa];
		for (int i = 0; i < this->m_size; i++)
		{
			this->arr[i] = p.arr[i];
		}
		return *this; 
	}
	//β��
	void PushBack(T val)
	{
		if (this->m_size == this->m_Capa)
		{
			cout << "Empty!" << endl;
			return;
		}
		this->arr[this->m_size] = val;
		this->m_size++;
	}
	//βɾ
	void PopBack()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}
	//����
	int operator[](int index)
	{
		return this->arr[index];
	}
	//��������
	int GetCapa()
	{
		return this->m_Capa;
	}
	//���������С
	int GetSize()
	{
		return this->m_size;
	}
	//��ӡ
	void MyArrPrint()
	{
		for (int i = 0; i < this->m_size; i++)
		{
			cout << this->arr[i] << endl;
		}
	}
	~MyArr()
	{
		cout << "��������" << endl;
		if (this->arr != NULL)
		{
			delete[] this->arr;
			this->arr = NULL;
			this->m_Capa = 0;
			this->m_size = 0;
		}
	}
private:
	int m_size;
	int m_Capa;
	T* arr;
};