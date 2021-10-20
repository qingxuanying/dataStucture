#include <iostream>
#include <stdlib.h>
using namespace std;
#define MaxQSize 4
typedef int ElemType;
typedef struct
{
    ElemType *base;
    int rear;
    int length;
} Queue;
int InitQueue(Queue &q)
{
    q.base = new ElemType[MaxQSize];
    if (!q.base)
        return 0;
    q.rear = 0;
    q.length = 0;
    return 1;
}
int EnQueue(Queue &q, ElemType e)
{
    if ((q.rear + 1) % MaxQSize == (q.rear + MaxQSize - q.length) % MaxQSize)
        return 0;
    else
    {
        q.base[q.rear] = e;
        q.rear = (q.rear + 1) % MaxQSize;
        q.length++;
    }
    return 1;
}
int DeQueue(Queue &q, ElemType &e)
{
    if ((q.rear + MaxQSize - q.length) % MaxQSize == q.rear)
        return 0;
    else
    {
        e = q.base[(q.rear + MaxQSize - q.length) % MaxQSize];
        q.length--;
    }
    return 1;
}