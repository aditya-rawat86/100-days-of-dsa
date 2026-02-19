/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        int alreadyCounted = 0;
        for(int k = 0; k < i; k++)
        {
            if(a[i] == a[k])
            {
                alreadyCounted = 1;
                break;
            }
        }
        if(alreadyCounted)
            continue;
        for(int j = 0; j < n; j++)
        {
            if(a[i] == a[j])
                count++;
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}
