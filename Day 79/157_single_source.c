/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#define INF 1000000000

int main()
{
    int n,m,u,v,w,s;
    scanf("%d %d",&n,&m);

    int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            adj[i][j]=0;

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adj[u][v]=w;
        adj[v][u]=w;
    }

    scanf("%d",&s);

    int dist[n+1],vis[n+1];

    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
        vis[i]=0;
    }

    dist[s]=0;

    for(int i=1;i<=n;i++)
    {
        int u=-1,min=INF;

        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        if(u==-1) break;

        vis[u]=1;

        for(int v=1;v<=n;v++)
        {
            if(adj[u][v] && !vis[v] && dist[u]+adj[u][v]<dist[v])
                dist[v]=dist[u]+adj[u][v];
        }
    }

    for(int i=1;i<=n;i++)
    {
        printf("%d",dist[i]);
        if(i!=n) printf(" ");
    }

    return 0;
}
