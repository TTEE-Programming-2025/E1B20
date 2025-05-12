//
//  main.c
//  程式作業三
//
//  Created by 莊景閎 on 2025/5/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>               //provide functions and type definitions related to time and date
//declare function
void clean_screen(void);        //clean screen
void clean_buffer(void);        //clean buffer
void ShowArray(char s[9][9]);   //show array
void SaveArray(char s[9][9]);   //save array

int main(void)
{
    int i=0,j=0,k=0,password=0,wrong=0,count=0,rand_i=0,rand_j=0,seat_num=0,seat_i=0,seat_j=0,num=0;
    char option,middle;
    srand((unsigned int)time(NULL));//set random number seed based on current time
    //first
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
    char seat[9][9];//declare two-dimensionl array
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            seat[i][j]='-';
        }
    }
    while(1)//set 10 seats that have been taken
    {
        rand_i=rand()%9;
        rand_j=rand()%9;
        if(seat[rand_i][rand_j]!='*')
        {
            seat[rand_i][rand_j]='*';
            count++;
        }
        if(count==10)
        {
            break;
        }
    }
    while(1)
    {
        //second
        //print menu
        printf("*****{Booking System}*****\n");
        printf("|  a. Available seats    |\n");
        printf("|  b. Arrange for you    |\n");
        printf("|  c. Choose by yourself |\n");
        printf("|  d. Exit               |\n");
        printf("**************************\n");
        printf("請輸入您想要的選項：");
        option=getchar();
        clean_buffer();
        //question three
        if(option=='a')//option a
        {
            ShowArray(seat);
            clean_screen();
            continue;
        }
        //question four
        if(option=='b')//option b
        {
            printf("請問您需要幾個座位？(1~4)");
            scanf("%d",&seat_num);
            if(seat_num==1)//one seat
            {
                rand_i=rand()%9;
                rand_j=rand()%9;
                if(seat[rand_i][rand_j]!='*')
                {
                    seat[rand_i][rand_j]='@';
                }
            }
            if(seat_num==2)//two seats
            {
                rand_i=rand()%9;
                rand_j=rand()%8;
                if(seat[rand_i][rand_j]!='*' && seat[rand_i][rand_j+1]!='*')
                {
                    seat[rand_i][rand_j]='@';
                    seat[rand_i][rand_j+1]='@';
                }
            }
            if(seat_num==3)//three seats
            {
                rand_i=rand()%9;
                rand_j=rand()%7;
                if(seat[rand_i][rand_j]!='*' && seat[rand_i][rand_j+1]!='*' && seat[rand_i][rand_j+2]!='*')
                {
                    seat[rand_i][rand_j]='@';
                    seat[rand_i][rand_j+1]='@';
                    seat[rand_i][rand_j+2]='@';
                }
            }
            if(seat_num==4)//four seats
            {
                if(rand()%2==1)//random choice
                {
                    rand_i=rand()%8;
                    rand_j=rand()%8;
                    if(seat[rand_i][rand_j]!='*' && seat[rand_i][rand_j+1]!='*' && seat[rand_i+1][rand_j]!='*' && seat[rand_i+1][rand_j+1]!='*')
                    {
                        seat[rand_i][rand_j]='@';
                        seat[rand_i][rand_j+1]='@';
                        seat[rand_i+1][rand_j]='@';
                        seat[rand_i+1][rand_j+1]='@';
                    }
                }
                else
                {
                    rand_i=rand()%9;
                    rand_j=rand()%6;
                    if(seat[rand_i][rand_j]!='*' && seat[rand_i][rand_j+1]!='*' && seat[rand_i][rand_j+2]!='*' && seat[rand_i][rand_j+3]!='*')
                    {
                        seat[rand_i][rand_j]='@';
                        seat[rand_i][rand_j+1]='@';
                        seat[rand_i][rand_j+2]='@';
                        seat[rand_i][rand_j+3]='@';
                    }
                }
            }
            clean_screen();
            printf("您是否滿意此次的選位？\n");
            ShowArray(seat);//show array
            printf("請回答(y/n):");
            option=getchar();
            clean_buffer();
            if(option=='n' || option=='N')
            {
                for(i=0;i<9;i++)
                {
                    for(j=0;j<9;j++)
                    {
                        if(seat[i][j]=='@')
                        {
                            seat[i][j]='-';
                        }
                    }
                }
            }
            if(option=='y' || option=='Y')
            {
                SaveArray(seat);//save array
            }
            clean_screen();
            continue;
        }
        //question five
        if(option=='c')//option c
        {
            printf("請輸入您想要的座位數量(0~71)：");
            scanf("%d",&num);
            clean_buffer();
            for(i=1;i<=num;i++)
            {
                while(1)
                {
                    printf("請依照格式輸入您想坐的座位（如：1-2 為第一列第二行）");
                    scanf("%d %c %d",&seat_i,&middle,&seat_j);
                    clean_buffer();
                    if(middle!='-')
                    {
                        printf("error:請輸入正確格式！\n");
                        continue;
                    }
                    if(seat[9-seat_i][seat_j-1]=='*')
                    {
                        printf("error:座位已被選取！\n");
                        continue;
                    }
                    if(seat[9-seat_i][seat_j-1]!='*' && middle=='-' )
                    {
                        break;
                    }
                }
                seat[9-seat_i][seat_j-1]='@';
            }
            ShowArray(seat);//show array
            SaveArray(seat);//save array
            clean_screen();
            continue;
        }
        //question six
        if(option=='d')//option d
        {
            while(1)
            {
                printf("請問您是否要退出？(y/n)");
                option=getchar();
                clean_buffer();
                if(option=='Y' || option=='y')
                {
                    return 0;
                }
                else if(option=='N' || option=='n')
                {
                    break;
                }
                else
                {
                    printf("error:請輸入(y/n)\n");
                    continue;
                }
            }
            clean_screen();
            continue;
        }
    }
    return 0;
}
//定義函式
void clean_screen(void)
{
    printf("Press Enter to continue...");
    getchar();
    printf("\033[2J\033[H");
}
void clean_buffer(void)
{
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}
void ShowArray(char s[9][9])
{
    int i=0,j=0;
    printf("\\123456789\n");
    for(i=0;i<9;i++)
    {
        printf("%d",9-i);
        for(j=0;j<9;j++)
        {
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
}
void SaveArray(char s[9][9])
{
    int i=0,j=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(s[i][j]=='@')
            {
                s[i][j]='*';
            }
        }
    }
}
