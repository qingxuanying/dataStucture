#include <iostream>
#include <stdlib.h>
using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10;

typedef struct{
    int *elem;;
    int length;
    int listsize;
}SqList ;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

int ListMerge_L(LinkList &A, LinkList &B, LinkList &C)
{
    LinkList pa, pb, qa, qb;
    pa = A->next;
    pb = B->next;
    C = A;
    while (pa && pb)
    {
        qa = pa;
        qb = pb;
        pa = pa->next;
        pb = pb->next;
        qb->next = qa->next;
        qa->next = qb;
    }
    if (!pa)
        qb->next = pb;
    pb = B;
    free(pb);
    return 1;
}