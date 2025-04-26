//
//  main.c
//  程設作業二
//
//  Created by 莊景閎 on 2025/4/23.
//

#include<stdio.h>
#include<stdlib.h>
void clear_screen(void);//清除螢幕
void clear_buffer(void);//清除緩衝區

int main(void)
{
    int i,j,k,password,wrong=0;
    char ch1,ch2,l,m,n;
    for(i=1;i<=20;i++){
        for(j=1;j<=i;j++){
            printf("😍");
        }
        printf("\n");
    }
    for(k=1;k<=3;k++){  //有三次輸入密碼的機會
        printf("請輸入4位數密碼：");
        scanf("%d",&password);
        if(password==2025){
            break;//三次中有一次對即可
        }
        if(password!=2025){
            wrong++;
        }
    }
    if(wrong==3){  //連續錯三次則結束程式
        printf("密碼錯誤！\n");
        return 0;
    }
    else{
        printf("歡迎！\n");
        clear_screen();
        while(1){
            printf(" ---------------------\n");
            printf(" | a. 畫出直角三角形 |\n");
            printf(" | b. 顯示九九乘法表 |\n");
            printf(" | c. 結束執行～～～ |\n");
            printf(" ---------------------\n");
            printf("請輸入字元：");
            scanf("%c",&ch1);
            clear_buffer();
            if(ch1=='a' || ch1=='A'){  //使用者輸入a或A
                clear_screen();
                while(1){
                    printf("請輸入一個'a'~'n'的字元：");
                    scanf("%c",&ch2);
                    clear_buffer();
                    if(ch2<'a' || ch2>'n'){  //輸入字元只能在a~n之間
                        printf("error\n");
                    }
                    else{
                        break;
                    }
                }
                for(l=ch2;l>='a';l--){  //印出直角三角形
                    for(m='a';m<l;m++){
                        printf(" ");
                    }
                    for(n=l;n<=ch2;n++){
                        printf("%c",n);
                    }
                    printf("\n");
                }
                clear_screen();
            }
            continue;
        }
    }
   
    return 0;
}
void clear_screen(void){
    printf("Press Enter to continue...");
        getchar();// 等待用戶按 Enter
    printf("\033[2J\033[H");// 清除畫面
}
void clear_buffer(void){
    int c;
    while((c=getchar())!='\n' && c!=EOF);//清除緩衝區
        
}

