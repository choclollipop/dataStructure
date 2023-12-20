#include "linkList.h"
#include <stdio.h>

#define BUFFER_SIZE 3

int myPrint(void * argv)
{
    int * tmp = (int *)argv;
    printf("list.data : %d\n", *tmp);
}

int main()
{
    linkList * list = NULL;
    int buffer[BUFFER_SIZE] = {0, 1, 2};
    int val = 5;

    /* 测试初始化函数 */
    linkListInit(&list);
    printf("list.len : %d\tlist.head : %p\tlist.tail : %p\n", list->len, list->head, list->tail);

    /* 测试插入(头插） */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        linkListHeadInsert(list, (void *)&buffer[idx]);
    }

    /* 测试尾插 */
    linkListTailInsert(list, (void *)&val);

    /* 测试指定位置插入 */
    linkListAppointPosInsert(list, 2, (void *)&buffer[2]);

    /* 测试头删 */
    linkListDelHead(list);

    /* 测试尾删 */
    linkListDelTail(list);

    /* 测试删除指定位置元素 */
    linkListDeleteAppointPosVal(list, 2);

    /* 测试链表遍历 */
    linkListSearch(list, myPrint);


    return 0;
}