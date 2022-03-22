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
        printf(">>> 1.初始化函数           \n");
        printf(">>> 2.创建链表             \n");
        printf(">>> 3.删除链表             \n");
        printf(">>> 4.插入结点             \n");
        printf(">>> 5.删除结点             \n");
        printf(">>> 6.判断闭环             \n");
        printf(">>> 7.搜索结点             \n");
        printf(">>> 8.遍历链表             \n");
        printf(">>> 9.链表中值             \n");
        printf(">>>10.链表反向             \n");
        printf("---------------------------\n");
        printf("请输入你的选择：");
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