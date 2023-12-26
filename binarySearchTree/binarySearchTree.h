#ifndef __BINARYSEARCH_TREE_H_
#define __BINARYSEARCH_TREE_H_

#define ELEMENTTYPE   void *

typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode * lchild;
    struct BSTreeNode * rchild;
    struct BSTreeNode * parent;
} BSTreeNode;

typedef struct binarySearchTree
{
    BSTreeNode * root;
    int size;

    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);

    int (*printFunc)(ELEMENTTYPE val);
} binarySearchTree;

/* 二叉搜索树初始化 */
int binarySearchTreeInit(binarySearchTree ** pBSTree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val));

/* 二叉搜索树插入 */
int binarySearchTreeInsert(binarySearchTree * pBSTree, ELEMENTTYPE val);

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrederTravel(binarySearchTree * pBSTree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree * pBSTree);

#endif //__BINARYSEARCH_TREE_H_