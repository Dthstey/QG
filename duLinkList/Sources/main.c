#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

int main()
{
	DuLinkedList L = NULL;
	DuLinkedList p = NULL;
    int x, a;
    while (1)
    {
        system("cls");
        printf("---------------------------\n");
        printf(">>> 1.��ʼ������           \n");
        printf(">>> 2.��������             \n");
        printf(">>> 3.ɾ������             \n");
        printf(">>> 4.ǰ����             \n");
        printf(">>> 5.�����             \n");
        printf(">>> 6.ɾ�����             \n");
        printf(">>> 7.��������             \n");
        printf("---------------------------\n");
        printf("���������ѡ��");
        scanf_s("%d", &x);
        switch (x)
        {
        case 1:
            InitList_DuL(&L);
            system("pause");
            break;
        case 2:
            Create(L);
            system("pause");
            break;
        case 3:
            DestroyList_DuL(&L);
            system("pause");
            break;
        case 4:
            InsertBeforeList_DuL(L, p);
            system("pause");
            break;
        case 5:
            InsertAfterList_DuL(L, p);
            system("pause");
            break;
        case 6:
            DeleteList_DuL(L, &a);
            system("pause");
            break;
        case 7:
            TraverseList_DuL(L, visit);
            system("pause");
            break;
        }
    }
}