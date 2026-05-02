/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>

struct node{int v;struct node*next;};

struct node* adj[100];
int vis[100],stack[100],top=-1;

void dfs(int u)
{
    vis[u]=1;
    struct node* t=adj[u];
    while(t)
    {
        if(!vis[t->v]) dfs(t->v);
        t=t->next;
    }
    stack[++top]=u;
}

int main()
{
    int n,m,u,v;
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0;i<n;i++){adj[i]=NULL;vis[i]=0;}

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        struct node* t=(struct node*)malloc(sizeof(struct node));
        t->v=v;t->next=adj[u];adj[u]=t;
    }

    for(int i=0;i<n;i++)
        if(!vis[i]) dfs(i);

    while(top!=-1)
        printf("%d ",stack[top--]);

    return 0;
}