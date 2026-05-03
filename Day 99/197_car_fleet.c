/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{int pos;float time;}Car;

int cmp(const void* a,const void* b)
{
    return ((Car*)b)->pos-((Car*)a)->pos;
}

int main()
{
    int n,target;
    scanf("%d %d",&n,&target);

    int pos[n],speed[n];
    for(int i=0;i<n;i++) scanf("%d",&pos[i]);
    for(int i=0;i<n;i++) scanf("%d",&speed[i]);

    Car a[n];
    for(int i=0;i<n;i++)
    {
        a[i].pos=pos[i];
        a[i].time=(float)(target-pos[i])/speed[i];
    }

    qsort(a,n,sizeof(Car),cmp);

    int fleets=0;
    float cur=0;

    for(int i=0;i<n;i++)
    {
        if(a[i].time>cur)
        {
            fleets++;
            cur=a[i].time;
        }
    }

    printf("%d",fleets);
    return 0;
}