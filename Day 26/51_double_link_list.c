/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory 
allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = NULL, *temp = NULL, *newnode;
    for(int i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        if(temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    return 0;
}