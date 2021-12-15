#include "node.cpp"
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

void dfs(vector<vector<Node*> > &ans,vector<Node*> &list,Node*** n,int** board,int x,int y);
void show(vector<vector<Node*> > &ans);
Node*** getRoot(int **nums);

int main(){
    int **nums = new int*[9];
    for(int i = 0 ; i< 9;i++){
        nums[i] = new int[12];
    }
    Node*** n = getRoot(nums);
    vector<vector<Node*> > ans;
    vector<Node*> list;
    dfs(ans,list,n,nums,0,0);
    show(ans);
    return 0;
}

Node*** getRoot(int **nums){
    fstream f;
    f.open("./map.txt",ios::in);
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0; j < 12 ;j++){
            f>>nums[i][j];
        }
    }
    f.close();
    Point***p = new Point**[9];
    Node*** n = new Node**[9];
    
    for(int i = 0 ; i < 9 ; i++){
        p[i] = new Point*[12];
        for(int j = 0 ; j < 12 ;j++){
            p[i][j] = new Point(i,j,nums[i][j]);
        }
    }
    for(int i = 0 ; i < 9;i++){
        n[i] = new Node*[12];
        for(int j = 0 ; j < 12 ; j++){
            n[i][j] = new Node(p[i][j]);
        }
    }
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 12 ;j++){
            if(i == 0){
                n[i][j]->setUp(NULL);
            }else{
                n[i][j]->setUp(n[i-1][j]);
            }
            if(j == 0){
                n[i][j]->setLeft(NULL);    
            }else{
                n[i][j]->setLeft(n[i][j-1]);  
            }
            if(i == 8){
                n[i][j]->setBottom(NULL);    
            }else{
                n[i][j]->setBottom(n[i+1][j]);  
            }
            if(j == 11){
                n[i][j]->setRight(NULL);    
            }else{
                n[i][j]->setRight(n[i][j+1]);  
            }
        }
    }
    return n;
}

void dfs(vector<vector<Node*> > &ans,vector<Node*> &list,Node***n,int **board,int x , int y){
    Node *p = n[x][y];
    if(x == 8 && y == 11){
        list.push_back(p);
        vector<Node*> l(list);
        ans.push_back(l);
        return;
    }else{
        if(x > 0){
            board[x][y] = 1;
            if(board[x -1][y] == 0){
                list.push_back(p);
                dfs(ans,list,n,board,x-1,y);
                list.pop_back();
            }
            board[x][y] = 0;
        }
        if(y > 0){
            board[x][y] = 1;
            if(board[x][y-1] == 0){
                list.push_back(p);
                dfs(ans,list,n,board,x,y-1);
                list.pop_back();
            }
            board[x][y] = 0;
        }
        if(x < 8){
            board[x][y] = 1;
            if(board[x +1][y] == 0){
                list.push_back(p);
                dfs(ans,list,n,board,x+1,y);
                list.pop_back();
            }
            board[x][y] = 0;
        }
        if(y < 11){
            board[x][y] = 1;
            if(board[x][y + 1] == 0){
                list.push_back(p);
                dfs(ans,list,n,board,x,y+1);
                list.pop_back();
            }
            board[x][y] = 0;
        }
    }
    
}

void show(vector<vector<Node*> > &ans){

        vector<Node*> list = ans[0];
        vector<Node*>::iterator it2(list.begin());
        for(it2 = list.begin();it2 < list.end();it2++){
            Node* p = *it2;
            p->getPoint()->show();
        }
        printf("\n");
}