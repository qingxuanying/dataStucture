#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

static int maze[10][20];

void initMaze(){
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            maze[i][j]=3;
        }
    }
}
int GETmazeWithprice(){
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            maze[i][j]=rand()%2;
        }
    }
}
//将迷宫剩余未被访问过的改为1
void initplus(){
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            if(maze[i][j]==3){
                maze[i][j]=1;
            }
        }
    }
}
//生成一个不带权值的迷宫
int GETmaze(int i, int j){
    maze[i][j]=0;
    if(i==9&&j==19){
        return 0;
    }
    else{
    label:
        int k=rand() %8;
        int m=0;int n=0;
        switch(k){
            case 0:m=i-1;n=j-1;break;
            case 1:m=i-1;n=j;break;
            case 2:m=i-1;n=j+1;break;
            case 3:m=i;n=j-1;break;
            case 4:m=i+1;n=j+1;break;
            case 5:m=i;n=j+1;break;
            case 6:m=i+1;n=j-1;break;
            case 7:m=i+1;n=j;break;
        }
        if(m<0){
            m=0;
        }
        if(m>=10){
            m=9;
        }
        if(n<0){
            n=0;
        }
        if(n>=20){
            n=19;
        }
        //cout<<m<<" "<<n<<endl;
        
        GETmaze(m,n);
    }
    initplus();
    return 0;
}


//输出迷宫矩阵
void displayMaze(){
    for(int i=0;i<10;i++){
        cout<<endl;
        for(int j=0;j<20;j++){
            cout<<maze[i][j];
        }
    }
}

int getAmaze(){
    srand(time(NULL));
    initMaze();
    GETmaze(0,0);
    //GETmazeWithprice();
    displayMaze();
}