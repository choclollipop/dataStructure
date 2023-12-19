#ifndef __LINK_LIST_H_
#define __LINK_LIST_H_

typedef struct Node
{
    ELEMENTTYPE data;
    struct node * next;
}Node;

typedef struct LinkList
{
    Node * head;   //头指针
    int len;
}linkList;


/* 链表初始化 */
int linkListInit(linkList ** pLinkList);

/* 头插 */
int linkListHeadInsert();

/* 尾插 */
int linkListTailInsert();

/* 指定位置插入 */
int linkListAppointPosInsert();

/* 删除元素（默认删除表尾元素） */
int linkListDeleteVal();

/* 删除指定位置元素 */
int linkListDeleteAppointPosVal();

/* 修改链表指定位置数据 */
int linkListModifyAppointPosVal();

/* 获取链表大小 */
int linkListGetLen();

/* 查询链表指定位置的元素 */
int linkListGetVal();

#endif //__LINKLIST_H_