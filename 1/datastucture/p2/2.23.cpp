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
int main(){
    LinkList la,lb,lc;
    la=new LNode;
    lb=new LNode;
    lc=new LNode;
    la->next=new LNode;
    la->next->data=1;
    la->next->next=new LNode;
    la->next->next->data=3;
    lb->next=new LNode;
    lb->next->data=2;
    ListMerge_L(la,lb,lc);
    cout<<lc->next->data<<lc->next->next->data<<lc->next->next->next->data<<endl;
}