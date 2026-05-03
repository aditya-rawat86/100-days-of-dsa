/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/

#include <stdio.h>
#include <stdlib.h>

int cmpStart(const void* a,const void* b){return ((int*)a)[0]-((int*)b)[0];}
int cmpEnd(const void* a,const void* b){return *(int*)a-*(int*)b;}

int main()
{
    int n;
    scanf("%d",&n);

    int a[n][2];
    for(int i=0;i<n;i++) scanf("%d %d",&a[i][0],&a[i][1]);

    qsort(a,n,sizeof(a[0]),cmpStart);

    int end[n],rooms=0;

    for(int i=0;i<n;i++)
    {
        int placed=0;

        for(int j=0;j<rooms;j++)
        {
            if(end[j]<=a[i][0])
            {
                end[j]=a[i][1];
                placed=1;
                break;
            }
        }

        if(!placed)
        {
            end[rooms++]=a[i][1];
        }

        qsort(end,rooms,sizeof(int),cmpEnd);
    }

    printf("%d",rooms);
    return 0;
}