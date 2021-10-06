#include <stdio.h>
#include <stdlib.h>
struct data_info
{
    int data;
    struct data_info *next;
};
typedef struct data_info NODE;
void Display_LinkList(NODE *tail)
{
    NODE *p;
    
    for(p=tail->next->next;p !=tail->next;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}
// void Sort_LinkList(NODE *tail)
// {
//     printf("开始排序");
//     NODE *p=tail->next->next;
//     NODE *q=p->next;
//     int s;
//     while(p != tail){
//         while(q->next != tail->next){
//             if(p->data > q->data){
//                 s=q->data;
//                 q->data=p->data;
//                 p->data=s;
//                 q=q->next;
//             }
//         }
//         p=p->next;
//     }
// }
NODE *Create_Linklist()
{
    NODE *head,*tail,*pnew;
    int data;char ch;
    head=(NODE *)malloc (sizeof(NODE));
    if(head==NULL){
        printf("no enough memory!\n");
        return (NULL);
    }
    head->next=NULL;
    tail=head;
    printf("input the data of node:\n");
    while(1){
        ch=getchar();
        if(ch!=' '&&ch!='\n'&&ch!='\r'&&(ch<'0'||ch>'9')){
            printf("输入非法");
            exit(-1);
        }
        if(ch=='\n'){
            break;
        }
        scanf("%d",&data);
        pnew=(NODE *)malloc(sizeof(NODE));
        if(pnew==NULL){
            printf("no enough memory!\n");
            return NULL;
        }
        pnew->data=data;
        pnew->next=head;

        tail->next=pnew;
        tail=pnew;
    }
    printf("创建完毕\n");fflush(stdin);
    return (tail);
}

int main(){
    NODE *pa,*pb,*s,*La,*Lb,*rc,*Lc;
    //创建链表LA,LB
    La=Create_Linklist();
    Lb=Create_Linklist();
//    Sort_LinkList(La);//排序la链表
    printf("La链表:");
    Display_LinkList(La);
//    Sort_LinkList(Lb);//排序lb链表
    printf("Lb链表:");
    Display_LinkList(Lb);

    pa=La->next->next;
    pb=Lb->next->next;
    rc=La->next;
    while(pa!=La->next && pb!=Lb->next){
        if(pa->data < pb->data){
            rc->next=pa;
            rc=pa;
            pa=pa->next;
        }
        else if(pa->data > pb->data){
            rc->next=pb;
            rc=pb;
            pb=pb->next;
        }
        else{
            rc->next=pa;
            rc=pa;
            pa=pa->next;
            
            s=pb;
            pb=pb->next;
            free(s);
        }
    }

    if(pb == Lb->next){
        rc->next=pa;
        Lc=La;
    }
    else if(pa == La->next){
        s=La->next;//书上有个小错误，加个s指针更正
        rc->next=pb;pb=Lb->next;
        Lb->next=s;La=Lb;
    }
    free(pb);

    printf("Lc链表:");
    Display_LinkList(La);

}
