#include "doubleCircleLinkList.h"
#include <stdio.h>

#define BUFFER_SIZE 5

int printInt(void *argc)
{
    int *tmp = (int *)argc;
    printf("circleList.data : %d\n", *tmp);
}

int compare(void * val1, void * val2)
{
    int ret = 0;
    int * tmp1 = (int *)val1;
    int * tmp2 = (int *)val2;

    /* todo ...... */
    if(*tmp1 == *tmp2)
    {
        return ret = 1;
    }

    return ret = 0;
}

int main()
{
    DoubleCircleLinkList *circleList = NULL;
    int buffer[BUFFER_SIZE] = {1, 2, 3, 4, 5};

    /* 测试初始化函数 */
    DoubleCircleLinkListInit(&circleList);

    /* 测试头插法 */
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        DoubleCircleLinkListHeadInsert(circleList, (void *)&buffer[idx]);
    }

    /* 测试尾插法 */
    for (int idx = 0; idx < 2; idx++)
    {
        DoubleCircleLinkListTailInsert(circleList, (void *)&buffer[idx]);
    }

    /* 测试指定位置插入数据 */
    DoubleCircleLinkListAppointPosInsert(circleList, 5, (void *)&buffer[2]);

    int len = 0;
    printf("circleLinkList.len : %d\n", circleList->len);

    /* 测试获取链表长度函数 */
    DoubleCircleLinkListGetLen(circleList, &len);
    printf("len : %d\n", len);

    /* 测试指定位置删除 */
    DoubleCircleLinkListAppointPosDel(circleList, 2);

    /* 测试循环尾删 */
    for (int idx = 0; idx < 2; idx++)
    {
        DoubleCircleLinkListTailDel(circleList);
    }

    /* 测试头删 */
    DoubleCircleLinkListHeadDel(circleList);

    /* 测试删除指定元素 */
    int val = 3;
    DoubleCircleLinkListDelAppointVal(circleList, (void *)&val, compare);

    /* 测试销毁链表 : 销毁后再遍历应该段错误 */
    DoubleCircleLinkListDestory(circleList);

    /* 测试遍历函数 */
    DoubleCircleLinkListForeach(circleList, printInt);

    /* 测试逆序打印函数 */
    // DoubleCircleLinkListReverseForeach(circleList, printInt);

    return 0;
}