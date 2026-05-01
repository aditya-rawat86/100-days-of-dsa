/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h>

struct node{int v;struct node*next;};

struct node* adj[100];
int vis[100];

int dfs(int u,int p)
{
    vis[u]=1;
    struct node* t=adj[u];
    while(t)
    {
        if(!vis[t->v])
        {
            if(dfs(t->v,u)) return 1;
        }
        else if(t->v!=p) return 1;
        t=t->next;
    }
    return 0;
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

        struct node* t1=(struct node*)malloc(sizeof(struct node));
        t1->v=v;t1->next=adj[u];adj[u]=t1;

        struct node* t2=(struct node*)malloc(sizeof(struct node));
        t2->v=u;t2->next=adj[v];adj[v]=t2;
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}