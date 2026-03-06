/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory 
allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update 
head to (n-k+1)th node.*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    for(int i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}
struct node* rotateRight(struct node *head, int k)
{
    if(head == NULL)
        return head;
    struct node *temp = head;
    int n = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }
    k = k % n;
    if(k == 0)
        return head;
    temp->next = head;
    int steps = n - k;
    struct node *newTail = head;
    for(int i = 1; i < steps; i++)
        newTail = newTail->next;
    struct node *newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}
void printList(struct node *head)
{
    while(head != NULL)
    {
        printf("%d", head->data);
        if(head->next != NULL)
            printf(" ");
        head = head->next;
    }
}
int main()
{
    int n, k;
    scanf("%d", &n);
    struct node *head = createList(n);
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    return 0;
}