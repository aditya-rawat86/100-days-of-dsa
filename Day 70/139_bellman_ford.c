/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/

#include <stdio.h>
#define INF 1000000000

struct edge{int u,v,w;};

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);

    struct edge e[m];
    for(int i=0;i<m;i++) scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);

    int s;
    scanf("%d",&s);

    int dist[n];
    for(int i=0;i<n;i++) dist[i]=INF;
    dist[s]=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[e[j].u]!=INF && dist[e[j].u]+e[j].w<dist[e[j].v])
                dist[e[j].v]=dist[e[j].u]+e[j].w;
        }
    }

    for(int j=0;j<m;j++)
    {
        if(dist[e[j].u]!=INF && dist[e[j].u]+e[j].w<dist[e[j].v])
        {
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d",dist[i]);
        if(i!=n-1) printf(" ");
    }

    return 0;
}