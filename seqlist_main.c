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
		printf("请输入你的选择：\n");
		scanf("%d", &num);
		switch (num)
		{
			case 0:
				/*printf("**************************\n");
				printf("****你想保存上次的记录吗****\n");
				printf("****0.保存     1.不保存****\n");
				printf("**************************\n");
				scanf("%d", &m);
				if(m==0)
					SeqlistSave(&s);
				else if(m==1)*/
				printf("退出操作\n");
				SeqListDestroy(&s);
				exit(0);
			case 1:
				printf("请输入你想插入的元素\n");
				scanf("%d", &x);
				SeqlistPushFront(&s, x);
				break;
			case 2:
				printf("请输入你想插入的元素\n");
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
				printf("请输入你想插入的元素\n");
				scanf("%d", &x);
				printf("请输入你想插入的位置\n");
				scanf("%d", &i);
				SeqListinsert(&s, i, x);
				break;
			case 6:
				printf("请输入你想删除的位置\n");
				scanf("%d", &i);
				SeqListerase(&s, i);
				break;
			case 7:
				printf("请输入你想查找的元素\n");
				scanf("%d", &x);
				flag = SeqListFind(&s, x);
				if (flag == -1)
				{
					printf("该元素不存在\n");
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
				printf("你的选择有误，请重新选择\n");
				break;
		}
	}
	return 0;
}