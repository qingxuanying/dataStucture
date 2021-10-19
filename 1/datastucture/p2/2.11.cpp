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

int InsertOrderList(SqList &va,int x)
{
//在非递减的顺序表 va 中插入元素 x 并使其仍成为顺序表的算法
//从后遍历将前一个值赋予后一个直到x的位置
    int i;
    if(va.length==va.listsize){
        return(-1);}
    for(i=va.length;i>0,x<va.elem[i-1];i--){
        va.elem[i]=va.elem[i-1];
    }
    va.elem[i]=x;
    va.length++;
    return 1;
}