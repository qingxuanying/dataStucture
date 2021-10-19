#include<stdio.h>
#include<math.h>
#define arrsize 32
#define MAXINT 1024
int getNum(int i){
    int j;
    j=i*pow(2,i);
    if(j>1024){
        printf("erorr");
        exit(-1);
    }
    return j;
}
int main(){
    int a[arrsize];
    int k;
    scanf("%d",&k);
    if(k>arrsize){
        printf("erorr");
        exit(-1);
    }
    if(k*pow(2,k)>MAXINT){
        printf("erorr");
        exit(-1);
    }
    for(int i=1;i<=k;i++){
        a[i]=getNum(i);
    }
    for(int i=0;i<k;i++){
        printf("%3d  ",a[i]);
    }
}