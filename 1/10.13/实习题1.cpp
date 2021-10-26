#include <string.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>
#include "login.cpp"
using namespace std;
struct Goods
{
    int gid;
    char gname[20];
    double gprice;
    int gnum;
};
struct Node
{
    Goods good;
    Node *next;
};
int ListLenth = 1;
int buyLenth = 1;
int ifowner = -1;
Node *GList;
Node *Buy_List;

//用循环链表存储的
Node *CreatGList()
{
    Node *head, *tail, *pnew;
    double tmp;
    int num, falg = 1;
    char string[20];
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    tail = head;
    if (head == NULL)
    {
        printf("内存不足,链表创建失败");
        exit(-1);
    }

    while (falg == 1)
    {
        printf("请输入商品名称:");
        scanf("%s", string);
        printf("请输入商品单价:");
        scanf("%lf", &tmp);
        printf("请输入物品数量:");
        scanf("%d", &num);
        pnew = (Node *)malloc(sizeof(Node));
        if (head == NULL)
        {
            printf("内存不足,链表创建失败");
            exit(-1);
        }
        printf("1");
        pnew->good.gid = ListLenth;
        ListLenth++;
        strcpy(pnew->good.gname, string);
        pnew->good.gprice = tmp;
        pnew->good.gnum = num;

        tail->next = pnew;
        tail = tail->next;
        tail->next = head;

        printf("继续输入.......1|输入完毕.......0：");
        scanf("%d", &falg);
    }
    printf("创建完毕\n");
    fflush(stdin);
    return (head);
}
Node *List_index(Node *GList, char *s)
{
    Node *p;
    p = GList->next;
    while (p != GList)
    {
        if (strcmp(s, p->good.gname) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void showGoods(Node *List)
{
    Node *p;
    printf("\n今日商品详情\n");
    printf("||商品名     ||单价      ||数量      ||\n");
    for (p = List->next; p != List; p = p->next)
    {
        printf("||%3s       ||%.2f      ||%2d        ||\n", p->good.gname, p->good.gprice, p->good.gnum);
    }
    printf(".............................................\n");
}
void showBuygoods(Node *List)
{
    Node *p;
    double x = 0;
    double price;
    int n;
    printf("\n您所购买的商品\n");
    printf("||商品名     ||单价      ||数量      ||\n");
    for (p = List->next; p != NULL; p = p->next)
    {
        price = p->good.gprice;
        n = p->good.gnum;
        x += n * price;
        printf("||%3s       ||%.2f      ||%2d        ||\n", p->good.gname, price, n);
    }
    printf(".............................................\n");
    printf("您一共需要付: %3.2f 元", x);
    cout << "感谢您的购买，欢迎下次光临" << endl;
}
int buy()
{
    Buy_List = (Node *)malloc(sizeof(Node));
    Buy_List->next = NULL;
    char s[20];
    int n;
    int choose = 0;
    printf("请输入您要买的商品:");
    scanf("%s", s);
    printf("请输入购买数量:");
    scanf("%d", &n);
    Node *pnew, *p;
    p = List_index(GList, s);
    if (p == NULL)
    {
        cout << "本超市并未上架该物品，请联系管理员补货" << endl;
        return 0;
    }
    else if (p->good.gnum < n)
    {
        cout << "本超市该物品数量不足，请联系管理员补货" << endl;
        return 0;
    }
    else
    {
        cout << "已经添加到购物车" << endl;
    }
    p->good.gnum -= n;
    pnew = (Node *)malloc(sizeof(Node));
    strcpy(pnew->good.gname, s);
    pnew->good.gid = buyLenth;
    buyLenth++;
    pnew->good.gnum = n;
    pnew->good.gprice = p->good.gprice;
    p = Buy_List->next;
    Buy_List->next = pnew;
    pnew->next = p;
    cout << "继续购买.......1 / 结账..........0 :";
    cin >> choose;
    if (choose)
    {
        buy();
    }
    else
    {
        showBuygoods(Buy_List);
    }
    return 1;
}
void opList_customer()
{
    int i;
    printf("\n--欢迎来到本超市--\n");
    printf("\t--1.购买商品--\n");
    printf("\t--2.结账离开--\n");
    printf("\t--------------\n");
    printf("请选择操作:");
    cin >> i;
    if (i == 1)
    {
        buy();
    }
    else
    {
        cout << "谢谢您的光顾，欢迎下次再来" << endl;
    }
}
void opList_owner()
{
    int i;
lable: 
    printf("\t.....1.初始化超市商品........\n");
    printf("\t.....2.补     货........... \n");
    printf("\t.....3.修     改........... \n");
    printf("\t.....4.退出 登录........... \n");
    printf(".................................\n");
    cout << "请选择你的操作:";
    cin >> i;
    switch(i){
        case 1:
            GList=CreatGList();
            showGoods(GList);
            goto lable;
            break;
        case 2:
            break;
    }
}

int main()
{
    int c;
    initUser();
    cout << "欢迎来到本超市"<<endl;;
lab:
    cout<<"1.......登录"<<endl;
    cout<<"2.......注册"<<endl;
    cout<<"3.......退出"<<endl;
    cin >> c;
    if (c == 0)
    {
        regest_user();
        goto lab;
    }
    else if (c == 1)
    {
        ifowner = login();
        if (ifowner == -1)
        {
            goto lab;
        }
    }
    else if(c == 3){
        cout<<"欢迎下次光临"<<endl;
        exit(-1);
    }
    switch (ifowner)
    {
    case 0:
        showGoods(GList);
        opList_customer();
        break;
    case 1:
        opList_owner();
        break;
    }

    return 0;
}