#include <stdio.h>
#include <stdlib.h>


// Queue node structure.
struct node
{

    int data;
    struct node* pNext;

}*pEntry, *pExit;

struct node *createNode(int data);


void enqueue(int data);
int dequeue();


void printQ();

int main()
{
    enqueue(5);
    enqueue(3);
    enqueue(8);
    enqueue(9);
    enqueue(11);
    enqueue(30);
    enqueue(79);


    printQ();

    dequeue();

    printf("\n");
    printQ();
    printf("\n");
    printQ();

    return 0;

}

struct node *createNode(int data)
{


    struct node *pNode= (struct node *)malloc(sizeof(struct node));

    if(pNode)
    {
        pNode->data= data;
        pNode -> pNext = NULL;
    }
    else
    {
        printf("No Memory Space.\n");
    }

}


void enqueue(int data)
{

    struct node*pNode = createNode(data);

    if(pNode)
    {
        if(pEntry)
        {
            // Not Empty
            pEntry->pNext = pNode;
            pEntry = pNode;
        }

        else
        {
            // Empty
            pEntry = pNode;
            pExit = pNode;
        }
    }





}


int dequeue()
{

    int data;

    if(pEntry)
    {

        data = pExit->data;

        struct node*pTemp= pExit;

        pExit = pExit->pNext;

        free(pTemp);

        return data;

    }
    else
    {
        printf("Queue is Empty.\n");
    }


    return -1;
}

void printQ()
{

    if(pEntry)
    {

        struct node*pCur = pExit;

        while(pCur)
        {
            printf("%d ", pCur->data);

            pCur=pCur->pNext;
        }
    }

}
