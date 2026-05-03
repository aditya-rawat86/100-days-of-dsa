/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

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

    dfs(1);

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}