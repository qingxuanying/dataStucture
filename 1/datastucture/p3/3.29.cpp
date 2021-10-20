#include <iostream>
#include <stdlib.h>
using namespace std;
#define MaxQSize 4
typedef int ElemType;
typedef struct
{
    ElemType *base;
    int front;
    int rear;
    int tag;
} Queue;
int InitQueue(Queue &q)
{
    q.base = new ElemType[MaxQSize];
    if (!q.base)
        return 0;
    q.front = 0;
    q.rear = 0;
    q.tag = 0;
    return 1;
}
int EnQueue(Queue &q, ElemType e)
{
    if (q.front == q.rear && q.tag)
        return 0;
    else
    {
        q.base[q.rear] = e;
        q.rear = (q.rear + 1) % MaxQSize;
        if (q.rear == q.front)
            q.tag = 1;
    }
    return 1;
}
int DeQueue(Queue &q, ElemType &e)
{
    if (q.front == q.rear && !q.tag)
        return 0;
    else
    {
        e = q.base[q.front];
        q.front = (q.front + 1) % MaxQSize;
        q.tag = 0;
    }
    return 1;
}