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
                    if(ch2>='a' && ch2<='n'){  //輸入字元只能在a~n之間
                        break;
                    }
                    else{
                        printf("error\n");
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
                continue;//回到主選單
            }
            else if(ch1=='b' || ch1=='B'){  //使用者輸入b或B
                clear_screen();
                while(1){
                    printf("輸入一個1~9的正整數：");
                    scanf("%d",&num);
                    clear_buffer();
                    if(num<1 || num>9){  //輸入正整數只能在1~9之間
                        printf("error\n");
                    }
                    else{
                        break;
                    }
                }
                for(o=1;o<=num;o++){  //印出九九乘法表
                    for(p=1;p<=9;p++){
                        printf(" %d*%d=%2d",o,p,o*p);
                    }
                    printf("\n");
                }
                clear_screen();
                continue;//回到主選單
            }
            else if(ch1=='c' || ch1=='C'){  //使用者輸入c或C
                clear_screen();
                while(1){
                    printf("請問是要重新輸入？(y/n)");
                    scanf("%c",&ch3);
                    clear_buffer();
                    if(ch3!='y' && ch3!='Y' && ch3!='n' && ch3!='Y'){
                        printf("error\n");
                        continue;//輸入字元只能是y或Ｙ或n或N
                    }
                    else{
                        break;
                    }
                }
                if(ch3=='y' || ch3=='Y'){  //使用者輸入y或Y
                    clear_screen();
                    continue;//回到主選單
                }
                if(ch3=='n' || ch3=='N'){  //使用者輸入n或N
                    return 0;//結束程式
                }
            }
        }
    }
   
    return 0;
}
void clear_screen(void){
    clear_buffer();//清除緩衝區，確保不讀到殘留的\n
    printf("Press Enter to continue...");
    getchar();// 等待用戶按 Enter
    printf("\033[2J\033[H");// 清除畫面
}
void clear_buffer(void){
    int c;
    while((c=getchar())!='\n' && c!=EOF);//清除緩衝區
}

