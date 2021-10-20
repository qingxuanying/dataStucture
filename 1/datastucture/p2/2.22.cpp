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
int main(){
    LinkList la=new LNode;
    la->data=0;
    la->next=new LNode;
    la->next->data=1;
    la->next->next=new LNode;
    la->next->next->data=2;
    la->next->next->next=new LNode;
    la->next->next->next->data=3;
    la->next->next->next->next=NULL;
    ListOppose_L(la);
    cout<<la->next->data<<endl;
}