/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

struct node{int v;struct node*next;};

struct node* adj[100];
int vis[100],q[100];

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

    int f=0,r=0;
    q[r++]=s;
    vis[s]=1;

    while(f<r)
    {
        int x=q[f++];
        printf("%d ",x);

        struct node* t=adj[x];
        while(t)
        {
            if(!vis[t->v])
            {
                vis[t->v]=1;
                q[r++]=t->v;
            }
            t=t->next;
        }
    }

    return 0;
}