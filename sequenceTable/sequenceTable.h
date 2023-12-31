#ifndef __SEQUENCE_TABLE_H_
#define __SEQUENCE_TABLE_H_

typedef int ElenType;

typedef struct seqList
{
    ElenType * data;
    int lenth;
    int MAX_SIZE;
} seqList;

/* 初始化顺序表 */
int InitList(seqList * pList);

/* 顺序表的插入 */
int InsertList(seqList * pList, const int site, const int num);

/* 顺序表的删除 */
int delateList(seqList * pList, const int site, int *num);

/* 按序查找 */
int orderSearch(seqList * pList, const int site);

/* 按值查找 */
int locateList(seqList * pList, const int num);

/* 增加表的长度 */
int increaseList(seqList * pList,const int len);

#endif //__SEQUENCE_TABLE_H_