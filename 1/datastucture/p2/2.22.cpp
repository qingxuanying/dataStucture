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

int ListOppose_L(LinkList &L)
{
    LinkList p, q;
    p = L;
    p = p->next;
    L->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
    return 1;
}