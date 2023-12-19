#include "dynamicArray.h"
#include <stdio.h>

#define DEFAULT_SIZE 5

int main()
{
    dynamicArray array;

    dynamicArrayInit(&array, DEFAULT_SIZE);
    printf("len : %d\n", array.len);
    printf("capacity: %d\n", array.capacity);

    return 0;
}