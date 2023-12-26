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
} binarySearchTree;

/* 二叉搜索树初始化 */
int binarySearchTreeInit(binarySearchTree ** pBSTree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 二叉搜索树插入 */
int binarySearchTreeInsert(binarySearchTree * pBSTree, ELEMENTTYPE val);



#endif //__BINARYSEARCH_TREE_H_