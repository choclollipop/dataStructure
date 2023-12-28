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

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree * pBSTree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelTravel(binarySearchTree * pBSTree);

/* 获取二叉搜索树的结点个数 */
int binarySearchTreeNodeSize(binarySearchTree * pBSTree, int * pSize);

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(binarySearchTree * pBSTree, int * pHeight);

/* 二叉搜索树删除指定的值 */
int binarySearchTreeDeleteAppointVal(binarySearchTree * pBSTree, ELEMENTTYPE val);

#endif //__BINARYSEARCH_TREE_H_