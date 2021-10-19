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
void ListDelete_LSameNode(LinkList &L)
{
    LinkList p, q, prev;
    p = L;
    prev = p;
    p = p->next;
    while (p)
    {
        prev = p;
        p = p->next;
        if (p && p->data == prev->data)
        {
            prev->next = p->next;
            q = p;
            p = p->next;
            free(q);
        }
    }
}
int main(){
    return 0;
}