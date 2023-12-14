#include <stdio.h>
#include "sequenceTable.h"

#define BUF_LIST 5


int main()
{
    seqList List;
   
    InitList(&List);

#if 1

    for(int idx = 0; idx < List.lenth; idx++)
    {
        printf("%d\t", *(List.data + idx));
    }

#endif

    /* 给顺序表赋值，赋值时不要忘记初始化时，表长度为0，需要将表长度同时赋值 */
    for(int idx = 0; idx < BUF_LIST - 1; idx++)
    {
        *(List.data + idx) = idx + 2;
        printf("%d\t", List.data[idx]);
        List.lenth = idx;
    }

    printf("上面是初始顺序表\n");

    List.lenth = BUF_LIST - 1;

#if 0
    
    InsertList(&List, 3, 5);

    /* 打印插入后的顺序表 */
    for(int idx = 0; idx < List.lenth; idx++)
    {
        printf("%d\t", List.data[idx]);
    }

    printf("\n");

    int delate;
    delateList(&List, 3, &delate);

    /* 打印删除后的顺序表，并打印删除的位置的值 */
    for(int idx = 0; idx < List.lenth; idx++)
    {
        printf("%d\t", List.data[idx]);
    }

    printf("delate data:%d\n", delate);

#endif

   
    int search = orderSearch(&List, 3);
    printf("search : %d\n", search);

    int locate = locateList(&List, 7);
    printf("locate : %d\n", locate);
    

    return 0;
}