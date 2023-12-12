#include "sequenceTable.h"
#include <stdlib.h>

typedef enum STATUS
{
    NO_LOCATE = -5,
    ON_EMPTY,
    ON_FULL,
    ON_ILLEGAL,
    ON_ERROR,
    ON_SUCCESS,
}STATUS;

int InitList(seqList *L, int num)
{
    L->data = (ElenType *)malloc(sizeof(ElenType) * num);
    if(!L->data)
    {
        return ON_ERROR;
    }

    L->lenth = 0;
    L->MAX_SIZE = num;

    return ON_SUCCESS;
}

int InsertList(seqList * L, const int site, const int num)
{
    /* 判断插入位置是否合法 */
    if((site < 1) || (site > L->lenth + 1))
    {
        return ON_ILLEGAL;
    }

    /* 判断表是不是满的 */
    if(L->lenth >= L->MAX_SIZE)
    {
        return ON_FULL;
    }

    /* 插入数据 */
    for(int idx = L->lenth - 1; idx >= site - 1; idx--)
    {
        L->data[idx + 1] = L->data[idx];
    }

    L->data[site - 1] = num;
    L->lenth++;

    return ON_SUCCESS;
}

int delateList(seqList *L, const int site, int *num)
{
    /* 判断输入是否合法 */
    if((site > L->lenth) || (site < 1))
    {
        return ON_ILLEGAL;
    }

    if(L->lenth == 0)
    {
        return ON_EMPTY;
    }

    /* 删除指定位置的值 */
    *num = L->data[site - 1];
    for(int idx = site; idx < L->lenth; idx++)
    {
        L->data[idx - 1] = L->data[idx];
    }

    L->lenth--;

    return ON_SUCCESS;
}

int orderSearch(seqList *L, const int site)
{
    if((site < 1) || (site > L->lenth))
    {
        return ON_ILLEGAL;
    }

    return L->data[site - 1];
}

int locateList(seqList *L, const int num)
{
    for(int idx = 0; idx < L->lenth; idx++)
    {
        if(L->data[idx] == num)
        {
            return idx + 1;
        }
    }

    return NO_LOCATE;
}

int increaseList(seqList *L, const int len)
{
    int * ptr = L->data;

    /* 为表重新申请一个空间 */
    L->data = (ElenType *)malloc(sizeof(ElenType) * (L->MAX_SIZE + len));
    for(int idx = 0; idx < L->lenth; idx++)
    {
        L->data[idx] = ptr[idx];
    }

    L->MAX_SIZE = L->MAX_SIZE + len;
    free(ptr);

    return ON_SUCCESS;
}
