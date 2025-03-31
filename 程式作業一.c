//
//  main.c
//  程式作業一
//
//  Created by 莊景閎 on 2025/3/26.
//
#include <stdio.h>
#include <stdlib.h>

void emoji(void);
int main(void)
{
    int i,j,password;
    char ch;
    for(i=1;i<=20;i++){
        for(j=1;j<=i;j++){
            printf("👀");
        }
        printf("\n");
    }
    printf("按ENTER鍵繼續...\n");
    getchar();
    system("clear");
    
    printf("請輸入四個字的密碼：");
    scanf("%d",&password);
    fflush(stdin);
    if(password==2025){
        printf("歡迎！\n");
        printf("按ENTER鍵繼續...\n");
        getchar();
        system("clear");
        emoji();
        printf("|'A'~'Z' are uppercase |\n");
        printf("|'a'~'z' are lowercase |\n");
        printf("|'0'~'9' are digit     |\n");
        printf("|otherwise is your name|\n");
        emoji();
        printf("請輸入一個字元：");
        scanf("%c",&ch);
        if(ch>='A' && ch<='Z'){
            printf("uppercase\n");
        }
            else if(ch>='a' && ch<='z'){
                printf("lowercase\n");
        }
                 else if(ch>='0' && ch<='9'){
                    printf("digit\n");
        }
                      else{
                        printf("E1B20 莊景閎\n");
        }
    }
    else{
        printf("輸入錯誤！\n");
    }
    
    return 0;
}
void emoji(void){
    int i;
    for(i=1;i<=11;i++){
        printf("😎");
    }
    printf("\n");
    return;
}
