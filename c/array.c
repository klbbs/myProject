#include "array.h"
#include <stdio.h>
#include <stdlib.h>

const int BLOCK = 20;
//链表的创建函数实现 
Array array_creat(int int_size){
	Array a;
	a.size = int_size;
	a.array = (int*)malloc(sizeof(int)*int_size);
	return a;
}
void array_free(Array *a){
	free(a->array);
	a->array = NULL;
	a->size = 0;
}
int array_size(const Array *a){
	return a->size;
}
int* array_at(Array *a,int index){
	if (index > a->size){
		
		array_inflate(a,(index/BLOCK+1)*BLOCK - a->size);
		printf("越界！已自动%d个增长block（20）\n",(index-a->size)/BLOCK+1);
	}
	return &(a->array[index]);
}
void array_inflate(Array *a,int more_size){
	int *p;
	p = (int*)malloc(sizeof(int)*(more_size+a->size));
	int i;
	for(i = 0;i<a->size;i++){
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
}


int main(int argc,char const *argv[]){
	Array a = array_creat(5);
	printf("array_size=%d\n",array_size(&a));
	*array_at(&a,0) = 10;
	printf("position0=%d\n",*array_at(&a,0));
	int number = 0;
	int cnt = 0;
	while(number != -1){
		scanf("%d",&number);
		if(number != -1){
			*array_at(&a,cnt++) = number;
		}
	
	}
	
	
	array_free(&a);
	
	
	return 0;
}
