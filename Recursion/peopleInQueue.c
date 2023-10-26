#include<stdio.h>

int peopleQueue(int n, int tot)
{
    if(n == 0)
    {
        printf("\nBase condition achieved");
        return tot;
    }
    else
    {
        tot += 1;
        peopleQueue(n - 1, tot);
    }
}

int main()
{
    int total = peopleQueue(5, 0);
    printf("\nTotal is %d", total);
}