/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2022 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2022.3.22
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
#include"duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
	*L = (DuLinkedList)malloc(sizeof(DuLNode));//开辟结点
	if (*L == NULL) {
		printf("初始化失败！\n");
		return ERROR;
	}
	(*L)->prior = NULL;
	(*L)->data = 0;
	(*L)->next = NULL;
	printf("初始化成功！\n");
	return SUCCESS;
}


/**
*  @name        : void Creat(LinkedList L)
*  @description : Create a linked list
*  @param		: L(the head node)
*  @return		: L
*  @notice      : None
*/
void Create(DuLinkedList L) 
{
	DuLinkedList p1;
	int x, i;
	if (L == NULL) {
		printf("链表不存在！");
		return ERROR;
	}
	printf("请输入你想建立的结点数量：");
	scanf_s("%d", &x);
	for (i = 1; i <= x; i++) {
		p1 = (DuLinkedList)malloc(sizeof(DuLNode));
		if (p1 != NULL) {
			L->next = p1;
			p1->prior = L;
			p1->data = i;
			L = p1;
			if (i == x) {
				p1->next = NULL;
			}
		}
	}
	printf("成功创建链表！\n");
}


/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L)
{
	if ((*L) == NULL || (*L)->next == NULL) 
	{
		printf("链表不存在！");
		return ERROR;
	}
	DuLinkedList p, temp = *L;
	while (temp!= 0) {
		p = temp->next;
		free(temp);
		temp = p;
	}
	*L = NULL;
	printf("成功删除链表！\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	int insert, i;
	printf("请输入要插入的节点的后一个位置:");
	scanf_s("%d", &insert);
	//找到要插入的位置
	for (i = 1; i < insert; i++) {
		if (p == NULL) {
			printf("插入位置错误！\n");
			return ERROR;
		}
		p = p->next;
	}
	q = (DuLNode*)malloc(sizeof(DuLNode));//创建需要插入的节点
	q->data = 0;
	q->next = p->next;//插入结点
	q->next->prior = q;
	q->prior = p;
	p->next = q;
	printf("插入成功！\n");
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	int insert, i;
	printf("请输入要插入的节点的前一个位置:");
	scanf_s("%d", &insert);
	//找到要插入的位置
	for (i = 1; i <= insert; i++) {
		if (p == NULL) {
			printf("插入位置错误！\n");
			return ERROR;
		}
		p = p->next;
	}
	q = (DuLNode*)malloc(sizeof(DuLNode));//创建需要插入的节点
	q->data = 0;
	q->next = p->next;//插入结点
	q->next->prior = q;
	q->prior = p;
	p->next = q;
	printf("插入成功！\n");
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	DuLNode* q;
	int n, i;
	printf("请输入要删除结点的前一个结点p的位置:");
	scanf_s("%d", &n);
	if (p == NULL || p->next == NULL) {
		printf("输入位置错误！\n");
		return ERROR;
	}
	for (i = 1; i <= n; i++) {
		p = p->next;
	}
	q = p;
	p = p->next;
	q->next = p->next;
	p->next->prior = q->next;
	*e = p->data;
	free(p);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	{
		if (L == NULL || L->next == NULL) {
			printf("链表不存在！");
			return ERROR;
		}
		DuLinkedList p = L->next;
		printf("以下是该链表的输出结果:\n");
		while (p) {
			visit(p->data);
			p = p->next;
		}
	}
}
void visit(ElemType e)
{
	printf("%d,", e);
}



/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/