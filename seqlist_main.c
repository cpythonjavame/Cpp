#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"


int main()
{
	SL s;
	IniSL(&s);
	int num = 0;
	SLdatatype x = 0;
	int i = 0;
	int flag = 0;
	/*int m = 0;*/
	while (1)
	{
		menu();
		printf("���������ѡ��\n");
		scanf("%d", &num);
		switch (num)
		{
			case 0:
				/*printf("**************************\n");
				printf("****���뱣���ϴεļ�¼��****\n");
				printf("****0.����     1.������****\n");
				printf("**************************\n");
				scanf("%d", &m);
				if(m==0)
					SeqlistSave(&s);
				else if(m==1)*/
				printf("�˳�����\n");
				SeqListDestroy(&s);
				exit(0);
			case 1:
				printf("��������������Ԫ��\n");
				scanf("%d", &x);
				SeqlistPushFront(&s, x);
				break;
			case 2:
				printf("��������������Ԫ��\n");
				scanf("%d", &x);
				SeqlistPushBack(&s, x);
				break;
			case 3:
				SeqlistpophFront(&s);
				break;
			case 4:
				SeqlistpophBack(&s);
				break;
			case 5:
				printf("��������������Ԫ��\n");
				scanf("%d", &x);
				printf("��������������λ��\n");
				scanf("%d", &i);
				SeqListinsert(&s, i, x);
				break;
			case 6:
				printf("����������ɾ����λ��\n");
				scanf("%d", &i);
				SeqListerase(&s, i);
				break;
			case 7:
				printf("������������ҵ�Ԫ��\n");
				scanf("%d", &x);
				flag = SeqListFind(&s, x);
				if (flag == -1)
				{
					printf("��Ԫ�ز�����\n");
				}
				else
				{
					printf("%d\n", flag);
				}
				break;
			case 8:
				SeqListprint(&s);
				break;
			default:
				printf("���ѡ������������ѡ��\n");
				break;
		}
	}
	return 0;
}