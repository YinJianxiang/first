#include <stdio.h>

void reserve(char *p) {
	if(*p == 0) {
		return;
	}
	reserve(p+1);
	printf("%c",*p);
}

int main(void) {
	reserve("asdfghjkl");
	printf("\n");
	return 0;
}

