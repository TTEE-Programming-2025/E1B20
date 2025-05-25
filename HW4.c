//
//  main.c
//  程式作業四
//
//  Created by 莊景閎 on 2025/5/25.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct data             //宣告結構
{
    char name[15];
    char code[15];
    int math;
    int physic;
    int English;
};
struct data student[MAX];//宣告結構變數

void clean_buffer(void);
void clean_screen(void);
void option_a(void);
void option_b(void);
void option_c(void);
void option_d(void);
void option_e(void);

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
           
            
        }
        if(option=='c' || option=='C')
        {
           
            
        }
        if(option=='d' || option=='D')
        {
           
            
        }
        if(option=='e' || option=='E')
        {
            option_e();
        }
    }
   
    return 0;
}

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
void option_a(void)
{
    int num=0,i=0;
    clean_screen();
    do{
        printf("請輸入5~10的任一個整數：");
        scanf("%d",&num);
        clean_buffer();
    }while(num>10 || num<5);
    for(i=0;i<num;i++)
    {
        printf("請輸入第%d位學生姓名：",i+1);
        scanf("%s",student[i].name);
        clean_buffer();
        printf("請輸入學生學號：");
        scanf("%s",student[i].code);
        clean_buffer();
        printf("請輸入數學成績：");
        scanf("%d",&student[i].math);
        clean_buffer();
        printf("請輸入物理成績：");
        scanf("%d",&student[i].physic);
        clean_buffer();
        printf("請輸入英文成績：");
        scanf("%d",&student[i].English);
        clean_buffer();
    }
    return;
}

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
