/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>

struct node{int data,hd;struct node*left,*right;};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;t->left=t->right=NULL;t->hd=0;
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

    root->hd=0;
    q2[r2++]=root;

    int min=0,max=0;
    int col[200][100],cnt[200]={0};

    while(f2<r2)
    {
        struct node* cur=q2[f2++];
        int h=cur->hd+100;

        col[h][cnt[h]++]=cur->data;

        if(cur->hd<min) min=cur->hd;
        if(cur->hd>max) max=cur->hd;

        if(cur->left)
        {
            cur->left->hd=cur->hd-1;
            q2[r2++]=cur->left;
        }

        if(cur->right)
        {
            cur->right->hd=cur->hd+1;
            q2[r2++]=cur->right;
        }
    }

    for(int i=min;i<=max;i++)
    {
        int h=i+100;
        for(int j=0;j<cnt[h];j++)
        {
            printf("%d",col[h][j]);
            if(j!=cnt[h]-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}