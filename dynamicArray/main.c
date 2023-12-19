#include "dynamicArray.h"
#include <stdio.h>

#define DEFAULT_SIZE 10

int main()
{
    dynamicArray array;
    int test[] = {1, 2, 3, 4, 5, 6, 7};

    /* 测试初始化函数 */
    dynamicArrayInit(&array, DEFAULT_SIZE);

    /* 测试插入数据 */
    for(int idx = 0; idx < 6; idx++)
    {
        dynamicArrayInsert(&array, (void*)&test[idx]);
    }

    /* 指定位置插入 */
    dynamicArrayInsertAppointPosData(&array, (void *)&test[0], 4);

    for(int idx = 0; idx < array.len; idx++)
    {
        printf("array.data[%d] : %d\n", idx, *(int *)array.data[idx]);
    }
    
    printf("len : %d\n", array.len);
    printf("capacity: %d\n", array.capacity);

    return 0;
}