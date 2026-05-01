/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>
#define MAX 100

int q[MAX],s[MAX];
int front=0,rear=-1,top=-1;

void enqueue(int x){q[++rear]=x;}
int dequeue(){return q[front++];}
void push(int x){s[++top]=x;}
int pop(){return s[top--];}

int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&x);enqueue(x);}
    for(int i=0;i<n;i++) push(dequeue());
    for(int i=0;i<n;i++) enqueue(pop());
    for(int i=front;i<=rear;i++)
    {
        printf("%d",q[i]);
        if(i!=rear) printf(" ");
    }
    return 0;
}