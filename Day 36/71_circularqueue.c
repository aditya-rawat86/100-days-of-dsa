/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue 
removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>
#define MAX 100
int queue[MAX];
int front=0,rear=-1,size=0;
void enqueue(int x)
{
    rear=(rear+1)%MAX;
    queue[rear]=x;
    size++;
}
int dequeue()
{
    int x=queue[front];
    front=(front+1)%MAX;
    return x;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        enqueue(x);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x=dequeue();
        enqueue(x);
    }
    int i=front,count=0;
    while(count<n)
    {
        printf("%d",queue[i]);
        if(count!=n-1) printf(" ");
        i=(i+1)%MAX;
        count++;
    }
    return 0;
}