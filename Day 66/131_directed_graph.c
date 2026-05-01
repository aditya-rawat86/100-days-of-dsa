/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>

struct node{int v;struct node*next;};

struct node* adj[100];
int vis[100],rec[100];

int dfs(int u)
{
    vis[u]=1;
    rec[u]=1;
    struct node* t=adj[u];
    while(t)
    {
        if(!vis[t->v])
        {
            if(dfs(t->v)) return 1;
        }
        else if(rec[t->v]) return 1;
        t=t->next;
    }
    rec[u]=0;
    return 0;
}

int main()
{
    int n,m,u,v;
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=0;i<n;i++){adj[i]=NULL;vis[i]=rec[i]=0;}

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        struct node* t=(struct node*)malloc(sizeof(struct node));
        t->v=v;t->next=adj[u];adj[u]=t;
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}