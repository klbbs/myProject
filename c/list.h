#ifndef _NODE_CHECK_
#define _NODE_CHECK_

typedef struct Node{
	int data;
	struct Node *next;	
}Node;
typedef struct _list{
	Node *head;
}List;
void add(List *plist,int data);
#endif
