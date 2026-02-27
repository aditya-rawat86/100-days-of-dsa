/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

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
struct node* mergeLists(struct node *p, struct node *q)
{
    struct node *head = NULL, *tail = NULL;
    if(p == NULL) return q;
    if(q == NULL) return p;
    if(p->data <= q->data)
    {
        head = tail = p;
        p = p->next;
    }
    else
    {
        head = tail = q;
        q = q->next;
    }
    while(p != NULL && q != NULL)
    {
        if(p->data <= q->data)
        {
            tail->next = p;
            tail = p;
            p = p->next;
        }
        else
        {
            tail->next = q;
            tail = q;
            q = q->next;
        }
    }
    if(p != NULL)
        tail->next = p;
    else
        tail->next = q;

    return head;
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
    int n, m;
    scanf("%d", &n);
    struct node *list1 = createList(n);
    scanf("%d", &m);
    struct node *list2 = createList(m);
    struct node *merged = mergeLists(list1, list2);
    printList(merged);
    return 0;
}