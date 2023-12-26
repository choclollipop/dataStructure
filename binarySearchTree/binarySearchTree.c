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

/* 前置声明 */
static BSTreeNode * creatrNewNode(ELEMENTTYPE val, BSTreeNode * node);

/* 二叉搜索树初始化 */
int binarySearchTreeInit(binarySearchTree ** pBSTree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
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
    tree->compareFunc = compareFunc;

    *pBSTree = tree;

    return ON_SUCCESS;
}

/* 二叉搜索树创建新的结点 */
static BSTreeNode * creatrNewNode(ELEMENTTYPE val, BSTreeNode * parentNode)
{
    BSTreeNode * newNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if(!newNode)
    {
        return NULL;
    }
    memset(newNode, 0, sizeof(BSTreeNode) * 1);

    newNode->data = val;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->parent = parentNode;

    return newNode;
}

/* 二叉搜索树插入 */
int binarySearchTreeInsert(binarySearchTree * pBSTree, ELEMENTTYPE val)
{
    CHECK_PTR(pBSTree);

    /* 从根结点开始遍历 */
    BSTreeNode * travelNode = pBSTree->root;
    /* 根节点为空插入根节点中 */
    if(pBSTree->size == 0)
    {
        travelNode->data = val;
        pBSTree->size++;

        return ON_SUCCESS;
    }

    /* 比较插入的值与结点大小 */
    int cmp = 0;

    BSTreeNode * parentNode = NULL;
    while(travelNode != NULL)
    {
        parentNode = travelNode;

        cmp = pBSTree->compareFunc(val, travelNode->data);

        if(cmp < 0)
        {
            travelNode = travelNode->lchild;
        }
        else if(cmp > 0)
        {
            travelNode = travelNode->rchild;
        }
        else
        {
            /* 相同时不做插入操作直接返回 */
            return ON_SUCCESS;
        }
    }

    BSTreeNode * newNode = creatrNewNode(val, parentNode);
    CHECK_MALLOC(newNode);

    if(cmp < 0)
    {
        parentNode->lchild = newNode;
    }
    else
    {
        parentNode->rchild = newNode;
    }

    /* 更新树的结点个数 */
    pBSTree->size++;

    return ON_SUCCESS;
}