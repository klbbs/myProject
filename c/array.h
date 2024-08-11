#ifndef _Array_check_
#define _Array_check_

typedef struct{
	int size;
	int* array;
}Array;

Array array_creat(int int_size);
void array_free(Array *a);
int array_size(const Array *A);
int* array_at(Array *a,int index);
void array_inflate(Array *a,int more_size);


#endif
