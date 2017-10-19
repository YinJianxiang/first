#include <stdio.h>  
  
  
int m;
int n;

int main() {  
    int a[1001][1001]; 
  
    scanf("%d %d",&m,&n);
    
    int i,j,k;  
    char flag,flag1; 
    for(i = 0;i < m;i++) {
        for(j = 0;j < n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 0; i < m; i++ ) {  
        for(j = 0; j < n; j++) {  
            flag = 0;  
            flag1 = 0;  
            for(k = 0 ;k < n;k++) {  
                if(a[i][j] < a[i][k])
                    flag = 1;  
            }  
            for(k = 0;k < m;k++) {  
                if(a[i][j] < a[k][j])
                    flag1 = 1;  
            }  
            if(!flag && !flag1)
                printf("hang:%d lie:%d = %d\n",i,j,a[i][j]);  
        }  
    }  
    return 0;  
}  
