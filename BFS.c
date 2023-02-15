#include <stdio.h>

int a[20][20],s[20],visited[20],n,i,j,top=-1;
void bfs(int v);
void main()
{
    int v;
    printf("enter the number of vertices: ");
    scanf("%d", &n);
    printf("enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        s[i]=0;
        visited[i]=0;
    }
    bfs(v);
    printf("the reachable nodes are:");
    for(i=0;i<n;i++)
    {
      if(visited[i]);
      printf("%d\t",i);
    }
}
void bfs(int v)
{
    for(i=0;i<n;i++)
    if(a[v][i] && !visited[i])
    s[++top]=i;
    if(top!=-1)
    {
        visited[s[top]]=1;
        bfs(s[top--]);
    }
}
