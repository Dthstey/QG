/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	Task
 *	SYSTEM					:   win10
 *	Create Data				:	2021.3.21
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
Status InitList(LinkedList*L) {
	*L = (LinkedList)malloc(sizeof(LNode));//开辟结点
	if (*L == NULL) {
		printf("初始化失败！\n");
		return ERROR;
	}
	(*L)->data = 0;
	(*L)->next = NULL;
	printf("初始化成功！\n");
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p,temp = *L;
	//循环控制删除结点
	while (temp!=0) {
		p = temp->next;
		free(temp);
		temp = p;
	}
	*L = NULL;
	printf("成功删除链表！\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) {
	
	int insert, i;
	printf("请输入要插入的节点位置:");
	scanf_s("%d", &insert);
	//找到要插入的位置
	for (i = 1; i <= insert; i++) {
		if (p == NULL) {
			printf("插入位置错误！\n");
			return ERROR;
		}
		p = p->next;
	}
	q = (LNode*)malloc(sizeof(LNode));//创建需要插入的节点
	q->data = 0;
	q->next = p->next;//插入结点
	p->next = q;
	printf("插入成功！\n");
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e) {
	LNode* q;
	int n, i;
	printf("请输入要删除结点的前一个结点p的位置:");
	scanf_s("%d", &n);
	if (p == NULL||p->next==NULL) {
		printf("输入位置错误！\n");
		return ERROR;
	}
	for (i = 1; i <= n; i++) {
		p = p->next;
	}
	q = p;
	p = p->next;
	q->next = p->next;
	*e = p->data;
	free(p);
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
	if (L==NULL||L->next == NULL) {
		printf("链表不存在！");
		return ERROR;
	}
	LinkedList p = L->next;
	printf("以下是该链表的输出结果:\n");
	while (p) {
		visit(p->data);
		p = p->next;
	}
}
void visit(ElemType e)
{
	printf("%d,", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if (L == NULL || L->next == NULL) {
		printf("错误的链表！\n");
		return ERROR;
	}
	LinkedList p = L->next;//设立头指针
	printf("请输入你想搜索的结点：");
	scanf_s("%d", &e);
	//找到要搜索的位置
	for (int i = 1; i < e; i++) {
		p = p->next;
	}
	printf("该结点数值为：%d", p->data);
	return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if ((*L) == NULL || (*L)->next == NULL) {
		printf("错误的链表！\n");
		return ERROR;//判断是否为空结点
	}
	LinkedList p = (*L)->next;
	LinkedList end = (*L)->next;
	while ((end->next) != NULL) {
		end = end->next;
	}
	while (p != end) {
		(*L)->next = p->next;
		p->next = end->next;
		end->next = p;
		p = (*L)->next;
	}
	printf("反转成功！\n");
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
		printf("错误的链表！\n");
		return ERROR;//判断是否为空结点
	}
	LinkedList slow = L->next;
	LinkedList quick = L->next->next;
	while (1) {
		if (!quick || !quick->next) {
			printf("不闭环\n");
			return ERROR;
		}
		else if (quick == slow || quick->next == slow) {
			printf("闭环\n");
			return SUCCESS;
		}
		else {
			quick = quick->next->next;
			slow = slow->next;
		}
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
/*
LNode* ReverseEvenList(LinkedList L) {
	if (L == NULL || L->next == NULL) {
		printf("错误的链表！\n");
		return L;//判断是否为空结点
	}
	if (L->next->next == NULL) {
		printf("%d", L->next->data);
		return L;
	}
	LinkedList p1 = L->next;
	LinkedList p2 = L->next->next;
	p2->next = p1;
	p1 = p1->next->next;
}*/

	

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
		if ((*L) == NULL || (*L)->next == NULL) {
			printf("错误的链表！\n");
			return ERROR;//判断是否为空结点
		}
		int i, count = 0;
		LinkedList p1 = (*L)->next;
		LinkedList p2 = (*L)->next;
		//统计结点总数
		while (p1){
			count++;
			p1 = p1->next;
		}
		//如果是偶数
		if (count % 2 == 0) {
			for (i=1; i < count / 2; i++)
				p2 = p2->next;
			printf("%d %d", p2->data, p2->next->data);
		}
		//如果是奇数
		else {
			for (i=1; i < (count + 1) / 2; i++)
				p2 = p2->next;
			printf("%d", p2->data);
		}
		return *L;
	}

/**
*  @name        : void Creat(LinkedList L)
*  @description : Create a linked list
*  @param		: L(the head node)
*  @return		: L
*  @notice      : None
*/
void Create(LinkedList L) {
		LinkedList p1;
		int x, i;
		if (L == NULL) {
			printf("链表不存在！");
			return ERROR;
		}
		printf("请输入你想建立的结点数量：");
		scanf_s("%d", &x);
		for (i = 1; i <= x; i++) {
			p1 = (LinkedList)malloc(sizeof(LNode));
			if (p1 != NULL) {
				L->next = p1;
				p1->data = i;
				L = p1;
				if (i == x) {
					p1->next = NULL;
				}
			}
		}
		printf("成功创建链表！\n");
	}
/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
