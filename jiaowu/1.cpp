#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <malloc.h>
using namespace std;
#include <vector>
#define N 1000
#define MAX_VERTEX_NUM 30

typedef int VertexType;

typedef struct ArcNode {
    int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode* firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

typedef int SElemType;

typedef struct {
    SElemType* elem;
    int top;
    int stacksize;
}Stack;

void InitStack(Stack& s)
{
    s.elem = new SElemType[N];
    s.top = 0;
    s.stacksize = N;
}

void ClearStack(Stack& s)
{
    s.top = 0;
}
bool StackEmpty(Stack s)
{
    if (s.top == 0)
        return 1;
    else
        return 0;
}

bool CopyStack(Stack& S1, Stack& S2)//S2复制给S1
{
    for (int i = 0; i <= S2.top; i++)
        S1.elem[i] = S2.elem[i];
    S1.top = S2.top;
    return 1;
}

void Push(Stack& s, SElemType e)
{
    s.elem[s.top++] = e;
}

bool Pop(Stack& s, SElemType& e)
{
    if (s.top == 0)
        return 0;
    e = s.elem[--s.top];
    return 1;
}

string course[MAX_VERTEX_NUM];
int indegree[MAX_VERTEX_NUM];

// 利用邻接表来构造有向图，course[]记录课程名称，indegree[]记录入度
void CreateDG(ALGraph & G)
{
	cout << "请输入课程名称，#号结束" << endl;
	int i = 0;
	cin >> course[i];

	while (strcmp(course[i].c_str(), "#") != 0)
		cin >> course[++i];

	G.vexnum = i;
	for (i = 0; i < G.vexnum; i++)//构造表头向量
	{
		G.vertices[i].firstarc = NULL;
	}
	for (i = 0; i < G.vexnum; i++)
	{
		cout << i + 1 << ":" << course[i] << endl;//显示课程编号
	}
	for (i = 0; i < G.vexnum; i++)
	{
		indegree[i] = 0;//入读初始化
	}
	cout << "请输入有序序列 v1-->v2(以0 0结束)" << endl;
	VNode v1, v2;
	cin >> v1.data >> v2.data;
	while ((v1.data > 0) && (v2.data > 0))//(0,0)结束
	{
		ArcNode* pi = (ArcNode*)malloc(sizeof(ArcNode));
		pi->adjvex = v2.data - 1;//邻接点的位置信息
		pi->nextarc = G.vertices[v1.data - 1].firstarc;//插入链表
		G.vertices[v1.data - 1].firstarc = pi;
		G.arcnum++;
		indegree[v2.data - 1]++;
		cin >> v1.data >> v2.data;
	}
}

void TopoSet(ALGraph G)
{
	int count = 0;//对输出的顶点计数
	Stack S1, S2;
	InitStack(S1);
	InitStack(S2);
	for (int i = 0; i < G.vexnum; i++)
	{
		if (indegree[i] == 0) Push(S1, i);//入度为0进S1
	}
	int term = 1;
	cout << term << " TERM:" << endl;
	while ((!StackEmpty(S1)) || (!StackEmpty(S2)))
	{
		if ((StackEmpty(S1)) || (!StackEmpty(S2)))
		{
			CopyStack(S1, S2);
			ClearStack(S2);
			term++;//新学期
			cout << term << " TERM:" << endl;
		}
		//p = new ArcNode;
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
		SElemType v;
		Pop(S1, v);
		++count;
		cout << course[v] << endl;//输出对应课程

		for (p = G.vertices[v].firstarc; p; p = p->nextarc)
		{
			int w = p->adjvex;
			--indegree[w];
			if (!indegree[w])
				Push(S2, w);//新产生的入度为0的点进入S2
		}
	}

	if (count < G.vexnum)
		cout << "图有环路" << endl;
}

int main()
{
	ALGraph G;
	CreateDG(G);
	cout << "拓扑排序结果：" << endl;
	TopoSet(G);
	return 0;
}