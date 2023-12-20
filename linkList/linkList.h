#ifndef __LINK_LIST_H_
#define __LINK_LIST_H_

#define ELEMENTTYPE void*

typedef struct Node
{
    ELEMENTTYPE data;
    struct Node * next;
}Node;

typedef struct LinkList
{
    Node * head;   //头指针
    Node * tail;   //尾指针
    int len;
}linkList;


/* 链表初始化 */
int linkListInit(linkList ** pLinkList);

/* 头插 */
int linkListHeadInsert(linkList * pList, ELEMENTTYPE val);

/* 尾插 */
int linkListTailInsert(linkList * pList, ELEMENTTYPE val);

/* 指定位置插入 */
int linkListAppointPosInsert(linkList * pList, int pos, ELEMENTTYPE val);

/* 头删 */
int linkListDelHead(linkList * pList);

/* 尾删 */
int linkListDelTail(linkList * pList);

/* 删除指定位置元素 */
int linkListDeleteAppointPosVal(linkList * pList, int pos);

/* 删除指定元素*/
int linkListDelAppointVal();    //todo......

/* 修改链表指定位置数据 */
int linkListModifyAppointPosVal(linkList * pList, int pos, ELEMENTTYPE val);

/* 获取链表大小 */
int linkListGetLen(linkList * pList, int *len);

/* 查询链表指定位置的元素 */
int linkListGetVal(linkList * pList, int pos, ELEMENTTYPE *val);

/* 遍历链表 */
int linkListSearch(linkList * pList, int(* printFunc)(ELEMENTTYPE));

/* 销毁链表 */
int linkListDestroy(linkList * pList);

#endif //__LINKLIST_H_