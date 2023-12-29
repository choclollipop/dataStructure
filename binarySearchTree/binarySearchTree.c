#include "binarySearchTree.h"
#include "doubleLinkListQueue.h"
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
/* 创建新节点 */
static BSTreeNode * creatrNewNode(ELEMENTTYPE val, BSTreeNode * node);
/* 前序遍历 */
static int preOrderTravel(binarySearchTree * pBSTree, BSTreeNode * node);
/* 中序遍历 */
static int inOrderTravel(binarySearchTree * pBSTree, BSTreeNode * node);
/* 后序遍历 */
static int postOrderTravel(binarySearchTree * pBSTree, BSTreeNode * node);
/* 获取指定值的结点位置 */
static BSTreeNode * baseAppointValGetPos(binarySearchTree * pBSTree, ELEMENTTYPE val);
/* 删除指定结点 */
static int binarySearchTreeDelete(binarySearchTree * pBSTree, BSTreeNode * node);
/* 度为2 */
static int binarySearchTreeHasTwoChilds(BSTreeNode * node);
/* 度为1 */
static int binarySearchTreeHasOneChild(BSTreeNode * node);
/* 度为0 */
static int binarySearchTreeIsLeave(BSTreeNode * node);
/* 查找指定结点的中序前驱节点 */
static BSTreeNode * getPreNode(BSTreeNode * node);
/* 查找指定结点的中序后继结点 */
static BSTreeNode * getPostNode(BSTreeNode * node);



/* 二叉搜索树初始化 */
int binarySearchTreeInit(binarySearchTree ** pBSTree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
{
    binarySearchTree * tree = (binarySearchTree *)malloc(sizeof(binarySearchTree) * 1);
    /* 判空 */
    CHECK_MALLOC(tree);
    /* 清零 */
    memset(tree, 0, sizeof(binarySearchTree) * 1);

    /* 初始化树 */
    tree->size = 0;
    tree->compareFunc = compareFunc;
    tree->printFunc = printFunc;

    tree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    /* 判空 */
    CHECK_MALLOC(tree->root);
    memset(tree->root, 0, sizeof(BSTreeNode) * 1);

    /* 初始化根节点 */
    tree->root->data = 0;
    tree->root->lchild = NULL;
    tree->root->rchild = NULL;
    tree->root->parent = NULL;

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

/* 前序遍历 */
static int preOrderTravel(binarySearchTree * pBSTree, BSTreeNode * node)
{
    if(node)
    {
        pBSTree->printFunc(node->data);
        preOrderTravel(pBSTree, node->lchild);
        preOrderTravel(pBSTree, node->rchild);
    }

    return ON_SUCCESS;
}

/* 中序遍历 */
static int inOrderTravel(binarySearchTree * pBSTree, BSTreeNode * node)
{
    if(node)
    {
        inOrderTravel(pBSTree, node->lchild);
        pBSTree->printFunc(node->data);
        inOrderTravel(pBSTree, node->rchild);
    }

    return ON_SUCCESS;
}

/* 后序遍历 */
static int postOrderTravel(binarySearchTree * pBSTree, BSTreeNode * node)
{
    if(node)
    {
        postOrderTravel(pBSTree, node->lchild);
        postOrderTravel(pBSTree, node->rchild);
        pBSTree->printFunc(node->data);
    }

    return ON_SUCCESS;
}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrederTravel(binarySearchTree * pBSTree)
{
    CHECK_PTR(pBSTree);

    return preOrderTravel(pBSTree, pBSTree->root);
}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree * pBSTree)
{
    CHECK_PTR(pBSTree);

    return inOrderTravel(pBSTree, pBSTree->root);
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree * pBSTree)
{
    CHECK_PTR(pBSTree);

    return postOrderTravel(pBSTree, pBSTree->root);
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelTravel(binarySearchTree * pBSTree)
{
    CHECK_PTR(pBSTree);

    doubleLinkListQueue * queue = NULL;
    BSTreeNode * val = NULL;
    /* 初始化队列 */
    doubleLinkListQueueInit(&queue);

    /* 头结点入队 */
    doubleLinkListQueuePush(queue, pBSTree->root);

    /* 循环取值 */
    while(!doubleLinkListQueueIsEmpty(queue))
    {
        /* 取队头元素 */
        doubleLinkListQueueTop(queue, (void **)&val);
        pBSTree->printFunc(val->data);
        /* 出队 */
        doubleLinkListQueuePop(queue);

        if(val->lchild)
        {
            doubleLinkListQueuePush(queue, (void *)&val->lchild);
        }
        if(val->rchild)
        {
            doubleLinkListQueuePush(queue, (void *)&val->rchild);
        }
    }

    /* 释放队列 */
    doubleLinkListQueueDestroy(queue);

    return ON_SUCCESS;
}

/* 获取二叉搜索树的结点个数 */
int binarySearchTreeNodeSize(binarySearchTree * pBSTree, int * pSize)
{
    CHECK_PTR(pBSTree);

    *pSize = pBSTree->size;

    return pBSTree->size;
}

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(binarySearchTree * pBSTree, int * pHeight)
{
    CHECK_PTR(pBSTree);

    doubleLinkListQueue * queue = NULL;
    BSTreeNode * val = NULL;

    /* 队列初始化 */
    doubleLinkListQueueInit(&queue);

    /* 根节点入队 */
    doubleLinkListQueuePush(queue, pBSTree->root);
    /* 记录每层的结点个数 */
    int levelSize = 1;
    /* 记录高度 */
    int height = 0;

    while(!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&val);
        doubleLinkListQueuePop(queue);
        levelSize--;

        if(val->lchild)
        {
            doubleLinkListQueuePush(queue, (void *)&val->lchild);
        }
        if(val->rchild)
        {
            doubleLinkListQueuePush(queue, (void *)&val->rchild);
        }
        if(!levelSize)
        {
            height++;
            doubleLinkListQueueGetSize(queue, &levelSize);
        }
    }

    *pHeight = height;

    /* 销毁队列 */
    doubleLinkListQueueDestroy(queue);

    return ON_SUCCESS;
}

/* 获取指定值的结点位置 */
static BSTreeNode * baseAppointValGetPos(binarySearchTree * pBSTree, ELEMENTTYPE val)
{
    /* 从根节点开始遍历 */
    BSTreeNode * travelNode = pBSTree->root;
    
    int cmp = 0;
    while (travelNode)
    {
        cmp = pBSTree->compareFunc(val, travelNode->data);
        /* cmp小于0表示val小于当前结点，应该向左子树继续寻找 */
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
            return travelNode;
        }
    }
    
    return NULL;
}

