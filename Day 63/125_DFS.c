/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

struct node{int v;struct node*next;};

struct node* adj[100];
int vis[100];

void dfs(int u)
{
    vis[u]=1;
    printf("%d ",u);
    struct node* t=adj[u];
    while(t)
    {
        if(!vis[t->v]) dfs(t->v);
        t=t->next;
    }
}

int main()
{
    int n,m,u,v,s;
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0;i<n;i++){adj[i]=NULL;vis[i]=0;}

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        struct node* t1=(struct node*)malloc(sizeof(struct node));
        t1->v=v;t1->next=adj[u];adj[u]=t1;

        struct node* t2=(struct node*)malloc(sizeof(struct node));
        t2->v=u;t2->next=adj[v];adj[v]=t2;
    }

    scanf("%d",&s);

    dfs(s);

    return 0;
}