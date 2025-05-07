//
//  main.c
//  程式作業三
//
//  Created by 莊景閎 on 2025/5/7.
//

#include <stdio.h>
#include <stdlib.h>
void clean_screen(void);
void clean_buffer(void);

int main(void)
{
    int i=0,j=0,k=0,password=0,wrong=0;
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
    printf("*****{Booking System}*****\n");
    printf("|  a. Available seats    |\n");
    printf("|  b. Arrange for you    |\n");
    printf("|  c. Choose by yourself |\n");
    printf("|  d. Exit               |\n");
    printf("**************************\n");
    
    
    
    
    return 0;
}

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
