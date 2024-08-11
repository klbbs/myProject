#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
	Node *head = NULL;
	int number = 0;
	do{
		scanf("%d",&number);
		if(number != -1){
			Node *p = (Node*)malloc(sizeof(Node));
			p->data = number;
			p->next = NULL;
			Node *last = head;
			if(last){
				while(last->next){
					last = last->next;
				}
				last->next = p;
			}else{
				head = p;
			}
		}
	}while(number != -1);
	Node *c = head;
	while(c){
		printf("%d\n",c->data);
		c = c->next;
	}
	return 0;
}
