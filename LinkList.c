#include "LinkList.h"
//#include <iostream>
#include "stdio.h"
#include<stdlib.h>
/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/12
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
 
tLinkList * LinkListInit()
{
	tLinkList * header;

	header = (tLinkList *)malloc(sizeof(tLinkList));
	if (header == NULL)
	{
		printf("\r\nLinkListInit malloc fail!");
		return NULL;
	}
	header->data = 0;
	header->next = NULL;
	return header;
}



/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/12
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
 
int LinkListAdd(tLinkList * header, int rank, int num) 
{
	int i;
	tLinkList * p,*pa;

	p = header;
	i = 0;

	while ((p != NULL)&&(i<rank-1))
	{
		p = p->next;
		i++;
	}
	if ((p == NULL) || (i > rank - 1) || (rank == 0))
	{
		printf("\r\n Unright list!");
		return FALSE;
	}

	pa = (tLinkList *)malloc(sizeof(tLinkList));
	pa->data = num;
	pa->next = p->next;
	p->next = pa;

	return TRUE;
}


/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/12
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int LinkListRemove(tLinkList * header, int rank)
{
	int i;
	tLinkList * p,*pa;

	p = header;
	i = 0;
	while ((p != NULL) && (i < rank - 1))
	{
		p = p->next;
		i++;
	}
	if ((p == NULL) || (i > rank - 1) || (rank == 0))
	{
		printf("\r\n Unright list!");
		return FALSE;
	}

	pa = p->next;
	printf("\r\n the remove list num:%d!",pa->data);
	p->next = pa->next;

	free(pa);
	return TRUE;
}

/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/12
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int LinkListShow(tLinkList * header)
{
	int i;
	tLinkList * p;

	p = header;
	i = 1;

	if (p == NULL)
	{
		printf("\r\n Unright list!");
		return FALSE;
	}

	printf("\r\n****** List Show ******");
	p = p->next;
	while ( p != NULL)
	{
		printf("\r\n %4d  %4d", i, p->data);
		p = p->next;
		i++;
	}

	printf("\r\n****** End ******");
	return TRUE;
}



/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/18
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int LinkListClear(tLinkList * header)
{
	tLinkList * p,*temp;

	if (header == NULL)
	{
		return FALSE;
	}
	p = header;

	while (p->next != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}

	if (p == NULL)
	{
		free(p);
	}

	return TRUE;

}



/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/18
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
tLinkList *  LinkListFind(tLinkList * list,int data)
{
	tLinkList * p;

	if ((list == NULL))
	{
		return NULL;
	}
	p = list;
	while (p !=NULL)
	{
		if (p->data == data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;

}

/************************************************************************/
/* Author   : DingFeng                     
/* Data     : 2019/05/18
/* Fuction	:
/* Remarks	:
/* Others	:
/************************************************************************/
int LinkListDeduplicate(tLinkList * header)
{
	tLinkList * p, *pa,*temp;

	if ((header == NULL)||(header->next == NULL))
	{
		return FALSE;
	}
	p = header->next;

	while (p != NULL)
	{
		temp = header;
		pa = header->next;
		while (pa != p)
		{
			if (pa->data == p->data)
			{
				temp->next = pa->next;
				printf("\r\n		rm pa%d",pa->data);
				free(pa);
				break;
			}
			temp = pa;
			pa = pa->next;

		}
		p = p->next;
	}

	return TRUE;
}

struct tLinkList *reverseList(struct tLinkList * head)
{
	tLinkList *newhead, *p,*tmp;
	if(NULL == head)	
	{
		printf("\r\n Err head!");
		return NULL;
	}
	newhead=head;
	p=head->next;
	while(p != NULL)
	{
		head->next=p->next;
		p->next=newhead;
		newhead=p;
		p=head->next;
	}

	return newhead;

}

//dddddddZZZZ
//

//LeetCode LinkList

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {

	MyLinkedList *header;
	header = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	if(NULL == header)
	{
		printf("\r\nLinkInit Fail!");
		return NULL;
	}
	header->val=0;
	header->next=NULL;	
	return header;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
	int i;
	MyLinkedList* header, *p;
	header=obj;
	if((index < 0)||(NULL == header->next))
	{
		printf("\r\nInvalid idx or obj!");
		return -1;
	}
	p=header->next;
	i=0;
	while(i<index)
	{
		if(NULL != p->next)
		{
			p=p->next;
		}
		else
		{
			return -1;
		}

		i++;
	}

	return p->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  	int i;
	MyLinkedList* header, *p;
	header=obj;
	if(NULL == header)
	{
		printf("\r\n err obj");
		return;
	}

	p = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	if(NULL == p)
	{
		printf("\r\nAddHead malloc Fail!");
		return ;
	}

	p->next = header->next;
	p->val= val;
	header->next = p;
	return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  	int i;
	MyLinkedList* header, *p,*q;
	header=obj;
	if(NULL == header)
	{
		printf("\r\n err obj");
		return;
	}

	q=header;
	p = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	if(NULL == p)
	{
		printf("\r\nAddTail molloc Fail!");
		return ;
	}
	
	p->val=val;
	p->next=NULL;
	while(NULL != q->next)
	{
		q=q->next;
	}

	q->next =p;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  	int i;
	MyLinkedList* header, *p,*q;
	header=obj;
	if((index < 0)||(NULL == header))
	{
		printf("\r\nInvalid idx or obj!");
		return ;
	}

	q = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	if(NULL == q)
	{
		printf("\r\nAddIdx molloc Fail!");
		return ;
	}
	
	q->val=val;

	p=header;
	i=0;
	while(i<index)
	{
	
		p=p->next;
		if(p == NULL)
		{
			return;
		}
	
		i++;
	}

	q->next=p->next;
	p->next =q;
	return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  	int i;
	MyLinkedList* header, *p,*q;
	header=obj;
	if((index < 0)||(NULL == header))
	{
		printf("\r\nInvalid idx or obj!");
		return;
	}

	p=header;
	i=0;
	while(i<index)
	{
		if(NULL == p)
		{
			return;
		}
		p=p->next;

		i++;
	}
	if(NULL == p->next)
	{
		return;
	}
	q=p->next;
	p->next=q->next;
	free(q);
	return;
}

void myLinkedListFree(MyLinkedList* obj) {
   
	MyLinkedList* header, *p,*q;
	header=obj;
	if(NULL == header)
	{
		printf("\r\nInvalid idx or obj!");
		return;
	}
	p=header;
	while(NULL != p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
