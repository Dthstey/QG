#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main() {
	int x;
	LinkedList head;
	LinkedList p;
	//�����˵�
	while (SUCCESS) {
		system("cls");
		printf("----------------------------\n");
		printf("1.��ʼ������\n");
		printf("2.��������\n");
		printf("3.ɾ������\n");
		printf("4.������\n");
		printf("5.ɾ�����\n");
		printf("5.�жϱջ�\n");
		printf("6.�������\n");
		printf("7.�����б�\n");
		printf("8.������ֵ\n");
		printf("----------------------------\n");
		printf("�������ѡ��");
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
	default:printf("��������룡\n");
	}
	return 0;
}
