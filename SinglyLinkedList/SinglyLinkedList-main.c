#include <stdio.h>
#include "SinglyLinkedList.c"

Status CmpGreater(LElemType_L e, LElemType_L data);
void PrintElem(LElemType_L e);

int main(int argc, char **argv)
{
    LinkList L;
    int i;
    LElemType_L e;

    printf("测试开始： -------\n");
    InitList_L(&L);

    ListEmpty_L(L) ? printf("L 为空 !!\n") : printf("L 不为空!!\n");

    return 0;
}