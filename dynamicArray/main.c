#include "dynamicArray.h"
#include <stdio.h>

#define DEFAULT_SIZE 10

int main()
{
    dynamicArray array;
    int test[] = {1, 2, 3, 4, 5, 6};
    int * val = NULL;

    /* 测试初始化函数 */
    dynamicArrayInit(&array, DEFAULT_SIZE);

    /* 测试插入数据 */
    for(int idx = 0; idx < 5; idx++)
    {
        dynamicArrayInsert(&array, (void*)&test[idx]);
    }

    /* 指定位置插入 */
    dynamicArrayInsertAppointPosData(&array, (void *)&test[0], 4);

    /* 测试删除 */
    dynamicArrayDelete(&array);

    /* 测试删除指定位置数据 */
    dynamicArrayDeleteAppointPosData(&array, 2);

    for(int idx = 0; idx < array.len; idx++)
    {
        printf("array.data[%d] : %d\n", idx, *(int *)array.data[idx]);
    }

    /* 删除指定元素 */
    dynamicArrayDeleteAppointVal(&array, 1);

#if 0
    /* 测试查找指定位置的元素 */
    dynamicArraySearch(&array, 2, (void *)&val);
    printf("pos = 2 ,val = %d\n", *val);

    /* 修改指定位置的元素 */
    dynamicArrayModifyAppiontPosVal(&array, &test[0], 1);
#endif

    for(int idx = 0; idx < array.len; idx++)
    {
        printf("array.data[%d] : %d\n", idx, *(int *)array.data[idx]);
    }

#if 0 
    /* 测试获取动态数组大小 */
    int len = 0;
    dynamicArrayGetSize(&array, &len);
    printf("dynamicArray len : %d\n", len);

    /* 测试获取动态数组的容量 */
    int capacity = 0;
    dynamicArrayGetCapacity(&array, &capacity);
    printf("dynamicArray capacity : %d\n", capacity);

    /* 测试销毁数组 */
    // dynamicArrayDestroy(&array);
    // printf("array.data[0]: %d\n", *(int *)array.data[0]);
#endif

    printf("len : %d\n", array.len);
    printf("capacity: %d\n", array.capacity);

    return 0;
}