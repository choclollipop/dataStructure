#ifndef __DOUBLECIRCLE_LINKLIST_H_
#define __DOUBLECIRCLE_LINKLIST_H_

#define ELEMENTTYPE void *

/* 链表结点 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;
    struct DoubleLinkNode * prev;
    struct DoubleLinkNode * next;
}DoubleLinkNode;

/* 链表 */
typedef struct DoubleCircleLinkList
{
    DoubleLinkNode * head;
    DoubleLinkNode * tail;
    int len;
}DoubleCircleLinkList;

/* 链表初始化 */
int DoubleCircleLinkListInit(DoubleCircleLinkList ** pList);

/* 链表头插 */
int DoubleCircleLinkListHeadInsert(DoubleCircleLinkList * pList, ELEMENTTYPE val);

/* 链表尾插 */
int DoubleCircleLinkListTailInsert(DoubleCircleLinkList * pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int DoubleCircleLinkListAppointPosInsert(DoubleCircleLinkList * pList,int pos, ELEMENTTYPE val);

/* 链表头删 */
int DoubleCircleLinkListHeadDel(DoubleCircleLinkList * pList);

/* 链表尾删 */
int DoubleCircleLinkListTailDel(DoubleCircleLinkList * pList);

/* 链表指定位置删除 */
int DoubleCircleLinkListAppointPosDel(DoubleCircleLinkList * pList, int pos);

/* 链表删除指定元素 */
int DoubleCircleLinkListDelAppointVal(DoubleCircleLinkList * pList, ELEMENTTYPE val);

/* 获取链表长度 */
int DoubleCircleLinkListGetLen(DoubleCircleLinkList * pList, int * pSize);

/* 销毁链表 */
int DoubleCircleLinkListDestory(DoubleCircleLinkList * pList);

/* 链表的遍历 */
int DoubleCircleLinkListForeach(DoubleCircleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

/* 链表的逆序打印 */
int DoubleCircleLinkListReverseForeach(DoubleCircleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

#endif //__DOUBLECIRCLE_LINKLIST_H_