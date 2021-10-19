#include <iostream>
#include <stdlib.h>
using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10;

typedef struct
{
    int *elem;
    ;
    int length;
    int listsize;
} SqList;
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
int ListDelete_L(LinkList &L, int mink, int maxk)
{
    LinkList p, q, prev = NULL;
    if (mink > maxk)
        return 0;
    p = L;
    prev = p;
    p = p->next;
    while (p && p->data < maxk)
    {
        if (p->data <= mink)
        {
            prev = p;
            p = p->next;
        }
        else
        {
            prev->next = p->next;
            q = p;
            p = p->next;
            free(q);
        }
    }
    return 1;
}
int main(){
    return 0;
}