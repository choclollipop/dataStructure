#include "linkList.h"
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ILLEGAL_DATA,
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
int linkListInit(linkList ** pList)
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
    /* 头尾指针均指向头结点 */
    plinkList->tail = plinkList->head;

    *pList = plinkList;

    return ON_SUCCESS;
}

/* 头插 */
int linkListHeadInsert(linkList * pList, ELEMENTTYPE val)
{
    return linkListAppointPosInsert(pList, 0, val);
}

/* 尾插 */
int linkListTailInsert(linkList * pList, ELEMENTTYPE val)
{
    return linkListAppointPosInsert(pList, pList->len, val);
}

/* 指定位置插入(后插操作) */
int linkListAppointPosInsert(linkList * pList, int pos, ELEMENTTYPE val)
{
    CHECK_PTR(pList);

    if(pos < 0 || pos > pList->len)
    {
        return ILLEGAL_DATA;
    }

    /* 创建新结点 */
    Node * newNode = (Node *)malloc(sizeof(Node) * 1);
    /* 判空 */
    CHECK_MALLOC(newNode);
    memset(newNode, 0, sizeof(Node) * 1);
    /* 给新结点赋值 */
    newNode->next = NULL;
    newNode->data = val;

    /* travleNode此时指向头结点，从头结点开始遍历 */
    Node * travleNode = pList->head;

    /* 进行尾插操作时，可以直接利用尾指针，不用再次遍历 */
    int flag = 0;
    if(pos == pList->len)
    {
        travleNode = pList->tail;
        flag = 1;
    }
    else
    {
        while(pos)
        {
            /* 向后遍历 */
            travleNode = travleNode->next;
            pos--;
        }
    }

    /* 执行插入操作 */
    newNode->next = travleNode->next;
    travleNode->next = newNode;

    if(flag)
    {
        pList->tail = newNode;
    }

    /* 更新链表信息 */
    pList->len++;

    return ON_SUCCESS;
}





/* 遍历链表 */
int linkListSearch(linkList * pList, int(* printFunc)(ELEMENTTYPE))
{
    CHECK_PTR(pList);

    /* 从头结点开始遍历 */
    Node * traveNode = pList->head;

    while(traveNode->next)
    {
        traveNode = traveNode->next;
        /* 回调函数 */
        printFunc(traveNode->data);
    }

    return ON_SUCCESS;
}