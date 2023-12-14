#include "sequenceTable.h"
#include <stdlib.h>

#define DEFAULT_SIZE 10

typedef enum STATUS
{
    NO_LOCATE = -5,
    ON_EMPTY,
    ON_FULL,
    ON_ILLEGAL,
    ON_ERROR,
    ON_SUCCESS,
}STATUS;

int InitList(seqList *pList)
{
    pList->data = (ElenType *)malloc(sizeof(ElenType) * DEFAULT_SIZE);
    if(!pList->data)
    {
        return ON_ERROR;
    }

    pList->lenth = 0;
    pList->MAX_SIZE = DEFAULT_SIZE;

    return ON_SUCCESS;
}

int InsertList(seqList * pList, const int site, const int num)
{
    /* 判断插入位置是否合法 */
    if((site < 1) || (site > pList->lenth + 1))
    {
        return ON_ILLEGAL;
    }

    /* 判断表是不是满的 */
    if(pList->lenth >= pList->MAX_SIZE)
    {
        return ON_FULL;
    }

    /* 插入数据 */
    for(int idx = pList->lenth - 1; idx >= site - 1; idx--)
    {
        pList->data[idx + 1] = pList->data[idx];
    }

    pList->data[site - 1] = num;
    pList->lenth++;

    return ON_SUCCESS;
}

int delateList(seqList *pList, const int site, int *num)
{
    /* 判断输入是否合法 */
    if((site > pList->lenth) || (site < 1))
    {
        return ON_ILLEGAL;
    }

    if(pList->lenth == 0)
    {
        return ON_EMPTY;
    }

    /* 删除指定位置的值 */
    *num = pList->data[site - 1];
    for(int idx = site; idx < pList->lenth; idx++)
    {
        pList->data[idx - 1] = pList->data[idx];
    }

    pList->lenth--;

    return ON_SUCCESS;
}

int orderSearch(seqList *pList, const int site)
{
    if((site < 1) || (site > pList->lenth))
    {
        return ON_ILLEGAL;
    }

    return pList->data[site - 1];
}

int locateList(seqList *pList, const int num)
{
    for(int idx = 0; idx < pList->lenth; idx++)
    {
        if(pList->data[idx] == num)
        {
            return idx + 1;
        }
    }

    return NO_LOCATE;
}

int increaseList(seqList *pList, const int len)
{
    int * ptr = pList->data;

    /* 为表重新申请一个空间 */
    pList->data = (ElenType *)malloc(sizeof(ElenType) * (pList->MAX_SIZE + len));
    for(int idx = 0; idx < pList->lenth; idx++)
    {
        pList->data[idx] = ptr[idx];
    }

    pList->MAX_SIZE = pList->MAX_SIZE + len;
    free(ptr);

    return ON_SUCCESS;
}
