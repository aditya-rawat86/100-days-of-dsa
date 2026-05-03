/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

#include <stdio.h>
#include <stdlib.h>

struct node{int v;struct node*next;};

struct node* adj[100];
int vis[100];

void dfs(int u)
{
    vis[u]=1;
    struct node* t=adj[u];
    while(t)
    {
        if(!vis[t->v]) dfs(t->v);
        t=t->next;
    }
}

int main()
{
    int n,m,u,v;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){adj[i]=NULL;vis[i]=0;}

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        struct node* t1=(struct node*)malloc(sizeof(struct node));
        t1->v=v;t1->next=adj[u];adj[u]=t1;

        struct node* t2=(struct node*)malloc(sizeof(struct node));
        t2->v=u;t2->next=adj[v];adj[v]=t2;
    }

    int count=0;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            count++;
        }
    }

    printf("%d",count);
    return 0;
}