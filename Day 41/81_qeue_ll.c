/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
struct node{int data;struct node*next;}*front=NULL,*rear=NULL;
void enqueue(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(rear==NULL) front=rear=newnode;
    else{rear->next=newnode;rear=newnode;}
}
void dequeue()
{
    if(front==NULL){printf("-1\n");return;}
    struct node*temp=front;
    printf("%d\n",temp->data);
    front=front->next;
    if(front==NULL) rear=NULL;
    free(temp);
}
int main()
{
    int N,x;
    char op[10];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",op);
        if(op[0]=='e'){scanf("%d",&x);enqueue(x);}
        else dequeue();
    }
    return 0;
}