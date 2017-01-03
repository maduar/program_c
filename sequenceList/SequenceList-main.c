#include <stdio.h>
#include "SequenceList.c"

Status ComGreater(LElemType_Sq e, LElemType_Sq data);
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

//  L.length = 10;
  int aa = 10;
  ListInsert_Sq(&L, 1, aa);
  len = ListLength_Sq(L);
  printf("L.length = %d\n", len);
  ListEmpty_Sq(L) ? printf("L为空!!\n") : printf("L 不为空！！\n");
  value = GetElem_Sq(L, 1, &e);
  printf("L的第1个元素是: %d\n", e);



}
