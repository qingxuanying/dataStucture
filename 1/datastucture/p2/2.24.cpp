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
int ListMergeOppose_L(LinkList &A, LinkList &B, LinkList &C)
{
    LinkList pa, pb, qa, qb;
    pa = A;
    pb = B;
    qa = pa; // 保存 pa 的前驱指针
    qb = pb; // 保存 pb 的前驱指针
    pa = pa->next;
    pb = pb->next;
    A->next = NULL;
    C = A;
    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            qa = pa;
            pa = pa->next;
            qa->next = A->next; //将当前最小结点插入 A 表表头
            A->next = qa;
        }
        else
        {
            qb = pb;
            pb = pb->next;
            qb->next = A->next; //将当前最小结点插入 A 表表头
            A->next = qb;
        }
    }
    while (pa)
    {
        qa = pa;
        pa = pa->next;
        qa->next = A->next;
        A->next = qa;
    }
    while (pb)
    {
        qb = pb;
        pb = pb->next;
        qb->next = A->next;
        A->next = qb;
    }
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
    ListMergeOppose_L(la,lb,lc);
    cout<<lc->next->data<<lc->next->next->data<<lc->next->next->next->data<<endl;
}