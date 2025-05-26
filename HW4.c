//
//  main.c
//  程式作業四
//
//  Created by 莊景閎 on 2025/5/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
int num=0;              //宣告全域變數
struct data             //宣告結構
{
    char name[15];
    char code[15];
    int math;
    int physic;
    int English;
    float avg;
};
struct data student[MAX];   //宣告結構變數

void clean_buffer(void);    //宣告清除緩衝區函式
void clean_screen(void);    //宣告清除螢幕函式
void option_a(void);        //宣告a選項函式
void option_b(void);        //宣告b選項函式
void option_c(void);        //宣告c選項函式
void option_d(void);        //宣告d選項函式
void option_e(void);        //宣告e選項函式
void swap(struct data *a, struct data *b)//宣告交換函式
{
    struct data temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int i=0,j=0,k=0,password=0,wrong=0;
    char option;
    for(i=1;i<=20;i++)
    {
        for(j=1;j<=20-i;j++)
        {
            printf(" ");
        }
        for(k=1;k<=2*i-1;k++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=1;i<=5;i++)
    {
        printf("           歡迎來到我的程式\n");
    }
    for(i=1;i<=3;i++)
    {
        printf("           請輸入密碼：");
        scanf("%d",&password);
        if(password==2025)
        {
            break;
        }
        else
        {
            wrong++;
        }
    }
    if(wrong==3)
    {
        printf("           error:密碼錯誤\n");
        return 0;
    }
    else
    {
        printf("               密碼正確\n");
        printf("           ！！！歡迎！！！\n");
    }
    clean_buffer();
    clean_screen();
    while(1)
    {
        printf("**********{Grade System}**********\n");
        printf("|  a. Enter student grades       |\n");
        printf("|  b. Display student grades     |\n");
        printf("|  c. Search for student grades  |\n");
        printf("|  d. Grade ranking              |\n");
        printf("|  e. Exit system                |\n");
        printf("**********************************\n");
        printf("請輸入您想要的選項：");
        scanf("%c",&option);
        clean_buffer();
        if(option=='a' || option=='A')
        {
            option_a();
        }
        if(option=='b' || option=='B')
        {
            option_b();
        }
        if(option=='c' || option=='C')
        {
            option_c();
        }
        if(option=='d' || option=='D')
        {
            option_d();
        }
        if(option=='e' || option=='E')
        {
            option_e();
        }
    }
   
    return 0;
}
                /*定義函式*/
void clean_buffer(void)
{
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}
void clean_screen(void)
{
    printf("Press Enter to continue...");
    getchar();
    printf("\033[2J\033[H");
}
                /*選項a*/
void option_a(void)
{
    int i=0,j=0,flag=0;
    clean_screen();
    do{
        printf("請輸入5~10的任一個整數：");
        scanf("%d",&num);
        clean_buffer();
    }while(num>10 || num<5);    //限定只能是5~10的整數
    for(i=0;i<num;i++)
    {
        printf("請輸入第%d位學生姓名：",i+1);
        scanf("%s",student[i].name);
        clean_buffer();
        while(1)
        {
            printf("請輸入學生學號：");
            scanf("%s",student[i].code);
            clean_buffer();
            if(strlen(student[i].code)!=6)  //限定只能是6位數
            {
                printf("無效輸入，請輸入6位數字學號！\n");
                continue;
            }
            else
            {
                for (j=0; j<6;j++)
                {
                    if (student[i].code[j]<'0' || student[i].code[j]>'9')   //限定只能是數字
                    {
                        printf("無效輸入，請輸入6位數字學號！\n");
                        flag++;
                    }
                }
            if(flag==0)
            {
                break;
            }
            else
            {
                continue;
            }
            }
        }
        do
        {
            printf("請輸入數學成績：");
            scanf("%d",&student[i].math);
            clean_buffer();
            if(student[i].math<=100 && student[i].math>=0)  //限定只能是0~100的整數
            {
                break;
            }
            else
            {
                printf("無效輸入，請輸入1~100的整數！\n");
            }
        }while(1);
        do
        {
            printf("請輸入物理成績：");
            scanf("%d",&student[i].physic);
            clean_buffer();
            if(student[i].physic<=100 && student[i].physic>=0)  //限定只能是0~100的整數
            {
                break;
            }
            else
            {
                printf("無效輸入，請輸入1~100的整數！\n");
            }
        }while(1);
        do
        {
            printf("請輸入英文成績：");
            scanf("%d",&student[i].English);
            clean_buffer();
            if(student[i].English<=100 && student[i].English>=0)    //限定只能是0~100的整數
            {
                break;
            }
            else
            {
                printf("無效輸入，請輸入1~100的整數！\n");
            }
        }while(1);
        student[i].avg=(float)(student[i].math+student[i].physic+student[i].English)/3;
    }
    clean_screen();
    return;
}
                /*選項b*/
void option_b(void)
{
    int i=0;
    clean_screen();
    for(i=0;i<num;i++)
    {
        printf("第%d位學生姓名：%s\n",i+1,student[i].name);
        printf("學生學號：%s\n",student[i].code);
        printf("數學成績：%d\n",student[i].math);
        printf("物理成績：%d\n",student[i].physic);
        printf("英文成績：%d\n",student[i].English);
        printf("平均成績：%.1f\n",student[i].avg);
    }
    clean_screen();
    return;
}
                /*選項c*/
void option_c(void)
{
    int i=0,flag=0;
    char name[20];
    clean_screen();
    printf("請輸入您要搜尋的姓名：");
    scanf("%s",name);
    for(i=0;i<num;i++)
    {
        if(strcmp(name,student[i].name)==0)
        {
            printf("第%d位學生姓名：%s\n",i+1,student[i].name);
            printf("學生學號：%s\n",student[i].code);
            printf("數學成績：%d\n",student[i].math);
            printf("物理成績：%d\n",student[i].physic);
            printf("英文成績：%d\n",student[i].English);
            printf("平均成績：%.1f\n",student[i].avg);
        }
        else
        {
            flag++;
        }
    }
    if(flag==num)
    {
        printf("查無此人！\n");
    }
    clean_buffer();
    clean_screen();
    return;
}
                /*選項d*/
void option_d(void)
{
    clean_screen();
    int i,j;
        printf("大到小:\n");
        for (i = 0; i < num - 1; i++) {
            for (j = 0; j < num - i - 1; j++) {
                if (student[j].avg < student[j + 1].avg) {
                    swap(&student[j], &student[j + 1]);
                }
            }
        }

        printf("%-8s %-10s %-6s\n", "姓名", "學號", "平均");
        for (i = 0; i < num; i++) {
            printf("%-8s %-10s %-6.1f\n", student[i].name, student[i].code, student[i].avg);
        }
    clean_buffer();
    clean_screen();
    return;
}
                /*選項e*/
void option_e(void)
{
    char option;
    do{
        printf("您確定要離開？(y/n)");
        scanf("%c",&option);
        clean_buffer();
        if(option=='n' || option=='N')
        {
            return;
        }
        else if(option=='y' || option=='Y')
        {
            printf("感謝使用，系統退出！\n");
            exit(0);
        }
        else
        {
            printf("無效輸入，請輸入y或n！\n");
        }
    }while(1);
}
/*
 撰寫這個學生成績管理系統讓我感受到程式設計的樂趣！
 從輸入成績到排序顯示，每個功能都像在打造一個小世界。
 因為這次的選單介面是利用函式完成的，所以程式中很常需
 要在主程式與函式間來回穿梭，因此我頻繁地在主程式與函式間來回穿梭，
 深刻體會到全域變數的便捷，讓資料管理更流暢。
 這種模組化的設計不僅讓程式碼更清晰，也讓我感受到結構化程式設計的魅力。
 */
