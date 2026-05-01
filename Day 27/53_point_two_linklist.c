/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic 
memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is 
intersection.*/

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
int main()
{
    int n, m;
    scanf("%d", &n);
    struct node *list1 = createList(n);
    scanf("%d", &m);
    struct node *list2 = createList(m);
    struct node *p = list1;
    struct node *q;
    while(p != NULL)
    {
        q = list2;
        while(q != NULL)
        {
            if(p->data == q->data)
            {
                printf("%d", p->data);
                return 0;
            }
            q = q->next;
        }
        p = p->next;
    }
    printf("No Intersection");
    return 0;
}