#include<stdio.h>


int sumRange(int n, int tot)
{
    if(n == 0)
    {
        printf("\nBase condition achieved");
        return tot;
    }
    else
    {
        tot += n;
        sumRange(n - 1, tot);
    }
}

int main()
{
    int total = sumRange(5, 0);
    printf("\nTotal is %d", total);
}