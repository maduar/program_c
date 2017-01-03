#include <stdio.h>
#include "SequenceList.c"

Status ComGreater(LElemType_Sq e, LElemType_Sq data);
void PrintElem(LElemType_Sq e);

int main(int argc, char **argv) {
  SqList L;
  int i;
  LElemType_Sq e;

  printf("init sequenceList:\n");
  InitList_Sq(&L);
  printf("\n");
  ListEmpty_Sq(L) ? printf("L 为空!! \n") : printf("L 不为空!!\n");

  ListInsert_Sq(&L, 1, 2);

  ListEmpty_Sq(L) ? printf("L为空!!\n") : printf("L 不为空！！\n");

}
