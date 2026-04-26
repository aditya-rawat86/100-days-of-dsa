/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>

struct node{int data;struct node*left,*right;};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;t->left=t->right=NULL;
    return t;
}

int search(int in[],int s,int e,int val)
{
    for(int i=s;i<=e;i++) if(in[i]==val) return i;
    return -1;
}

struct node* build(int in[],int post[],int s,int e,int *pi)
{
    if(s>e) return NULL;
    struct node* root=newnode(post[(*pi)--]);
    if(s==e) return root;
    int idx=search(in,s,e,root->data);
    root->right=build(in,post,idx+1,e,pi);
    root->left=build(in,post,s,idx-1,pi);
    return root;
}

void preorder(struct node* root)
{
    if(!root) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);
    int in[n],post[n];
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);

    int pi=n-1;
    struct node* root=build(in,post,0,n-1,&pi);

    preorder(root);
    return 0;
}