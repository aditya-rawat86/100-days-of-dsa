/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.   */

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

struct node* build(int pre[],int in[],int s,int e,int *pi)
{
    if(s>e) return NULL;
    struct node* root=newnode(pre[(*pi)++]);
    if(s==e) return root;
    int idx=search(in,s,e,root->data);
    root->left=build(pre,in,s,idx-1,pi);
    root->right=build(pre,in,idx+1,e,pi);
    return root;
}

void postorder(struct node* root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    int n;
    scanf("%d",&n);
    int pre[n],in[n];
    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);

    int pi=0;
    struct node* root=build(pre,in,0,n-1,&pi);

    postorder(root);
    return 0;
}