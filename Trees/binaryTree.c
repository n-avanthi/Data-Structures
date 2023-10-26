#include<stdio.h>
#include<stdlib.h>

typedef struct tnode
{
    struct tnode *lchild;
    int data;
    struct tnode *rchild;
}tnode;

tnode* createNode(int val)
{
    tnode* tn = (tnode*)malloc(sizeof(tnode));
    tn->lchild = NULL;
    tn->data = val;
    tn->rchild = NULL;
    printf("\nData has been inserted into tree\n");
    return tn;
}

void preorder(tnode *n)
{
    if(n == NULL)
    {
        return;
    } //termination condition


    printf("%d ", n->data);
    preorder(n->lchild);
    preorder(n->rchild);
}

void inorder(tnode *n)
{
    if(n == NULL)
    {
        return;
    } //termination condition

    inorder(n->lchild);
    printf("%d ", n->data);
    inorder(n->rchild);
}

void postorder(tnode *n)
{
    if(n == NULL)
    {
        return;
    } //termination condition

    postorder(n->lchild);
    postorder(n->rchild);
    printf("%d ", n->data);
}

tnode* insertNode(tnode *p, int x)
{
    if(p == NULL)
    {
        p = createNode(x);
    }
    else if(x < p->data)
    {
        p->lchild = insertNode(p->lchild, x);
    }
    else if(x > p->data)
    {
        p->rchild = insertNode(p->rchild, x);
    }
    else
    {
        printf("\n%d already in tree\n", x);
    }
    return p;
}

void search(tnode *tn, int key)
{
    if(tn == NULL)
    {
        printf("/nNOT FOUND");
        return;
    }
    if(key < tn->data)
    {
        search(tn->lchild, key);
    }
    if(key > tn->data)
    {
        search(tn->lchild, key);
    }
    if(key == tn->data)
    {
        printf("\nFOUND");
        return;
    }
}
void minElement(tnode *p)
{
    if(p->lchild == NULL)
    {
        printf("\nMinimum element is %d\n", p->data);
        return;
    }
    minElement(p->lchild);
}

void maxElement(tnode *p)
{
    if(p->rchild == NULL)
    {
        printf("\nMaximum element is %d\n", p->data);
        return;
    }
    maxElement(p->rchild);
}

int main()
{
    tnode* root = NULL;
    for(;;)
    {
        int ele, x, ch;
        printf("\nMENU OF BINARY SEARCH TREE\n");
        printf("\n1.Insert into tree");
        printf("\n2.Preorder traversal");
        printf("\n3.Inorder traversal");
        printf("\n4.Postorder traversal");
        printf("\n5.Search for an element");
        printf("\n6.Minimum element in tree");
        printf("\n7.Maximum element in tree");
        printf("\n8.Exit");
        printf("\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter element to be inserted into tree: ");
                scanf("%d", &ele);
                root = insertNode(root, ele);
                break;
            case 2:
                if(root == NULL)
                {
                    printf("\nTree is empty.. Insert elements to traverse!!\n");
                    break;
                }
                else
                {
                    printf("\nPreorder traversal - \n");
                    preorder(root);
                    break;
                }
            case 3:
                if(root == NULL)
                {
                    printf("\nTree is empty.. Insert elements to traverse!!\n");
                    break;
                }
                else
                {
                    printf("\nInorder traversal - \n");
                    inorder(root);
                    break;
                }
            case 4:
                if(root == NULL)
                {
                    printf("\nTree is empty.. Insert elements to traverse!!\n");
                    break;
                }
                else
                {
                    printf("\nPostorder traversal - \n");
                    postorder(root);
                    break;
                }
            case 5:
                printf("\nEnter element to be searched for: ");
                scanf("%d", &x);
                search(root, x);
            case 6:
                minElement(root);
                break;
            case 7:
                maxElement(root);
                break;
            case 8:
                exit(0); 
        }  
    }
    return 0;
}