/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);

    int h[m];
    for(int i=0;i<m;i++) h[i]=EMPTY;

    char op[10];
    int k;

    for(int i=0;i<n;i++)
    {
        scanf("%s %d",op,&k);

        if(op[0]=='I')
        {
            int idx=k%m;
            int j=0;
            while(h[(idx+j*j)%m]!=EMPTY) j++;
            h[(idx+j*j)%m]=k;
        }
        else
        {
            int idx=k%m;
            int j=0,found=0;

            while(h[(idx+j*j)%m]!=EMPTY && j<m)
            {
                if(h[(idx+j*j)%m]==k){found=1;break;}
                j++;
            }

            if(found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}