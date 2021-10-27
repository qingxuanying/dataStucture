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
//int moner = 0;
Node *GList;
Node *Buy_List;
char *filename;
char *userFile;
void userListtoFile(char *userFile);
void Goodstofile(char *filename)
{
    FILE *w;
    Node *p = GList->next;
    if ((w = fopen(filename, "wb")) == NULL)
    { /*二进制只写打开文件*/
        printf("cannot open file\n");
        exit(1);
    }
    cout << "正在保存数据" << endl;
    for (int i = 0; i < ListLenth - 1; i++) //链表数据循环输入到文件内
    {
        fprintf(w, "%d ", p->good.gid);
        fprintf(w, "%s ", p->good.gname);
        fprintf(w, "%d ", p->good.gnum);
        fprintf(w, "%f", p->good.gprice);
        p = p->next;
    }
    fclose(w);
}
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
        Goodstofile(filename);
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
            Goodstofile(filename);
            exit(-1);
        }
       // printf("1");
        pnew->good.gid = ListLenth;
        ListLenth++;
        strcpy(pnew->good.gname, string);
        pnew->good.gprice = tmp;
        pnew->good.gnum = num;

        tail->next = pnew;
        tail = tail->next;
        tail->next = NULL;

        printf("继续输入.......1|输入完毕.......0：");
        scanf("%d", &falg);
    }
    printf("创建完毕\n");
    fflush(stdin);
    return (head);
}
Node *List_index(Node *List, char *s)
{
    Node *p;
    p = List->next;
    while (p != NULL)
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
    printf("||商 品 名     ||单价      ||数量      ||\n");
    for (p = List->next; p != NULL; p = p->next)
    {
        printf("||%5s     ||%.2f      ||%2d        ||\n", p->good.gname, p->good.gprice, p->good.gnum);
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
    Goodstofile(filename);
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
    Node *pnew;
    Node *p = NULL;
    if (List_index(GList, s))
    {
        p = List_index(GList, s);
    }
    if (p == NULL)
    {
        cout << "本超市并未上架该物品，请联系管理员补货" << endl;
        buy();
        return 0;
    }
    else if (p->good.gnum < n)
    {
        cout << "本超市该物品数量不足，请联系管理员补货" << endl;
        buy();
        return 0;
    }
    else
    {
        cout << "已经添加到购物车" << endl;
    }
    if (List_index(Buy_List, s) != NULL)
    {
        cout<<"重复购买，自动添加"<<endl;
        pnew = List_index(Buy_List, s);
        pnew->good.gnum += n;
        p->good.gnum -= n;
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
lb:
    printf("\t--1.购买商品--\n");
    printf("\t--2.查看商品--\n");
    printf("\t--3.离开--\n");
    printf("\t--------------\n");
    printf("请选择操作:");
    cin >> i;
    if (i == 1)
    {
        buy();
    }
    else if (i == 2)
    {
        showGoods(GList);
        goto lb;
    }
    else
    {
        userListtoFile(userFile);
        cout << "谢谢您的光顾，欢迎下次再来" << endl;
    }
}
void addgoods()
{
    char name[20];
    int n;
    int falg;
    Node *p = NULL;
    cout << "输入你要补的货物:";
    scanf("%s", name);
    cout << "要补的数量:";
    scanf("%d", &n);
    p = List_index(GList, name);
    if (p == NULL)
    {
        int price;
        cout << "清单中无此物品，正在为您添加" << endl;
        cout << "请输入该商品单价:";
        cin >> price;
        p = (Node *)malloc(sizeof(Node));
        p->good.gid = ListLenth;
        ListLenth++;
        strcpy(p->good.gname, name);
        p->good.gnum = n;
        p->good.gprice = price;

        p->next = GList->next;
        GList->next = p;
    }
    else
    {
        p->good.gnum += n;
    }
    cout << "继续补货........1/停止补货..........0" << endl;
    cin >> falg;
    if (falg == 1)
    {
        addgoods();
    }
}
void fixgoods()
{
    char name[20];
    cout << "输入你要修改的商品名:";
    scanf("%s", name);
    Node *p;
    p = List_index(GList, name);
    if (p == NULL)
    {
        cout << "在列表里未查找到对应商品" << endl;
        fixgoods();
    }
    else
    {
        int price;
        int n;
        char name2[20];
        cout << "修改后端名称:";
        scanf("%s", name2);
        strcpy(p->good.gname, name2);
        cout << "修改后的单价:";
        cin >> price;
        cout << "修改后的数量:";
        cin >> n;
        p->good.gprice = price;
        p->good.gnum = n;
    }
}
void opList_owner()
{
    int i;
lables:
    printf("\t.....1.初始化超市商品........\n");
    printf("\t.....2.补     货........... \n");
    printf("\t.....3.修     改........... \n");
    printf("\t.....4.展示 商品........... \n");
    printf("\t.....5.退出 登录........... \n");
    printf(".................................\n");
    cout << "请选择你的操作:";
    cin >> i;
    switch (i)
    {
    case 1:
        GList = CreatGList();
        showGoods(GList);
        goto lables;
        break;
    case 2:
        addgoods();
        goto lables;
        break;
    case 3:
        fixgoods();
        goto lables;
        break;
    case 4:
        showGoods(GList);
        goto lables;
        break;
    case 5:
        cout << "感谢你的使用" << endl;
        userListtoFile(userFile);
        Goodstofile(filename);
        exit(-1);
    }
}
int Goodsgetfromfile(char *filename)
{
    FILE *fp;
    GList = (Node *)malloc(sizeof(Node));
    GList->next = NULL;
    int gid;
    char name[20];
    int gnum;
    double gprice;
    int flag;
    Node *p = GList->next;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("cannot open file\n");
        return 0;
    }

    while (1)
    {
        if (feof(fp))
        {
            break;
        }
        //cout << "正在写入" << endl;
        fscanf(fp, "%d", &gid);
        fscanf(fp, "%s", name);
        fscanf(fp, "%d", &gnum);
        fscanf(fp, "%lf", &gprice);
        Node *pnew = (Node *)malloc(sizeof(Node));
        pnew->good.gid = gid;
        strcpy(pnew->good.gname, name);
        pnew->good.gnum = gnum;
        pnew->good.gprice = gprice;
        pnew->next = GList->next;
        GList->next = pnew;
        ListLenth++;
    }
    fclose(fp);
    return 1;
}
void userListtoFile(char *userFile)
{
    FILE *w;
    uNode *p = ulist->next;
    if ((w = fopen(userFile, "wb")) == NULL)
    { /*二进制只写打开文件*/
        printf("cannot open file\n");
        exit(1);
    }
    cout << "正在保存用户数据" << endl;
    while (p != NULL)
    {
        fprintf(w, "%d ", p->user.ifowner);
        fprintf(w, "%s ", p->user.name);
        fprintf(w, "%s ", p->user.password);
        p = p->next;
    }
    fclose(w);
}
int getUserList(char *userFile)
{
    FILE *fp;
    int ifowner; //0普通用户 1管理员 2超级管理员
    char name[20];
    char password[20];
    if ((fp = fopen(userFile, "r")) == NULL)
    {
        printf("cannot open file\n");
        return 0;
    }
    ulist->next = NULL;
    while (1)
    {
        if (feof(fp))
        {
            break;
        }
        //cout << "正在写入" << endl;
        fscanf(fp, "%d", &ifowner);
        fscanf(fp, "%s", name);
        fscanf(fp, "%s", password);
        uNode *pnew = (uNode *)malloc(sizeof(uNode));
        pnew->user.ifowner = ifowner;
        strcpy(pnew->user.name, name);
        strcpy(pnew->user.password, password);
        pnew->next = ulist->next;
        ulist->next = pnew;
    }
    fclose(fp);
    return 1;
}
void addowner()
{
    char name[20];
    char password[20];
    cout << "请输入账号/用户名:";
    cin >> name;
    cout << "请输入密码:";
    cin >> password;
    uNode *p, *pnew;
    pnew = (uNode *)malloc(sizeof(uNode));
    strcpy(pnew->user.password, password);
    strcpy(pnew->user.name, name);
    pnew->user.ifowner = 1;

    p = ulist->next;

    pnew->next = p;
    ulist->next = pnew;
    cout << "添加完成";
}
void opList_superowner()
{
    int i;
lables2:
    printf("\t.....1.初始化超市商品........\n");
    printf("\t.....2.补     货........... \n");
    printf("\t.....3.修     改........... \n");
    printf("\t.....4.增设管理员........... \n");
    printf("\t.....5.展示 商品........... \n");
    printf("\t.....6.退出 登录........... \n");
    printf(".................................\n");
    cout << "请选择你的操作:";
    cin >> i;
    switch (i)
    {
    case 1:
        GList = CreatGList();
        showGoods(GList);
        goto lables2;
        break;
    case 2:
        addgoods();
        goto lables2;
        break;
    case 3:
        fixgoods();
        goto lables2;
        break;
    case 4:
        addowner();
        goto lables2;
        break;
    case 5:
        showGoods(GList);
        goto lables2;
        break;
    case 6:
        cout << "感谢你的使用" << endl;
        ;
        Goodstofile(filename);
        userListtoFile(userFile);
        exit(-1);
    }
}
int main()
{
    int c;
    initUser();
    filename = new char[20];
    userFile = new char[20];
    strcpy(filename, "goodsList.txt");
    strcpy(userFile, "userdata.txt");
    cout << "正在加载" << endl;
    Goodsgetfromfile(filename);
    getUserList(userFile);
    cout << "欢迎来到本超市" << endl;
    ;
lab:
    cout << "1.......登录" << endl;
    cout << "2.......注册" << endl;
    cout << "3.......退出" << endl;
    cin >> c;
    if (c == 2)
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
    else if (c == 3)
    {
        cout << "欢迎下次光临" << endl;
        exit(-1);
    }
    switch (ifowner)
    {
    case 0:
        showGoods(GList);
        opList_customer();
        break;
    case 1:
        showGoods(GList);
        opList_owner();
        break;
    case 2:
        showGoods(GList);
        opList_superowner();
        break;
    }
    return 0;
}