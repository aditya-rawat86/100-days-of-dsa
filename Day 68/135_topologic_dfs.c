/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm)*/

#include <stdio.h>

int main()
{
    int n,m,u,v;
    scanf("%d",&n);
    scanf("%d",&m);

    int adj[n][n],indeg[n],q[n];

    for(int i=0;i<n;i++)
    {
        indeg[i]=0;
        for(int j=0;j<n;j++) adj[i][j]=0;
    }

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        indeg[v]++;
    }

    int f=0,r=0;

    for(int i=0;i<n;i++)
        if(indeg[i]==0) q[r++]=i;

    while(f<r)
    {
        int x=q[f++];
        printf("%d ",x);

        for(int i=0;i<n;i++)
        {
            if(adj[x][i])
            {
                indeg[i]--;
                if(indeg[i]==0) q[r++]=i;
            }
        }
    }

    return 0;
}