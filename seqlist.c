#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"


void menu()
{
	printf("**************************\n");
	printf("*********  0.退出  ********\n");
	printf("***1.头插         2.尾插***\n");
	printf("***3.头删         4.尾删***\n");
	printf("***   5.对指定位置插入   ***\n");
	printf("***   6.对指定位置删除   ***\n");
	printf("***   7.查找元素的下标   ***\n");
	printf("***     8.打印数据      ***\n");
	printf("**************************\n");
}

//初始化顺序表
void IniSL(SL* p)
{
	p -> a = NULL;
	p -> size = 0;
	p -> capacity = 0;
	/*SeqListLoad(p);*/
}

//打印数据
void SeqListprint(SL* p)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("\n");
}

//尾插
void SeqlistPushBack(SL* p, SLdatatype x)
{
	//没有空间或空间不足
	if (p->size == p->capacity)
	{
		size_t newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		SLdatatype* temp = NULL;
		temp = (SLdatatype*)realloc(p->a, newcapacity * sizeof(SLdatatype));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		p->a = temp;
		p->capacity = newcapacity;
	}
	p->a[p->size] = x;
	p->size = p->size + 1;
}

//尾删
void SeqlistpophBack(SL* p)
{
	p->size = p->size > 0 ? p->size - 1 : 0;
}

//头插
void SeqlistPushFront(SL* p, SLdatatype x)
{
	//没有空间或空间不足
	if (p->size == p->capacity)
	{
		size_t newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		SLdatatype* temp = NULL;
		temp = (SLdatatype*)realloc(p->a, newcapacity * sizeof(SLdatatype));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		p->a = temp;
		p->capacity = newcapacity;
	}
	for (size_t i = p->size; i > 0; i--)
	{
		p->a[i] = p->a[i - 1];
	}
	p->a[0] = x;
	p->size++;
}

//头删
void SeqlistpophFront(SL* p)
{
	if (p->size > 0)
	{
		for (size_t i = 0; i < p->size - 1; i++)
		{
			p->a[i] = p->a[i + 1];
		}
		p->size--;
	}
}

//找到元素返回下标
int SeqListFind(SL* p, SLdatatype x)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (p->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//指定位置插入
void SeqListinsert(SL* p, int pos, SLdatatype x)
{
	if (pos<0 || pos>p->size)
	{
		printf("输入位置错误\n");
		return;
	}
	if (p->size == p->capacity)
	{
		size_t newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		SLdatatype* temp = NULL;
		temp = (SLdatatype*)realloc(p->a, newcapacity * sizeof(SLdatatype));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		p->a = temp;
		p->capacity = newcapacity;
	}
	int i = 0;
	for (i = p->size-1; i >= pos; i--)
	{
		p->a[i + 1] = p->a[i];
	}
	p->a[pos] = x;
	p->size++;
}

//指定位置删除
void SeqListerase(SL* p, int pos)
{
	if (pos<0 || pos>p->size)
	{
		printf("输入位置错误\n");
		return;
	}
	int i = 0;
	for (i = pos; i < p->size-1; i++)
	{
		p->a[i] = p->a[i + 1];
	}
	p->size--;
}
//销毁顺序表
void SeqListDestroy(SL* p)
{
	free(p->a);
	p->a = NULL;
	p->capacity = p->size = 0;
}




//好像动态内存结束后会被系统自动释放，不能保存...........
////保存到本地
//void SeqlistSave(SL* p)
//{
//	FILE* ptr = fopen("seqlist.dat", "w");
//	if (ptr == NULL)
//	{
//		perror("SeqlistSave");
//		return;
//	}
//	fwrite(p, sizeof(SL), 1, ptr);
//	fclose(ptr);
//	ptr = NULL;
//}
//
////预加载保存的文件
//void SeqListLoad(SL* p)
//{
//	FILE* ptr = fopen("seqlist.dat", "r");
//	if (ptr == NULL)
//	{
//		perror("SeqlistSave");
//		return;
//	}
//	fread(p, sizeof(SL), 1, ptr);
//	fclose(ptr);
//	ptr = NULL;
//}
