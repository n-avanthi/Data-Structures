/* Vowel shooter, using a queue implemented as an array.
Store the input characters choosing a suitable data structure such that
when the input character is a vowel, remove the first of the currently remaining input characters from the data structure. Do not add the vowel itself to the data structure.
When the input character is a '.', display the elements in the data structure and end the game(program).
If there are no elements at all in the data structure at the time of display, display EMPTY. Implement the data structure using an array.

Input:
Each character will be input in a new (separate) line.

Output:
Display the characters, each in a new line.
If there are no characters at all in the data structure, display EMPTY */

#include <stdio.h>
#define size 8
int front = -1, rear = -1;
char queue[size];

void enqueue(int ele)
{
    if (rear == size - 1)
    {
        printf("Queue full\n");
        return;
    }
    if (front == -1)
    {
        front++;
    }
    rear++;
    queue[rear] = ele;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        return;
    }
    front++;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("EMPTY");
        return;
    }
    while (front <= rear)
    {
        printf("%c\n", queue[front]);
        front++;
    }
}

int main()
{
    char ele;
    for (;;)
    {
        scanf(" %c", &ele);
        if (ele == '.')
        {
            display();
            break;
        }
        else if (ele == 'a' || ele == 'e' || ele == 'i' || ele == 'o' || ele == 'u' || ele == 'A' || ele == 'E' || ele == 'I' || ele == 'O' || ele == 'U')
        {
            dequeue();
        }
        else
        {
            enqueue(ele);
        }
    }
}