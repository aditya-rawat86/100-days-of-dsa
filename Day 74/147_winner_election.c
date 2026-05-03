/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);

    char a[n][100];
    for(int i=0;i<n;i++) scanf("%s",a[i]);

    int max=0;
    char res[100];

    for(int i=0;i<n;i++)
    {
        int count=1;
        for(int j=i+1;j<n;j++)
            if(strcmp(a[i],a[j])==0) count++;

        if(count>max)
        {
            max=count;
            strcpy(res,a[i]);
        }
        else if(count==max)
        {
            if(strcmp(a[i],res)<0) strcpy(res,a[i]);
        }
    }

    printf("%s %d",res,max);
    return 0;
}