/* 度为2 */
static int binarySearchTreeHasTwoChilds(BSTreeNode * node)
{
    CHECK_PTR(node);

    return node->rchild != NULL && node->lchild != NULL;
}

/* 度为1 */
static int binarySearchTreeHasOneChild(BSTreeNode * node)
{
    CHECK_PTR(node);

    return (node->rchild != NULL && node->lchild == NULL) || (node->rchild == NULL && node->lchild != NULL);
}

/* 度为0 */
static int binarySearchTreeIsLeave(BSTreeNode * node)
{
    CHECK_PTR(node);

    return node->rchild == NULL && node->lchild == NULL;
}

/* 查找指定结点的中序前驱节点 */
static BSTreeNode * getPreNode(BSTreeNode * node)
{
    if(!node)
    {
        return NULL;
    }

    BSTreeNode * travelNode = node->lchild;

    /* 有左子树 */
    if(travelNode)
    {
        while(travelNode->rchild)
        {
            travelNode = travelNode->rchild;
        }
        return travelNode;
    }
    else
    {
        travelNode = node->parent;
        while(travelNode->parent)
        {
            if(travelNode == travelNode->parent->rchild)
            {
                return travelNode->parent;
            }
            travelNode = travelNode->parent;
        }
    }

    return NULL;   
}

/* 查找指定结点的中序后继结点 */
static BSTreeNode * getPostNode(BSTreeNode * node)
{
    if(!node)
    {
        return NULL;
    }

    BSTreeNode * travelNode = node->rchild;

    /* 有右子树 */
    if(travelNode)
    {
        while (travelNode->lchild)
        {
            travelNode = travelNode->lchild;
        }
        return travelNode;
    }
    else
    {
        /* 没有右子树 */
        travelNode = travelNode->parent;
        while(travelNode->parent)
        {
            if(travelNode == travelNode->parent->lchild)
            {
                return travelNode->parent;
            }
            travelNode = travelNode->parent;
        }
    }

    return NULL;
}

/* 删除指定结点 */
static int binarySearchTreeDelete(binarySearchTree * pBSTree, BSTreeNode * node)
{
    CHECK_PTR(pBSTree);
    CHECK_PTR(node);

    BSTreeNode * delNode = node;
    BSTreeNode * preNode = NULL;

    if(binarySearchTreeHasTwoChilds(delNode))
    {
        preNode = getPreNode(delNode);
        delNode->data = preNode->data;
        delNode = preNode;
    }

    BSTreeNode * child = delNode->lchild != NULL ? delNode->lchild : delNode->rchild;
    /* child非空则表示删除结点度为1 */
    if(child)
    {
        child->parent = delNode->parent;
        if(delNode == delNode->parent->lchild)
        {
            delNode->parent->lchild = child;
        }
        else if(delNode == delNode->parent->rchild)
        {
            delNode->parent->rchild = child;
        }
        if(delNode->parent == NULL)
        {
            pBSTree->root = child;
        }
    }
    else
    {
        if(delNode == delNode->parent->lchild)
        {
            delNode->parent->lchild = NULL;
        }
        else if(delNode == delNode->parent->rchild)
        {
            delNode->parent->rchild = NULL;
        }
    }

    if(delNode)
    {
        free(delNode);
        delNode = NULL;
    }

    return ON_SUCCESS;
}

/* 二叉搜索树删除指定的值 */
int binarySearchTreeDeleteAppointVal(binarySearchTree * pBSTree, ELEMENTTYPE val)
{
    CHECK_PTR(pBSTree);

    return binarySearchTreeDelete(pBSTree, baseAppointValGetPos(pBSTree, val));
}

/* 二叉搜索树的销毁 */
int binarySearchTreeDestroy(binarySearchTree * pBSTree)
{
    CHECK_PTR(pBSTree);

    /* 使用层序遍历删除所有结点 */
    doubleLinkListQueue * queue = NULL;
    BSTreeNode * valNode = NULL;

    /* 队列初始化 */
    doubleLinkListQueueInit(&queue);

    /* 根节点入队 */
    doubleLinkListQueuePush(queue, (void *)pBSTree->root);
    /* 循环删除 */
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&valNode);
        doubleLinkListQueuePop(queue);

        if(valNode->lchild)
        {
            doubleLinkListQueuePush(queue, (void **)&valNode->lchild);
        }
        if(valNode->rchild)
        {
            doubleLinkListQueuePush(queue, (void **)&valNode->rchild);
        }

        if(valNode)
        {
            free(valNode);
            valNode = NULL;
        }
    }

    /* 销毁队列 */
    doubleLinkListQueueDestroy(queue);

    if(pBSTree)
    {
        free(pBSTree);
        pBSTree->root = NULL;
    }

    return ON_SUCCESS;  
}
