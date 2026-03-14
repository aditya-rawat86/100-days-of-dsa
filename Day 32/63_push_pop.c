/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>
#define MAX 100
int main()
{
    int stack[MAX];
    int top = -1;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        if(top != -1)
            top--;
    }
    for(int i = top; i >= 0; i--)
    {
        printf("%d", stack[i]);
        if(i != 0)
            printf(" ");
    }
    return 0;
}