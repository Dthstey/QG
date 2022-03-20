#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main() {
	int x;
	LinkedList head;
	LinkedList p;
	//制作菜单
	while (SUCCESS) {
		system("cls");
		printf("----------------------------\n");
		printf("1.初始化链表\n");
		printf("2.创建链表\n");
		printf("3.删除链表\n");
		printf("4.插入结点\n");
		printf("5.删除结点\n");
		printf("5.判断闭环\n");
		printf("6.搜索结点\n");
		printf("7.遍历列表\n");
		printf("8.链表中值\n");
		printf("----------------------------\n");
		printf("输入你的选择：");
		scanf_s("%d", &x);
	}

	switch (x) {
	case 1:head = InitList(head); display(head); break;
	case 2:head = Creat(head); display(head); break;
	case 3:DestroyList(head); display(head); break;
	case 4:head = InsertList(head, p); display(head); break;
	case 5:head = DeleteList(head, p); display(head); break;
	case 6:head = SearchList(head, p); display(head); break;
	case 7:TraverseList(head, p); display(head); break;
	case 8:head = FindMidNode(head); display(head); break;
	default:printf("错误的输入！\n");
	}
	return 0;
}
