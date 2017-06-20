/*************************************************************************
    > File Name: N的阶乘.c
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com 
    > Created Time: 2017年06月20日 星期二 21时54分10秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(void) {
    long long result[10000];
    int num;
    int i;
    int j;
    while(scanf("%d",&num) != EOF) {
        memset(result,0,sizeof(result));
        result[0] = 1;
        for(j = 1;j < num;j++) {
            for(i = 0;i < 9999;i++) {
                result[i] *= j;
                for(i = 0;i < 9999;i++) {
                    if(result[i] >= 10000) {
                        result[i+1] += result[i] / 10000;
                        result[i] %= 10000;
                    }
                }
            }
        }
 
        for(i = 9999;i >= 0;i--) {
            if(result[i]) {
                break;
            }
        }
        printf("%lld",result[i]);
        for(j = i - 1;j >= 0;j--) {
            printf("%05lld",result[i]);
        }
        printf("\n");
    }
    
    return 0;
}

