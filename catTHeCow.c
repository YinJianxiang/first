#include <stdio.h>
#include <string.h>

#define MAXN 200003

typedef struct Queue
{
    int count,step;
}Queue;
Queue queue[MAXN];
int visit[MAXN];
void bfs(int n,int k)
{
    int front=0,rear=0;
    queue[rear].step=n;
    queue[rear++].count=0;
    visit[n]=1;
    while(front<rear)
    {
        Queue q=queue[front++];
        if(q.step==k)
        {
            printf("%d\n",q.count);
            break;
        }
        if(q.step-1>=0 && !visit[q.step-1])
        {
            visit[q.step]=1;
            queue[rear].step=q.step-1;
            queue[rear++].count=q.count+1;
        }
        if(q.step<=k && !visit[q.step+1])
        {
            visit[q.step+1]=1;
            queue[rear].step=q.step+1;
            queue[rear++].count=q.count+1;
        }
        if(q.step<=k && !visit[q.step*2])
        {
            visit[q.step*2]=1;
            queue[rear].step=q.step*2;
            queue[rear++].count=q.count+1;
        }
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    
    memset(visit,0,sizeof(visit));
    bfs(n,k);
    
    return 0;
}
