#include<stdio.h>  
  
void left_num(int* a,int n) {  
    int count = 0;  
    int i;  
    int out = 0;  
      
    for(i = 0;i < n;i++) {  
        a[i] = i + 1;  
    }  
      
    i = 0;  
    while(out < n - 1) {  
        if(a[i] != 0) {  
            count++;  
        }  
        if(count == 3) {  
            count = 0;  
            a[i] = 0;  
            out++;  
        }  
        i++;  
        if (i == n) {  
            i = 0;    
        }  
    }  
    for(i = 0;i < n;i++) {  
         if (a[i] != 0) {  
            printf("%d\n",a[i]);  
        }  
    }  
      
}  
      
  
int main(void) {  
    int a[101];  
    int n;  
      
    scanf("%d",&n);  
    left_num(a,n);  
      
    return 0;  
}  

