/* Write a program that reverses a given list of characters. Store the characters choosing a suitable data structure and perform the 
reversal of the input stored in the data structure.

Input:
Each character will be input in a new (separate) line.
When the input character is a '.', you can ignore the '.' and stop scanning for more input (i.e.) you have reached the end of the list of characters.

Output:
Display the characters, each in a new line, in reverse order. */

//we use stacks for this question as it is LIFO hence when printing the stack, it prints in reverse or it can be done through poping the stack

#include<stdio.h>
#define SIZE 7

int top = -1;
char stack[SIZE];

void push(char ele)
{
    if(top == SIZE-1) 
    {
        //printf("Stack overflow\n");
        return;
    }
    stack[++top] = ele;
}

void pop()
{
    while(top != -1) //UNDERFLOW
    {
        printf("%c\n", stack[top]);
        top--;
    }
}

void display() //incase pop doesnt work
{
    while(top != -1) //UNDERFLOW
    {
        for(int i = top; i >= 0; i++)
        {
            printf("%c\n", stack[top]);
        }
    }
}

int main()
{
    char ele;
    while(1)
    {
        scanf(" %c", &ele);
        if(ele == '.')
        {
            pop();
            break;
        }
        push(ele);
    } 
}