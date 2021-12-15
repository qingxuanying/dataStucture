#include <stdio.h>
#include <assert.h>

typedef int DataType;

typedef struct LinkNode
{
    DataType data;
    struct LinkNode *next;
} LinkNode, *pLinkNode; //结点结构体

typedef struct LinkList
{
    LinkNode *pHead;             //头结点指针
} LinkList, *pLinkList;          //链表
void SelectSort(pLinkList pList) //选择排序单链表
{
    pLinkNode p = NULL;
    pLinkNode q = NULL;
    assert(pList);

    for (p = pList->pHead; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next) //找最小的结点
        {
            if (p->data > q->data) 
            {
                DataType tmp = q->data;
                q->data = p->data;
                p->data = tmp;
            }
        } 
    }
}
int main(){
    
}