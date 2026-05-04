/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{int val,idx;}Node;

void merge(Node a[],int l,int m,int r,int count[])
{
    int n1=m-l+1,n2=r-m;
    Node L[n1],R[n2];

    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];

    int i=0,j=0,k=l,smaller=0;

    while(i<n1 && j<n2)
    {
        if(L[i].val<=R[j].val)
        {
            count[L[i].idx]+=smaller;
            a[k++]=L[i++];
        }
        else
        {
            smaller++;
            a[k++]=R[j++];
        }
    }

    while(i<n1)
    {
        count[L[i].idx]+=smaller;
        a[k++]=L[i++];
    }

    while(j<n2) a[k++]=R[j++];
}

void mergesort(Node a[],int l,int r,int count[])
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(a,l,m,count);
        mergesort(a,m+1,r,count);
        merge(a,l,m,r,count);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    Node a[n];
    int count[n];

    for(int i=0;i<n;i++)
    {
        a[i].val=arr[i];
        a[i].idx=i;
        count[i]=0;
    }

    mergesort(a,0,n-1,count);

    for(int i=0;i<n;i++)
    {
        printf("%d",count[i]);
        if(i!=n-1) printf(" ");
    }

    return 0;
}