#include<stdio.h>
typedef enum {A,B,C,D,E} SchoolName;
typedef enum {FEMALE,MALE} SexType;
typedef struct{
    char event[3];
    SexType sex;
    SchoolName school;
    int score;
}Component;
typedef struct{
    int malesun;//男子团体
    int femalesum;//女子团体
    int totalsum; //团体
}Sum;
Component report[3]; //三个项目
Sum result[5];//五个学校的成绩
int main()
{
    report[0].sex=FEMALE;
    report[0].school=A;
    report[0].score=32;
    report[1].sex=MALE;
    report[1].school=A;
    report[1].score=24;
    report[2].score=32;
    report[2].school=B;
    report[2].sex=FEMALE;
    int i,j=0;
    for(i=0;i<3;i++){
        j=0;
        switch(report[i].school){
            case A: j=1; break;
            case B: j=2; break;
            case C: j=3; break;
            case D: j=4; break;
            case E: j=5; break;
        }
        switch(report->sex){
            case FEMALE: result[j-1].femalesum += report[i].score; result[j-1].totalsum += report[i].score;;break;
            case MALE: result[j-1].malesun += report[i].score; result[j-1].totalsum += report[i].score;;break;
        }
    }
}
