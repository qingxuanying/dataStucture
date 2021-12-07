#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include "getAMaze.cpp"
using namespace std;

int m[10][20];
int route=-1

;
void initm(){
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            m[10][20]=0;
        }
    }
}
int dfs(int i,int j,int k){
    m[i][j]==1;
    if(i==9 && j==19){
        route=k;
        return k;
    }
    else{
        if(m[i][j+1]==0 && maze[i][j+1]==0){
            dfs(i,j+1,k+1);
        }
        if(m[i+1][j]==0 && maze[i+1][j]==0){
            dfs(i+1,j,k+1);
        }
    }
}
int main(){
    getAmaze();
    int min=0;
    min=dfs(0,0,0);
    cout<<endl;
    cout<<min<<endl;
    cout<<route<<endl;
}