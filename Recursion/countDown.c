#include<stdio.h>

void countDown(int n)
{
    if(n == 0)
    {
        printf("\nBase conditon achieved\n");
    }
    else
    {
        printf("\n%d", n);
        countDown(n-1);
    }
}

int main()
{
    countDown(5);
    return 0;
}