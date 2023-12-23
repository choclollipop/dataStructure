#include "doubleCircleLinkList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    NOT_FIND,
};

static int DoubleCircleLinkListAccordAppointValGetPos(DoubleCircleLinkList *pList, ELEMENTTYPE val, int *pPos, int(* compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));
static DoubleLinkNode *createDoubleLinkNode(ELEMENTTYPE val);

/* 链表初始化 */
int DoubleCircleLinkListInit(DoubleCircleLinkList **pList)
{
    DoubleCircleLinkList *list = (DoubleCircleLinkList *)malloc(sizeof(DoubleCircleLinkList) * 1);
    if (!list)
    {
        return MALLOC_ERROR;
    }
    /* 清空脏数据 */
    memset(list, 0, sizeof(DoubleCircleLinkList) * 1);

    list->head = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if (!list->head)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(DoubleLinkNode) * 1);

    /* 初始化链表的长度和尾指针 */
    list->len = 0;
    list->tail = list->head;

    /* 初始化头节点 */
    list->head->data = 0;
    list->head->next = NULL;
    list->head->prev = NULL;

    *pList = list;

    return ON_SUCCESS;
}

/* 链表头插 */
int DoubleCircleLinkListHeadInsert(DoubleCircleLinkList *pList, ELEMENTTYPE val)
{
    return DoubleCircleLinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int DoubleCircleLinkListTailInsert(DoubleCircleLinkList *pList, ELEMENTTYPE val)
{
    return DoubleCircleLinkListAppointPosInsert(pList, pList->len, val);
}

/* 创建新节点封装成函数 */
static DoubleLinkNode *createDoubleLinkNode(ELEMENTTYPE val)
{
    DoubleLinkNode *newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if (!newNode)
    {
        return NULL;
    }
    memset(newNode, 0, sizeof(DoubleLinkNode) * 1);
    newNode->data = 0;
    newNode->next = NULL;
    newNode->prev = NULL;

    /* 赋值 */
    newNode->data = val;

    return newNode;
}

/* 链表指定位置插入 */
int DoubleCircleLinkListAppointPosInsert(DoubleCircleLinkList *pList, int pos, ELEMENTTYPE val)
{
    if (!pList)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 创建新节点封装成函数 */
    DoubleLinkNode *newNode = createDoubleLinkNode(val);
    if (!newNode)
    {
        return MALLOC_ERROR;
    }

    /* 从头结点开始遍历 */
    DoubleLinkNode *travel = pList->head;

    /* 改变尾指针的情况:尾插 */
    int flag = 0;
    if (pos != 0)
    {
        if (pos == pList->len)
        {
            travel = pList->tail;
            flag = 1;
        }
        else
        {
            while (pos)
            {
                travel = travel->next;
                pos--;
            }
        }
        /* 执行插入操作 */
        newNode->next = travel->next;
        newNode->prev = travel;
        travel->next->prev = newNode;
        travel->next = newNode;
    }
    /* 插入位置在头结点之后 */
    else
    {
        if (pList->len == 0)
        {
            newNode->prev = newNode;
            newNode->next = newNode;
            travel->next = newNode;
            flag = 1;
        }
        else
        {
            /* 执行插入操作 */
            newNode->next = travel->next;
            newNode->prev = travel->next->prev;
            travel->next->prev = newNode;
            travel->next = newNode;
            pList->tail->next = newNode;
        }
    }

    if (flag)
    {
        pList->tail = newNode;
    }

    /* 更新链表数据 */
    pList->len++;

    return ON_SUCCESS;
}

/* 链表头删 */
int DoubleCircleLinkListHeadDel(DoubleCircleLinkList *pList)
{
    return DoubleCircleLinkListAppointPosDel(pList, 1);
}

/* 链表尾删 */
int DoubleCircleLinkListTailDel(DoubleCircleLinkList *pList)
{
    return DoubleCircleLinkListAppointPosDel(pList, pList->len);
}

/* 链表指定位置删除 */
int DoubleCircleLinkListAppointPosDel(DoubleCircleLinkList *pList, int pos)
{
    if (!pList)
    {
        return NULL_PTR;
    }

    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 从头结点开始遍历 */
    DoubleLinkNode *travel = pList->head;
    DoubleLinkNode *needDelNode = NULL;

    int flag = 0;
    if (pos == pList->len && pList->len != 0)
    {
        flag = 1;
        travel = pList->tail->prev;
        needDelNode = pList->tail;
        pList->head->next->prev = travel;
    }
    else if (pos == 1)
    {
        travel = pList->head;
        needDelNode = travel->next;
        needDelNode->next->prev = pList->tail;
    }
    else
    {
        while (--pos)
        {
            travel = travel->next;
        }
        needDelNode = travel->next;
        needDelNode->next->prev = travel;
    }

    travel->next = needDelNode->next;

    /* 删除了表尾结点的时候需要移动尾指针 */
    if (flag)
    {
        pList->tail = travel;
    }

    /* 释放内存 */
    if (needDelNode)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    /* 更新链表信息 */
    pList->len--;

    return ON_SUCCESS;
}

/* 根据指定元素得到元素在链表中所在位置 */
static int DoubleCircleLinkListAccordAppointValGetPos(DoubleCircleLinkList *pList, ELEMENTTYPE val, int *pPos, int(* compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    /* 第一个数据开始遍历 */
    DoubleLinkNode * travelNode = pList->head->next;

    int pos = 0;
    int ret = 0;
    int count = 1;

    while(count <= pList->len)
    {
        ret = compareFunc(travelNode->data, val);
        if(ret == 1)
        {
            pos++;
            *pPos = pos;
            return pos;
        }
        travelNode = travelNode->next;
        pos++;
        count++;
    }

    *pPos = NOT_FIND;

    return NOT_FIND;
}

/* 链表删除指定元素 */
int DoubleCircleLinkListDelAppointVal(DoubleCircleLinkList *pList, ELEMENTTYPE val, int(* compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    if (!pList)
    {
        return NULL_PTR;
    }

    int pos = 0;
    
    while(pos != NOT_FIND)
    {
        DoubleCircleLinkListAppointPosDel(pList, DoubleCircleLinkListAccordAppointValGetPos(pList, val, &pos, compareFunc));
    }

    return ON_SUCCESS;
}

/* 获取链表长度 */
int DoubleCircleLinkListGetLen(DoubleCircleLinkList *pList, int *pSize)
{
    if (!pList)
    {
        return NULL_PTR;
    }

    if (pSize)
    {
        *pSize = pList->len;
    }

    /* 返回链表长度 */
    return pList->len;
}

/* 销毁链表 */
int DoubleCircleLinkListDestory(DoubleCircleLinkList *pList)
{
    /* 使用头删销毁链表 */
    int size = 0;
    while (DoubleCircleLinkListGetLen(pList, &size))
    {
        DoubleCircleLinkListHeadDel(pList);
    }

    /* 删除头节点，并将头指针和尾指针都置空 */
    if (pList->head)
    {
        free(pList->head);
        pList->head = NULL;
        pList->tail = NULL;
    }

    return ON_SUCCESS;
}

/* 链表的遍历 */
int DoubleCircleLinkListForeach(DoubleCircleLinkList *pList, int (*printFunc)(ELEMENTTYPE))
{
    if (!pList)
    {
        return NULL_PTR;
    }

    /* 从头结点开始遍历 */
    DoubleLinkNode *travel = pList->head->next;
    int count = 0;

    /* 结束条件：下一个结点的指针域为空，即来到了表尾结点 */
    while (count != pList->len)
    {
        /* 包装器即回调函数 */
        printFunc(travel->data);
        travel = travel->next;
        count++;
    }

    return ON_SUCCESS;
}

/* 链表逆序打印 */
int DoubleCircleLinkListReverseForeach(DoubleCircleLinkList *pList, int (*printFunc)(ELEMENTTYPE))
{
    if (!pList)
    {
        return NULL_PTR;
    }

    /* 从尾节点开始遍历 */
    DoubleLinkNode *travel = pList->tail;
    int count = 0;

    /* 结束条件：头结点的指针域为空，即来到了表尾结点 */
    while (count != pList->len)
    {
        /* 包装器即回调函数 */
        printFunc(travel->data);
        travel = travel->prev;
        count++;
    }

    return ON_SUCCESS;
}