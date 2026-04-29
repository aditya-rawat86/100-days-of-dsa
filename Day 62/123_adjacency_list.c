/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/

#include <stdio.h>
#include <stdlib.h>

struct node{int v;struct node*next;};

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);

    struct node* adj[n];
    for(int i=0;i<n;i++) adj[i]=NULL;

    int u,v;
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
        printf("%d:",i);
        struct node* t=adj[i];
        while(t)
        {
            printf(" %d",t->v);
            t=t->next;
        }
        printf("\n");
    }

    return 0;
}