#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* getNext(char *b,int len_b) {
	int j = 0;
	int k = -1;
	
	int *next = (int *)malloc(sizeof(int) * len_b);
	next[0] = -1;
	while(j < len_b - 1) {
		if(k == -1 || b[j] == b[k]) {
			if(b[++j] == b[++k]) {
				next[j] = next[k];
			} else {
				next[j] = k;
			}
		} else {
			k = next[k];
		}
	}

	return next;
}

int main(void) {
	char a[1001];
	char b[1001];
	int i;
	int j;
	int len_a;
	int len_b;
	int *next;

	scanf("%s",a);
	scanf("%s",b);

	len_a = strlen(a);
	len_b = strlen(b);

	next = getNext(b,len_b);

	i = 0;
	j = 0;

	while(i < len_a && j < len_b) {
		if(j == -1 || a[i] == b[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if(j == len_b) {
		printf("%d\n",i-j); 
	} else {
		printf("-1\n");
	}

	free(next);

	return 0;
}
