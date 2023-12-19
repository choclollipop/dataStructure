#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ILLEGAL_DATA,
};

#define DEFAULT_SIZE    10

/* 指针判空函数 */
#define CHECK_PTR(ptr)      \
do{                         \
    if(!ptr){               \
        return NULL_PTR;    \
    }                       \
}while(0);

#define CHECK_MALLOC(ptr)        \
do{                              \
    if(!ptr){                    \
        return MALLOC_ERROR;     \
    }                            \
}while(0);


/* 前置声明 */
static int dynamicArrayExpand(dynamicArray * pArray);

int dynamicArrayInit(dynamicArray * pArray, int capacity)
{
    /* 指针判空 */
    CHECK_PTR(pArray);

    /* 避免非法数值 */
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }

    pArray->data = (ELEMENTYP *)malloc(sizeof(ELEMENTYP) * capacity);
    CHECK_MALLOC(pArray->data);

    /* 分配空间初始化 */
    memset(pArray->data, 0, sizeof(ELEMENTYP) * capacity);

    /* 给结构体属性赋初值 */
    pArray->capacity = capacity;
    pArray->len = 0;

    return ON_SUCCESS;
}

/* 动态数组扩容 */
static int dynamicArrayExpand(dynamicArray * pArray)
{
    ELEMENTYP *pTmp = pArray->data;

    int expandCapacity = pArray->capacity + (pArray->capacity >> 1);

    pArray->data = (ELEMENTYP *)malloc(sizeof(ELEMENTYP) * expandCapacity);
    CHECK_MALLOC(pArray->data);

    /* 清空分配内存中脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTYP) * expandCapacity);

    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pTmp[idx];
    }

    pArray->capacity = expandCapacity;

    free(pTmp);
    pTmp = NULL;

    return ON_SUCCESS;
}

/* 动态数组的插入操作（默认插入位置末尾） */
int dynamicArrayInsert(dynamicArray * pArray, ELEMENTYP val)
{
    return dynamicArrayInsertAppointPosData(pArray, val, pArray->len);
}

/* 动态数组指定位置插入数据 */
int dynamicArrayInsertAppointPosData(dynamicArray * pArray, ELEMENTYP val, int pos)
{
    CHECK_PTR(pArray);

    /* 判断位置是否合法 */
    if(pos < 0 || pos > pArray->len)
    {
        return ILLEGAL_DATA;
    }

    /* 当此时存储的数据数量的1.5倍大于等于容量时，开始扩容 */
    if(pArray->len + (pArray->len >> 1) >= pArray->capacity)
    {
        dynamicArrayExpand(pArray);
    }

    for(int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }

    /* data中存储的是val传进来的地址 */
    pArray->data[pos] = val;
    pArray->len++;

    return ON_SUCCESS;
}

