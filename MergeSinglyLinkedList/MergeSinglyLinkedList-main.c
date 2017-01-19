#include <stdio.h>
#include "MergeSinglyLinkedList.c"


void PrintElem(LElemType_L e);

int main(int argc, char **argv) {
    FILE *fp;
    LinkList La, Lb, Lc;
    int m;

    m = 5;

    fp = fopen("../SinglyLinkedList/TestData_HL.txt", "r");
    CreateList_HL(fp, &La, m);
    fclose(fp);
    fp = fopen("../SinglyLinkedList/TestData_TL.txt", "r");
    CreateList_TL(fp, &Lb, m);
    fclose(fp);

    MergeList_L(La, &Lb, &Lc);
    ListTraverse_L(Lc, PrintElem);
    printf("\n\n");

    return 0;
}



void PrintElem(LElemType_L e) {
    printf("%d ", e);
}