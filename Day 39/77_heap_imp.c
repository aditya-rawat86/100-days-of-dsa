/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include <stdio.h>
#define MAX 100
int heap[MAX],n=0;

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void insert(int x)
{
    int i=n++;
    heap[i]=x;
    while(i>0 && heap[(i-1)/2]>heap[i])
    {
        swap(&heap[i],&heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

int extractMin()
{
    if(n==0) return -1;
    int min=heap[0];
    heap[0]=heap[n-1];
    n--;
    int i=0;
    while(1)
    {
        int l=2*i+1,r=2*i+2,small=i;
        if(l<n && heap[l]<heap[small]) small=l;
        if(r<n && heap[r]<heap[small]) small=r;
        if(small!=i)
        {
            swap(&heap[i],&heap[small]);
            i=small;
        }
        else break;
    }
    return min;
}

int peek()
{
    if(n==0) return -1;
    return heap[0];
}

int main()
{
    int N,x;
    char op[20];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",op);
        if(op[0]=='i')
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(op[0]=='e')
        {
            int res=extractMin();
            if(res==-1) printf("-1\n");
            else printf("%d\n",res);
        }
        else
        {
            int res=peek();
            if(res==-1) printf("-1\n");
            else printf("%d\n",res);
        }
    }
    return 0;
}