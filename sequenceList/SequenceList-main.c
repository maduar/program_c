#include <stdio.h>
#include "SequenceList.c"

Status CmpGreater(LElemType_Sq e, LElemType_Sq data);
void PrintElem(LElemType_Sq e);

int main(int argc, char **argv) {
  SqList L;
  int i, len, value;
  LElemType_Sq e;

  printf("init sequenceList:\n");
  InitList_Sq(&L);

  len = ListLength_Sq(L);
  printf("L.length = %d\n", len);
  ListEmpty_Sq(L) ? printf("L 为空!! \n") : printf("L 不为空!!\n");
  printf("\n\n");

  int aa = 10;
  printf("Insert two elements! \n");
  ListInsert_Sq(&L, 1, 11);
  ListInsert_Sq(&L, 2, aa);
  len = ListLength_Sq(L);
  printf("L.length = %d\n", len);
  ListEmpty_Sq(L) ? printf("L为空!!\n") : printf("L 不为空！！\n");
  value = GetElem_Sq(L, 1, &e);
  printf("L的第1个元素是: %d\n", e);
  value = GetElem_Sq(L, 2, &e);
  printf("L的第2个元素是: %d\n", e);

  i = LocateElem_Sq(L, 10, CmpGreater);
  printf("i = %d\n", i);

  printf("\n\n");
  printf("Get Prior Element !\n");
  PriorElem_Sq(L, 10, &e);
  printf("10的前驱节点是 i = %d\n", e);

  printf("\n\n");
  printf("Get Next Element !\n");
  NextElem_Sq(L, 11, &e);
  printf("11的后继节点是 i = %d\n", e);

  printf("\n\n");
  len = ListLength_Sq(L);
  printf("delete 之前的len = %d\n", len);
  ListDelete_Sq(&L, 2, &e);
  len = ListLength_Sq(L);
  printf("delete 之后的len = %d\n", len);

  printf("\n\n");

  return 0;

}

Status CmpGreater(LElemType_Sq e, LElemType_Sq data)
{
    return data > e ? TRUE : FALSE;
}

