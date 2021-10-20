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

void MergeList_L(LinkList &ha,LinkList &hb,LinkList &hc)
{
    LinkList pa,pb;
    pa=ha;
    pb=hb;
    while(pa->next&&pb->next){
        pa=pa->next;
        pb=pb->next;
    }
    if(!pa->next){
        hc=hb;
        while(pb->next) pb=pb->next;
        pb->next=ha->next;
    }
    else{
        hc=ha;
        while(pa->next) pa=pa->next;
        pa->next=hb->next;
    }
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
    MergeList_L(la,lb,lc);
    cout<<lc->next->data<<lc->next->next->data<<lc->next->next->next->data<<endl;
}