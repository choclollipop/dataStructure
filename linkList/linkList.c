#include "linkList.h"
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
};

#define CHECK_PTR(ptr)       \
do{                          \
    if(!ptr){                \
        return NULL_PTR;     \
    }                        \
}while(0)

#define CHECK_MALLOC(ptr)       \
do{                             \
    if(!ptr){                   \
        return MALLOC_ERROR;    \
    }                           \
}while(0)


/* 链表初始化 */
int linkListInit(linkList ** pLinkList)
{
    /* 申请含有头指针的结构体 */
    linkList * plinkList = (linkList *)malloc(sizeof(linkList) * 1);
    CHECK_MALLOC(plinkList);
    memset(plinkList, 0, sizeof(linkList) * 1);

    /* 申请头节点的空间 */
    plinkList->head = (Node *)malloc(sizeof(Node) * 1);
    CHECK_MALLOC(plinkList->head);
    memset(plinkList->head, 0, sizeof(Node) * 1);

    /* 初始化链表 */
    plinkList->len = 0;
    /* 初始化头节点 */
    plinkList->head->data = 0;
    plinkList->head->next = NULL;

    *pLinkList = plinkList;

    return ON_SUCCESS;
}

