/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2022 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2021.3.20
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"linklist.h"

 /**
  *  @name        : Status InitList(LinkList L);
  *	@description : initialize an empty linked list with only the head node without value
  *	@param		 : L(the head node)
  *	@return		 : Status
  *  @notice      : None
  */
Status InitList(LinkedList L) {
	if (L != NULL)
		return ERROR;
	L = (LinkedList)malloc(sizeof(LNode));//���ٽ��
	if (L == NULL)
		return ERROR;
	printf("��ʼ���ɹ���\n");
	L->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList L) {
	LinkedList temp = L;
	//ѭ������ɾ�����
	while (temp) {
		temp = temp->next;
		free(L);
		L = temp;
	}
	printf("�ɹ�ɾ������\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) {
	
	int insert;
	printf("������Ҫ����Ľڵ�λ��:");
	scanf_s("%d", &insert);
	//�ҵ�Ҫ�����λ��
	for (int i = 1; i < insert; i++) {
		if (p == NULL) {
			printf("����λ�ô���\n");
			return ERROR;
		}
		p = p->next;
	}
	q = (LNode*)malloc(sizeof(LNode));//������Ҫ����Ľڵ�
	q->data = NULL;
	q->next = p->next;//������
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, int* e) {
	LNode* p1 = p->next;
	*e = p1->data;
	p1->next = p->next->next;//�����ý��
	free(p1);//�ͷŸý����ռ�ڴ�
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p = L;//����ͷָ��
	printf("�����Ǹ������������:/n");
	if (p != NULL)
		do {
			visit(p->data);
			p = p->next;
		} while (p != NULL);
}
void visit(ElemType e)
{
	printf("%d->", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, int e) {
	LinkedList p = L;//����ͷָ��
	printf("���������������Ľ�㣺");
	scanf_s("%d", &e);
	//�ҵ�Ҫ�����λ��
	for (int i = 1; i < e; i++) {
		if (p == NULL) {
			printf("����λ�ô���\n");
			return ERROR;
		}
		p = p->next;
	}
	printf("�ý����ֵΪ��%d", p->data);
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList L) {
	if (L == NULL)
		return ERROR;

	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if (L == NULL || L->next == NULL) {
		return ERROR;//�ж��Ƿ�Ϊ�ս��
	}
	LinkedList slow = L->next,quick = L->next->next;
	while (quick != NULL && quick->next != NULL) {
		if (quick == slow) {
			quick = L;
			while (slow != quick) {
				slow = slow->next;
				quick = quick->next;
			}
			return SUCCESS;
		}
		quick = quick->next->next;
		slow = slow->next;
	}
	return SUCCESS;

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
/*	LinkedList p1 = L;
	if (p1 == NULL||p1->next==NULL)
		return ERROR;
	while (p1)
	{
		if (p1)
	}
*/	
	

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
	LNode* FindMidNode(LinkedList L) {
		int i, count = 0;
		LinkedList p1 = L;
		LinkedList p2 = L;
		while (p1)
		{
			count++;
			p1 = p1->next;
		}
		//�����ż��
		if (count % 2 == 0) {
			for (; i < count / 2; i++)
				p2 = p2->next;
			printf("%d %d", p2->data, p2->next->data);
		}
		//���������
		else {
			for (; i < (count + 1) / 2; i++)
				p2 = p2->next;
			printf("%d", p2->data);
		}
		return L;
	}

/**
*  @name        : void* Creat()
*  @description : Create a linked list
*  @param		 : L(the head node)
*  @return		 : None
*  @notice      : None
*/
	void* Creat(LinkedList L) {
		LinkedList p1 = L;
		LinkedList p2;
		int x, i;
		p1 = (LinkedList)malloc(sizeof(LNode));
		printf("���������뽨���Ľ��������");
		scanf_s("%d", &x);
		//ѭ��������Ӧ����
		for (i = 1; i < x; i++) {
			p2 = (LinkedList)malloc(sizeof(LNode));
			p2->data = i;
			p1->next = p2;
			p1 = p2;
			p2 = p2->next;
		}
		printf("�ɹ���������\n");
		p1->next = NULL;
	}
/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
