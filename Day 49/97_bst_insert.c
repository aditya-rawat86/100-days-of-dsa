/*Problem: BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
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

void inorder(struct node* root)
{
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);
    struct node* root=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    inorder(root);
    return 0;
}