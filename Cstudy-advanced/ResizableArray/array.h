#ifndef _ARRAY_H  // if n def 注意别忘了中间的n
#define _ARRAY_H

typedef struct {
    int *array;
    int size;
} Array;  // 申明新类型Array，一种包含一个整数指针和一个整数的数据结构

Array array_create(int init_size);
void array_free(Array *parr);
int array_size(Array *parr);
int* array_at(Array *parr, int index);
void array_inflate(Array *parr, int more_size);


#endif