#include<stdio.h>

int m;
int n;
int max;

char map[1001][1001];
int book[1001][1001];

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

int isSafe(int x,int y) {
    if(x < 0 || x >= m || y < 0 || y >= n || book[x][y] == 0) {
        return 0;
    }
    
    return 1;
}

void dfs(int x,int y) {
    int next_x;
    int next_y;
    int i;
    
    book[x][y] = 0;
    max++;
    
    for(i = 0;i < 4;i++) {
        next_x = x + dx[i];
        next_y = y + dy[i];
        if(isSafe(next_x,next_y)) {
            dfs(next_x,next_y);  
            book[x][y] = 1;
            break;
        }
    }  
    return;
}

int main(void) {
    int i;
    int j;
    int s_x;
    int s_y;
    
    max = 0;
    scanf("%d %d",&m,&n);
    for(i = 0;i < m;i++) {
        for(j = 0;j < n;j++) {
            scanf("%s",map[j]);
            if(map[i][j] == 'P') {
                book[i][j] = 1;
            }
            if(map[i][j] == 'U') {
                book[i][j] = 0;
            }
            if(map[i][j] == 'Z') {
                book[i][j] = 0;
                s_x = i;
                s_y = j;
            }
        }
    }
   
    dfs(s_x,s_y);
    
    printf("%d\n",max);
    
    return 0;
}

