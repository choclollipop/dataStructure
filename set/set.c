#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
};

/* 判断传入指针是否正确 */
#define CHECK_PTR(ptr)   \
do                       \
{                        \
    if (!ptr)            \
    {                    \
        return NULL_PTR; \
    }                    \
} while (0)

/* 判断分配空间是否正确 */
#define CHECK_MALLOC(ptr)    \
do                           \
{                            \
    if (!ptr)                \
    {                        \
        return MALLOC_ERROR; \
    }                        \
} while (0)

/* 静态函数前置声明 */
static setNode * creatrNewNode(ELEMENTTYPE val, setNode * parentNode);
/* 更新结点高度 */
static int updateNodeHeight(setNode * node);
/* 判断结点是否平衡 */
static int nodeIsBalance(setNode * node);

/* 创建新的结点 */
static setNode * creatrNewNode(ELEMENTTYPE val, setNode * parentNode)
{
    setNode * newNode = (setNode *)malloc(sizeof(setNode) * 1);
    CHECK_MALLOC(newNode);
    memset(newNode, 0, sizeof(setNode) * 1);

    newNode->height = 1;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->parent = parentNode;
    newNode->val = val;

    return newNode;
}

/* 集合的初始化 */
int setInit(set **pSet, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    set * myset = (set *)malloc(sizeof(set) * 1);
    CHECK_MALLOC(myset);
    memset(myset, 0, sizeof(set) * 1);

    myset->root = creatrNewNode(0, NULL);

    /* 初始化集合 */
    myset->size = 0;
    myset->compareFunc = compareFunc;

    *pSet = myset;

    return ON_SUCCESS;
}

/* 判断结点左右子树高度的最大值 */
static int nodeMax(setNode * node)
{
    int leftHeight = node->lchild == NULL ? 0 : node->lchild->height;

    int rightHeight = node->rchild == NULL ? 0 : node->rchild->height;

    return leftHeight - rightHeight >= 0 ? leftHeight : rightHeight;
}

/* 更新结点高度 */
static int updateNodeHeight(setNode * node)
{
    int maxHeight = nodeMax(node);

    node->height = maxHeight + 1;

    return ON_SUCCESS;
}

/* 判断结点是否平衡 */
static int nodeIsBalance(setNode * node)
{
    int leftHeight = node->lchild == NULL ? 0 : node->lchild->height;

    int rightHeight = node->rchild == NULL ? 0 : node->rchild->height;

    int sub = leftHeight - rightHeight;
    if (abs(sub) >= 1)
    {
        /* 不平衡 */
        return 1;
    }
    
    /* 平衡 */
    return 0;
}

/* 左旋 */
static int leftRotate(setNode * node)
{


}

/* 插入结点后的操作 */
static int afterInsert(set * pSet)
{
    
}

/* 集合中插入数据 */
int setInsert(set *pSet, ELEMENTTYPE *pVal)
{
    CHECK_PTR(pSet);

    setNode * travelNode = pSet->root;

    /* 插入的结点是根节点 */
    if (!pSet->size)
    {
        pSet->root->val = pVal;
    }

    int cmp = 0;
    setNode * parentNode = travelNode->parent;
    /* 插入的结点不是根节点 */
    while (pSet)
    {
        /* 记录父节点 */
        parentNode = travelNode;

        cmp = pSet->compareFunc(travelNode->val, pVal);

        if (cmp < 0)
        {
            travelNode = travelNode->rchild;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->lchild;
        }
        else
        {
            return ON_SUCCESS;
        }
    }

    set * newNode = creatrNewNode(pVal, parentNode);

    if (cmp > 0)
    {
        parentNode->lchild = newNode;
    }
    else
    {
        parentNode->rchild = newNode;
    }

    /* 插入结点后需要进行的操作 */

    /* 更新集合内容 */
    pSet->size++;

    return 0;
}
