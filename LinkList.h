#ifndef _LINKLIST_H_ //���û������ͷ�ļ�file.h
#define _LINKLIST_H_ //�Ǿ�����ͷ�ļ�file.h

#define TRUE	1
#define FALSE	0
#define  DEBUG_

typedef struct tLinkList
{
	int data;
	tLinkList* next;
}tLinkList;

extern tLinkList * LinkListInit();
extern int LinkListAdd(tLinkList * header,int rank,int num);
extern int LinkListRemove(tLinkList * header, int rank);
extern int LinkListShow(tLinkList * header);
extern int LinkListClear(tLinkList * header);
extern tLinkList * LinkListFind(tLinkList * list, int data);
extern int LinkListDeduplicate(tLinkList * header);

#endif