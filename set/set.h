#ifndef __SET_H_
#define __SET_H_

#define ELEMENTTYPE void *

typedef struct setNode
{
    ELEMENTTYPE val;
    /* 结点高度 */
    int height;
    struct setNode * lchild;   /* 左子树 */
    struct setNode * rchild;  /* 右子树 */
    struct setNode * parent; /* 父结点 */

}setNode;

typedef struct set
{
    setNode * root;
    int size;
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);
} set;


/* 集合的初始化 */
int setInit(set ** pSet, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 在集合中插入数据 */
int setInsert(set * pSet, ELEMENTTYPE * val);



#endif //__SET_H_