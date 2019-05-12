#include "LinkList.h"
#include <iostream>
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