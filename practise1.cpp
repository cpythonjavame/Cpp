#include "Myarr.hpp"



void test01()
{
	MyArr <int>arr1(10);
	MyArr <int>arr2(arr1);
	MyArr <int>arr3(100);
	arr3 = arr1;
	arr3.PushBack(10);
	arr3.PushBack(11);
	arr3.PushBack(12);
	arr3.MyArrPrint();
	cout<<arr3.GetCapa()<<endl;
	cout<<arr3.GetSize()<<endl;
	cout << arr3[1] << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
