#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

Status InitList_Sq(SqList *L)
{
  (*L).elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
  if(!(*L).elem)
    exit(OVERFLOW);

  (*L).length = 0;
  (*L).listsize = LIST_INIT_SIZE;

  return OK;
}

void ClearList_Sq(SqList *L) {
  (*L).length = 0;
}

void DestroyList_Sq(SqList *L) {
  free((*L).elem);

  (*L).elem = NULL;
  (*L).length = 0;
  (*L).listsize = 0;

}

Status ListEmpty_Sq(SqList L) 
{
  return L.length == 0 ? TRUE : FALSE;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
    if(i<1 || i>L.length)
        return ERROR;
    else
        *e = L.elem[i-1];

    return *e;
}


Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
  LElemType_Sq *newbase;
  LElemType_Sq *p, *q;
  
  if(i<1 || i>(*L).length + 1) 
    return ERROR;

  if((*L).length >= (*L).listsize) {
    newbase = (LElemType_Sq*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT)
        *sizeof(LElemType_Sq));
   if(!newbase)
    exit(OVERFLOW);
    

   (*L).elem = newbase;
   (*L).listsize += LISTINCREMENT;
  }


  q = &(*L).elem[i-1];

  for(p=&(*L).elem[(*L).length-1]; p>=q; --p)
    *(p+1) = *p;

  *q = e;
  (*L).length++;

  return OK;

}

#endif
