#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
};

#define DEFAULT_SIZE    10

/* 指针判空函数 */
#define CHECK_PTR(ptr)      \
do{                         \
    if(!ptr){               \
        return NULL_PTR;    \
    }                       \
}while(0);


int dynamicArrayInit(dynamicArray * pArray, int capacity)
{
    /* 指针判空 */
    CHECK_PTR(pArray);

    /* 避免非法数值 */
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }

    pArray->data = malloc(sizeof(ELEMENTYP) * capacity);
    if(!pArray->data)
    {
        return MALLOC_ERROR;
    }

    /* 给结构体属性赋初值 */
    pArray->capacity = capacity;
    pArray->len = 0;

    return ON_SUCCESS;
}

