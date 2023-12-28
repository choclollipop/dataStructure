#include "binarySearchTree.h"
#include <stdio.h>

#define BUFFER_SIZE    5

int InOrderTravel(BSTreeNode * node)
{
    if(node)
    {
        InOrderTravel(node->lchild);
        printf("data : %d\n", *(int *)node->data);
        InOrderTravel(node->rchild);
    }
    
    return 0;
}

int printFunc(void * val)
{
    int * tmp = (int *)val;
    printf("data : %d\n", *tmp);
}

int compare(void * val1, void *val2)
{
    int * tmp1 = (int *)val1;
    int * tmp2 = (int *)val2;

    if(*tmp1 < *tmp2)
    {
        return -1;
    }
    else if(*tmp1 > *tmp2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    binarySearchTree * tree = NULL;
    int buffer[BUFFER_SIZE] = {6, 10, 5, 7, 9};

    binarySearchTreeInit(&tree, compare, printFunc);

    /* 测试二叉搜索树的插入操作 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        binarySearchTreeInsert(tree, (void *)&buffer[idx]);
    }

    /* 测试删除函数 */
    binarySearchTreeDeleteAppointVal(tree, (void *)&buffer[4]);

    /* 测试二叉搜索的树前序遍历 */
    binarySearchTreePreOrederTravel(tree);
    printf("\n");

    /* 测试二叉搜索树的中序遍历 */
    binarySearchTreeInOrderTravel(tree);
    printf("\n");

    /* 测试二叉搜索树的后序遍历 */
    binarySearchTreePostOrderTravel(tree);
    printf("\n");

    /* 测试二叉搜索树的层序遍历 */
    binarySearchTreeLevelTravel(tree);

    /* 测试获取结点个数 */
    int size = 0;
    binarySearchTreeNodeSize(tree, &size);
    printf("size : %d\n", size);

    /* 测试获取二叉搜索树高度函数 */
    int height = 0;
    binarySearchTreeGetHeight(tree, &height);
    printf("height : %d\n", height);

    return 0;
}