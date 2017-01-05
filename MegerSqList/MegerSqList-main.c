#include <stdio.h>
#include "MegerSqList.c"

void PrintElem(LElemType_Sq e);

int main(int argc, char **argv) {
    SqList La, Lb, Lc1, Lc2;

    LElemType_Sq a[5] = {1, 2, 4, 6, 7};
    LElemType_Sq b[6] = {2, 3, 5, 8, 9, 10};
    int i;

    InitList_Sq(&La);
    for(i = 1; i <= 5; i++)
        ListInsert_Sq(&La, i, a[i -1]);

    InitList_Sq(&Lb);
    for(i = 1; i <= 6; i++)
        ListInsert_Sq(&Lb, i, b[i -1]);

    printf("\n\n");

    ListTraverse_Sq(La, PrintElem);

    printf("\n\n");

    ListTraverse_Sq(Lb, PrintElem);

    printf("\n\n");
    MergerSqList_1(La, Lb, &Lc1);
    ListTraverse_Sq(Lc1, PrintElem);
    printf("\n\n");

}



void PrintElem(LElemType_Sq e) {
    printf("%d ", e);
}
