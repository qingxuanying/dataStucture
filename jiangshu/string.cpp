#include<iostream>
#include<string.h>
#include "kmp.cpp"
using namespace std;
class String{
    public:
        char str[30];
        String(const char *s){
            strcpy(str,s);
        }
        String(){
            
        }
        String(char *s){
            strcpy(str,s);
        }
        String(String &s){
            strcpy(str,s.str);
        }
        void setStr(char *s){
            strcpy(str,s);
        }
        int lenth(){
            return strlen(str);
        }
        void show(){
            cout<<str<<endl;
        }
        int deleteStr(char s){
            int key=-1;
            for(int i=strlen(str);i>=0;i--){
                if(str[i]==s){
                    key=i;
                    for(int j=i;j<=strlen(str)-1;j++){
                        str[j]=str[j+1];
                    }
                }
            }
            return key;
        }
        int deleteByid(int d){
            if(d>strlen(str)){
                return 0;
            }
            for(int j=d;j<=strlen(str)-1;j++){
                str[j]=str[j+1];
            }
            return 1;
        }
        int insert(String A,int s){
            if(s>strlen(str)){
                return 0;
            }
            int l=A.lenth();
            for(int i=strlen(str)-1;i>=s;i--){
                str[i+l]=str[i];
            }
            
            for(int i=0;i<l;i++){
                str[s+i]=A.str[i];
            }
            return 1;
            
        }
        int subStrIndex(String s){
            int flag=-1;
            flag=KMP(str,s.str);
            return flag;
        }
        friend String SubString(String s,int start,int len);
        friend void StrAssign(String &t,String &S);
        friend int StrCompare(String s,String t);
        friend int StrLength(String s);
        friend String Concat(String s,String t);
        friend String inSnotInT(String s,String t);
        friend String verseString(String &s);
        friend int Replace(String &S,String T,String V);
        friend void wordSUM(String A);
};
void StrAssign(String &t,String &s){
    strcpy(t.str,s.str);
}
int StrCompare(String s,String t){
    return strcmp(s.str,t.str);
}
int StrLength(String s){
    return strlen(s.str);
}
String Concat(String s,String t){
    int la=StrLength(s);
    int lb=StrLength(t);
    char strb[la+lb+1];
    strcpy(strb,strcat(s.str,t.str));
    String str(strb);
    return str;
};
String SubString(String s,int start,int len){
    char str[len+1];
    for(int i=0;i<len;i++){
        str[i]=s.str[start+i];
    }
    str[len]='\0';
    String sub(str);
    return sub;
}