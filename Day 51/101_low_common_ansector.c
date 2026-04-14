/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/

#include <stdio.h>
#include <stdlib.h>

struct node{int data;struct node*left,*right;};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;t->left=t->right=NULL;
    return t;
}

struct node* insert(struct node* root,int x)
{
    if(!root) return newnode(x);
    if(x<root->data) root->left=insert(root->left,x);
    else root->right=insert(root->right,x);
    return root;
}

int lca(struct node* root,int a,int b)
{
    if(root->data>a && root->data>b) return lca(root->left,a,b);
    if(root->data<a && root->data<b) return lca(root->right,a,b);
    return root->data;
}

int main()
{
    int n,x,a,b;
    scanf("%d",&n);
    struct node* root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    scanf("%d %d",&a,&b);
    printf("%d",lca(root,a,b));
    return 0;
}