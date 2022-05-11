#pragma once
#include <stdio.h>
#include <stdlib.h>

#define SLdatatype int

typedef struct SeqList
{
	SLdatatype* a;
	size_t size;
	size_t capacity;
}SL;

void IniSL(SL* p);
void SeqlistPushBack(SL* p, SLdatatype x);
void SeqlistpophBack(SL* p);
void SeqlistPushFront(SL* p, SLdatatype x);
void SeqlistpophFront(SL* p);
void SeqListDestroy(SL* p);
void SeqListprint(SL* p);
int SeqListFind(SL* p, SLdatatype x);
void SeqListinsert(SL* p, int pos, SLdatatype x);
void SeqListerase(SL* p, int pos);
void menu();
//void SeqlistSave(SL* p);
//void SeqListLoad(SL* p);