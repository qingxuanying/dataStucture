#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
struct Goods {
    int gid;
    char gname[20];
    double gprice;
    int gnum;
};
struct Node {
    Goods good;
    Node * next;
};
int ListLenth=1;
Node *GList;

//用循环链表存储的
Node * CreatGList(){
    Node *head,*tail,*pnew;
    double tmp;
    int num,falg=1;
    char string[20];
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    tail = head;
    if(head == NULL){
        printf("内存不足,链表创建失败");
        exit(-1);
    }
    
    while(falg==1){
        printf("请输入商品名称:");
        scanf("%s",string);
        printf("请输入商品单价:");
        scanf("%lf",&tmp);
        printf("请输入物品数量:");
        scanf("%d",&num);
        pnew = (Node*)malloc(sizeof(Node));
        if(head == NULL){
            printf("内存不足,链表创建失败");
            exit(-1);
        }
        printf("1");
        pnew->good.gid = ListLenth;
        ListLenth++;
        strcpy(pnew->good.gname,string);
        pnew->good.gprice = tmp;
        pnew->good.gnum = num;

        tail->next = pnew;
        tail = tail->next;
        tail->next=head;

        printf("是否继续输入？ 是.......1|否.......0");
        scanf("%d",&falg);
    }
    printf("创建完毕\n");fflush(stdin);
    return (head);
}

void showGoods(Node *List){
    Node *p;
    printf("\n今日商品详情\n");
    printf("||商品名     ||单价      ||数量      ||\n");
    for(p=List->next;p != List;p=p->next){
        printf("||%3s       ||%.2f      ||%2d        ||\n",p->good.gname,p->good.gprice,p->good.gnum);
    }
    printf(".............................................\n");
}

void sortGoodsByPrice(Node *List){
    Node *p,*q,*pre,*qre;
    pre=List;
    qre=List->next;
    for(p=List->next;p->next != List ; p=p->next){
        for()
    }
};
void opList_customer(){
    int i;
    printf("\n--欢迎来到本超市--\n");
    printf("--1.购买商品--\n");
    printf("--2.结账离开--\n");
    printf("请选择操作:");
    cin>>i;
    if(i==1){

    }
    else{

    }
}
int main(){
    GList = CreatGList();
    showGoods(GList);
    return 0;
}