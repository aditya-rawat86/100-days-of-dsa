/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#define INF 1000000000

int main()
{
    int n,m,u,v,w,s;
    scanf("%d",&n);
    scanf("%d",&m);

    int adj[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adj[u][v]=w;
        adj[v][u]=w;
    }

    scanf("%d",&s);

    int dist[n],vis[n];

    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        vis[i]=0;
    }

    dist[s]=0;

    for(int i=0;i<n;i++)
    {
        int u=-1,min=INF;

        for(int j=0;j<n;j++)
        {
            if(!vis[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        if(u==-1) break;

        vis[u]=1;

        for(int v=0;v<n;v++)
        {
            if(adj[u][v] && !vis[v] && dist[u]+adj[u][v]<dist[v])
                dist[v]=dist[u]+adj[u][v];
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d",dist[i]);
        if(i!=n-1) printf(" ");
    }

    return 0;
}