/* Write a program for creating a Binary Search tree(BST) that stores a set of positive integers. 
Search for the specific element in the BST.

Note: First line of input contains key element to be searched.

Input:
One integer in one line.
The end of the list will be indicated through an input of -1. Do not add the -1 itself to the list.

Output:
Display FOUND, if found. If not found, display NOT FOUND. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lchild;
    int val;
    struct node *rchild;
}node;

node* createNode(int ele)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->lchild = NULL;
    newNode->val = ele;
    newNode->rchild = NULL;
    return newNode;
}

node* insertNode(node *parent, int ele)
{
    if(parent == NULL)
    {
        parent = createNode(ele);
    }
    if(ele < parent->val)
    {
        parent->lchild = insertNode(parent->lchild, ele);
    }
    else if(ele > parent->val)
    {
        parent->rchild = insertNode(parent->rchild, ele);
    }
    return parent;
}

void search(node* parent, int key)
{
    if(parent == NULL)
    {
        printf("NOT FOUND");
        return;
    }
    if(key < parent->val)
    {
        search(parent->lchild, key);
    }
    else if(key > parent->val)
    {
        search(parent->rchild, key);
    }
    else
    {
        printf("FOUND");
        return;
    }
}

int main()
{
    int ele, key;
    node *root = NULL;
    scanf("%d", &key);
    while(1)
    {
        scanf("%d", &ele);
        if(ele == -1)
        {
            break;
        }
        root = insertNode(root, ele);
    }
    search(root, key);
}