//有A，B两个字符串，请设计函数输出A，B的公共最长子串
#include <stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

void findSubChars(char *str1,char *str2,char *awn){
    int str1len = strlen(str1);
	int str2len = strlen(str2);
	int i,j,index,max=0,num=0; 
	int start;
    
	//将两个字符串看做两个直尺，固定一个直尺，另外一个从头到尾开始移动，逐一与固定的直尺比较值。
	for(i = 0; i < str1len; i++) 
	{
		for(j = 0; j < str2len; j++)
		{
			//这里的start1、start2是比较关键的
			int start1=i;
			int start2=j;
			while((start1 <= str1len-1) && (start2 <= str2len-1) && (str1[start1++] == str2[start2++]))
				num++;
			if(num > max)//如果num是当前最大匹配的个数，则赋给max，并且在start记下str1最长匹配开始的位置
			{
				max=num;
				start=i; 
			} 
			num=0;//如果num不是当前最大的，则赋为0值继续循环
		}
	}
	char *str=(char *)malloc(max + 1);
	strncpy(str,str1 + start,max);//从字符串str1的start位置开始，拷贝max个字符到str中，这就是我们找出的最大子串
	str[max] = '\0';
	printf("最长公共连续子串的长度为：%d\n",max);
	strcpy(awn,str);

}

int main(){
    char a[20];
    char b[20];
    char sub_ab[20];
    cout<<"输入a字符串:";
    cin>>a;
    cout<<"输入b字符串:";
    cin>>b;
    findSubChars(a,b,sub_ab);
    cout<<sub_ab<<endl;

    
}