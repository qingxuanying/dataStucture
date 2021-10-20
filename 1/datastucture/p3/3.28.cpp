#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct NodeType
{
    int data;
    NodeType *next;
} QNode, *QPtr;
typedef struct
{
    QPtr rear;
    int size;
} Queue;
int InitQueue(Queue &q)
{
    q.rear = NULL;
    q.size = 0;
    return 1;
}
//入列
int EnQueue(Queue &q, int e)
{
    QPtr p;
    p = new QNode;
    if (!p)
        return 0;
    p->data = e;
    if (!q.rear)
    {
        q.rear = p;
        p->next = q.rear;
    }
    else
    {
        p->next = q.rear->next;
        q.rear->next = p;
        q.rear = p;
    }
    q.size++;
    return 1;
}
//出列
int DeQueue(Queue &q, int &e)
{
    QPtr p;
    if (q.size == 0)
        return 0;
    if (q.size == 1)
    {
        p = q.rear;
        e = p->data;
        q.rear = NULL;
        delete p;
    }
    else
    {
        p = q.rear->next;
        e = p->data;
        q.rear->next = p->next;
        delete p;
    }
    q.size--;
    return 1;
}