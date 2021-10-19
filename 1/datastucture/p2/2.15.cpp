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