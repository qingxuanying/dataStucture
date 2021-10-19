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

int compareList(SqList &A,SqList &B){
    int i,k,j;
    k=A.length > B.length?A.length:B.length;
    for(i=0;i<k;i++){
        if(A.elem[i]>B.elem[i]) j=1;
        if(A.elem[i]<B.elem[i]) j=-1;
    }
    if(A.length>k) {
        j=1;
    }
    if(B.length>k){
        j=-1;
    }
    if(A.length==B.length){
        j=0;
    }
    return j;
}