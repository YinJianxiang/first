/*************************************************************************
    > File Name: Ainstein.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2017年05月28日 星期日 13时57分09秒
 ************************************************************************/

#include<stdio.h>

int main(void) {
	int n;
	int i;

	for(i = 7;i < 10000 ;i += 7)
		if((i % 2 == 1) && (i % 3 == 2) && (i % 5 == 4) && (i % 6 == 5)) {
			printf("%d\n",i);
			break;
		}
	return 0;
}

