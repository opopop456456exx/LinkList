#ifndef _LINKLIST_H_ //如果没有引入头文件file.h
#define _LINKLIST_H_ //那就引入头文件file.h

#define TRUE	1
#define FALSE	0
#define  DEBUG_

typedef struct tLinkList
{
	int data;
	struct tLinkList *next;
}tLinkList;

typedef struct {
   int val;
   struct MyLinkedList *next;
} MyLinkedList;

extern tLinkList * LinkListInit();
extern int LinkListAdd(tLinkList * header,int rank,int num);
extern int LinkListRemove(tLinkList * header, int rank);
extern int LinkListShow(tLinkList * header);
extern int LinkListClear(tLinkList * header);
extern tLinkList * LinkListFind(tLinkList * list, int data);
extern int LinkListDeduplicate(tLinkList * header);

extern struct tLinkList *reverseList(struct tLinkList *head);
//LeetCode LinkList
// 
extern MyLinkedList* myLinkedListCreate();
extern int myLinkedListGet(MyLinkedList* obj, int index);
extern void myLinkedListAddAtHead(MyLinkedList* obj, int val) ;
extern void myLinkedListAddAtTail(MyLinkedList* obj, int val);
extern void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
extern void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
extern void myLinkedListFree(MyLinkedList* obj);

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

#endif
