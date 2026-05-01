/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/

#include <stdio.h>
#include <stdlib.h>

struct node{int data;struct node*left,*right;};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;t->left=t->right=NULL;
    return t;
}

int isMirror(struct node* a,struct node* b)
{
    if(!a&&!b) return 1;
    if(!a||!b) return 0;
    if(a->data!=b->data) return 0;
    return isMirror(a->left,b->right)&&isMirror(a->right,b->left);
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    if(n==0||a[0]==-1){printf("YES");return 0;}

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

    if(isMirror(root->left,root->right)) printf("YES");
    else printf("NO");

    return 0;
}