#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main()
{
    LinkedList L=NULL; // Head of LinkedList.
    LinkedList p=NULL;
    int x, a;
    ElemType b;
    while (1)
    {
        system("cls");
        printf("---------------------------\n");
        printf(">>> 1.��ʼ������           \n");
        printf(">>> 2.��������             \n");
        printf(">>> 3.ɾ������             \n");
        printf(">>> 4.������             \n");
        printf(">>> 5.ɾ�����             \n");
        printf(">>> 6.�жϱջ�             \n");
        printf(">>> 7.�������             \n");
        printf(">>> 8.��������             \n");
        printf(">>> 9.������ֵ             \n");
        printf(">>>10.������             \n");
        printf("---------------------------\n");
        printf("���������ѡ��");
        scanf_s("%d", &x);
        switch (x)
        {
        case 1:
            InitList(&L);
            system("pause");
            break;
        case 2:
            Create(L);
            system("pause");
            break;
        case 3:
            DestroyList(&L);
            system("pause");
            break;
        case 4:
            InsertList(L, p);
            system("pause");
            break;
        case 5:
            DeleteList(L, &a);
            system("pause");
            break;
        case 6:
            IsLoopList(L);
            system("pause");
            break;
        case 7:
            SearchList(&L, &b);
            system("pause");
            break;
        case 8:
            TraverseList(L, visit);
            system("pause");
            break;
        case 9:
            FindMidNode(&L);
            system("pause");
            break;
        case 10:
            ReverseList(&L);
            system("pause");
            break;
        }
    }
}