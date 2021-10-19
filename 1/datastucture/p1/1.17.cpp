#include <stdio.h>

int main(){
    int m=1,k=0,n=0;
    int a[10001];
    printf("第几项m:");
    scanf("%d",&m);
    printf("几阶斐波拉契数列k:");
    scanf("%d",&k);
    for(int i=0;i<m+1;i++){
        if(i<k){
            a[i]=0;
        }
        if(i==k){
            a[i]=1;
        }
        else{
            for(int j=0;j<i;j++){
                a[i]=a[i]+a[j];
            }
        }
        n=i;
    }
    printf("%d",a[m]);
    return 0;
}