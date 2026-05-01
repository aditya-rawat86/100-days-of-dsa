/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/

#include <stdio.h>
#include <stdlib.h>

struct node{int data;struct node*left,*right;};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;t->left=t->right=NULL;
    return t;
}

struct node* lca(struct node* root,int a,int b)
{
    if(!root) return NULL;
    if(root->data==a||root->data==b) return root;
    struct node* l=lca(root->left,a,b);
    struct node* r=lca(root->right,a,b);
    if(l&&r) return root;
    return l?l:r;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    if(n==0||a[0]==-1) return 0;

    struct node* q[n];
    int f=0,r=0;

    struct node* root=newnode(a[0]);
    q[r++]=root;

    int i=1;
    while(i<n)
    {
        struct node* cur=q[f++];

        if(a[i]!=-1)
        {
            cur->left=newnode(a[i]);
            q[r++]=cur->left;
        }
        i++;

        if(i<n && a[i]!=-1)
        {
            cur->right=newnode(a[i]);
            q[r++]=cur->right;
        }
        i++;
    }

    int x,y;
    scanf("%d %d",&x,&y);

    struct node* ans=lca(root,x,y);
    if(ans) printf("%d",ans->data);

    return 0;
}