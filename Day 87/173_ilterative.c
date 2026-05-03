/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/

#include <stdio.h>

int main()
{
    int n,x;
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    scanf("%d",&x);

    int l=0,r=n-1;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(a[mid]==x)
        {
            printf("%d",mid);
            return 0;
        }
        else if(a[mid]<x) l=mid+1;
        else r=mid-1;
    }

    printf("-1");
    return 0;
}