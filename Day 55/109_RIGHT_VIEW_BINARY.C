/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/

#include <stdio.h>
#include <stdlib.h>

struct node{int data;struct node*left,*right;};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;t->left=t->right=NULL;
    return t;
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

    struct node* q2[100];
    int f2=0,r2=0;

    q2[r2++]=root;

    while(f2<r2)
    {
        int size=r2-f2;

        for(int i=0;i<size;i++)
        {
            struct node* cur=q2[f2++];

            if(i==size-1) printf("%d ",cur->data);

            if(cur->left) q2[r2++]=cur->left;
            if(cur->right) q2[r2++]=cur->right;
        }
    }

    return 0;
}