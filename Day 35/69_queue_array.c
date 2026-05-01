/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display 
from front to rear.*/

#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = 0;
int rear = -1;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        rear++;
        queue[rear] = x;
    }
    for(int i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);
        if(i != rear)
            printf(" ");
    }
    return 0;
}