/*Problem: BST Search

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

int search(struct node* root,int key)
{
    if(!root) return 0;
    if(root->data==key) return 1;
    if(key<root->data) return search(root->left,key);
    return search(root->right,key);
}

int main()
{
    int n,x,key;
    scanf("%d",&n);
    struct node* root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    scanf("%d",&key);
    if(search(root,key)) printf("Found");
    else printf("Not Found");
    return 0;
}