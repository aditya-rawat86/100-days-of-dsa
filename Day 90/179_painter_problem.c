/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/

#include <stdio.h>

int can(int a[],int n,int k,int max)
{
    int painters=1,sum=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>max) return 0;

        if(sum+a[i]<=max) sum+=a[i];
        else
        {
            painters++;
            sum=a[i];
        }

        if(painters>k) return 0;
    }
    return 1;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];

    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int l=0,r=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>l) l=a[i];
        r+=a[i];
    }

    int ans=r;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(can(a,n,k,mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    printf("%d",ans);
    return 0;
}