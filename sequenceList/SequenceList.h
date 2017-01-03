#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct {
  LElemType_Sq *elem;
  int length;
  int listsize;
}SqList;

Status InitList_Sq(SqList *L);

void ClearList_Sql(SqList *L);

void DestroyList_Sq(SqList *L);

Status ListEmpty_Sq(SqList L);


Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);


#endif


