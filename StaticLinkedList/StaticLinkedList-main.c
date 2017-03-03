#include <stdio.h>
#include "StaticLinkedList.c"

void PrintElem(LElemType_S e);

int main(int argc, char **argv) {
    SLinkList H;
    LElemType_S E;
    int i, sign;

    InitSpace_SL();
    InitList_SL(&H);

    ListEmpty_SL(H) ? printf("H 为空\n") : printf("H 不为空\n");
    i = ListLength_SL(H);
    printf("i = %d \n", i);


    sign = ListInsert_SL(H, 1, 12);
    printf("sign = %d \n", sign);

    i = ListLength_SL(H);
    printf("i = %d \n", SPACE[H].cur);

    ListTraverse_SL(H, PrintElem);

    return 0;
}

void PrintElem(LElemType_S e) {
    printf("%d ", e);
}