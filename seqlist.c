#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"


void menu()
{
	printf("**************************\n");
	printf("*********  0.�˳�  ********\n");
	printf("***1.ͷ��         2.β��***\n");
	printf("***3.ͷɾ         4.βɾ***\n");
	printf("***   5.��ָ��λ�ò���   ***\n");
	printf("***   6.��ָ��λ��ɾ��   ***\n");
	printf("***   7.����Ԫ�ص��±�   ***\n");
	printf("***     8.��ӡ����      ***\n");
	printf("**************************\n");
}

//��ʼ��˳���
void IniSL(SL* p)
{
	p -> a = NULL;
	p -> size = 0;
	p -> capacity = 0;
	/*SeqListLoad(p);*/
}

//��ӡ����
void SeqListprint(SL* p)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("\n");
}

//β��
void SeqlistPushBack(SL* p, SLdatatype x)
{
	//û�пռ��ռ䲻��
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

//βɾ
void SeqlistpophBack(SL* p)
{
	p->size = p->size > 0 ? p->size - 1 : 0;
}

//ͷ��
void SeqlistPushFront(SL* p, SLdatatype x)
{
	//û�пռ��ռ䲻��
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

//ͷɾ
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

//�ҵ�Ԫ�ط����±�
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

//ָ��λ�ò���
void SeqListinsert(SL* p, int pos, SLdatatype x)
{
	if (pos<0 || pos>p->size)
	{
		printf("����λ�ô���\n");
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

//ָ��λ��ɾ��
void SeqListerase(SL* p, int pos)
{
	if (pos<0 || pos>p->size)
	{
		printf("����λ�ô���\n");
		return;
	}
	int i = 0;
	for (i = pos; i < p->size-1; i++)
	{
		p->a[i] = p->a[i + 1];
	}
	p->size--;
}
//����˳���
void SeqListDestroy(SL* p)
{
	free(p->a);
	p->a = NULL;
	p->capacity = p->size = 0;
}




//����̬�ڴ������ᱻϵͳ�Զ��ͷţ����ܱ���...........
////���浽����
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
////Ԥ���ر�����ļ�
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
