/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top 
is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
int pop()
{
    if(top == NULL)
        return 0;
    struct node *temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}
int main()
{
    char postfix[100];
    fgets(postfix, sizeof(postfix), stdin);
    int i = 0;
    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if(postfix[i] == '+' || postfix[i] == '-' ||
                postfix[i] == '*' || postfix[i] == '/')
        {
            int b = pop();
            int a = pop();
            int result;
            switch(postfix[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            push(result);
        }
        i++;
    }
    printf("%d", pop());
    return 0;
}