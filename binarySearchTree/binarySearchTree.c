#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 判空 */
#define CHECK_PTR(ptr)      \
do{                         \
    if(!ptr){               \
        return NULL_PTR;    \
    }                       \
}while(0)

/* 检查malloc是否成功 */
#define CHECK_MALLOC(ptr)       \
do{                             \
    if(!ptr){                   \
        return MALLOC_ERROR;    \
    }                           \
}while(0)

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
    NOT_FIND,
};

/* 二叉搜索树初始化 */
int binarySearchTreeInit(binarySearchTree ** pBSTree)
{
    binarySearchTree * tree = (binarySearchTree *)malloc(sizeof(binarySearchTree) * 1);
    /* 判空 */
    CHECK_MALLOC(tree);
    /* 清零 */
    memset(tree, 0, sizeof(binarySearchTree) * 1);

    /* 初始化 */
    tree->size = 0;

    tree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    /* 判空 */
    CHECK_MALLOC(tree->root);
    memset(tree->root, 0, sizeof(BSTreeNode) * 1);

    tree->root->data = 0;
    tree->root->lchild = NULL;
    tree->root->rchild = NULL;
    tree->root->parent = NULL;

    *pBSTree = tree;

    return ON_SUCCESS;
}

