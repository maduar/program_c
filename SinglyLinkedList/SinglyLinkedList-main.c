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
    int a = ListLength_L(L);
    printf("a = %d\n", a);

    ListInert_L(L, 1, 21);
    ListInert_L(L, 2, 22);

    getElem_L(L, 1, &e);
    printf("e = %d\n", e);

    i = LocateElem_L(L, 7, CmpGreater);
    printf("%d \n", i);

    PriorElem_L(L, 22, &e);
    printf("%d \n", e);

    NextElem_L(L, 21, &e);
    printf("%d \n", e);

    a = ListLength_L(L);
    printf("L.length = %d\n", a);

    printf("---------\n");
    ListTraverse_L(L, PrintElem);
    printf("\n");
    printf("---------\n");
    ListDelete_L(L, 1, &e);

    a = ListLength_L(L);
    printf("L.length = %d, e = %d\n", a, e);

//    CreateList_HL
    FILE *fp;
    LinkList H;
    printf("头插法建立单链表 H = ");
    fp = fopen("TestData_HL.txt", "r");
    CreateList_HL(fp, &H, 5);
    fclose(fp);
    ListTraverse_L(H, PrintElem);
    printf("\n\n");

//    FILE *fp;
    LinkList HHH;
    printf("尾插法建立单链表 HHH = ");
    fp = fopen("TestData_HL.txt", "r");
    CreateList_TL(fp, &HHH, 5);
    fclose(fp);
    ListTraverse_L(HHH, PrintElem);
    printf("\n\n");
    return 0;
}

Status CmpGreater(LElemType_L e, LElemType_L data) {
    return data > e ? TRUE : FALSE;
}

void PrintElem(LElemType_L e) {
    printf("%d ", e);
}