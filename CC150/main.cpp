#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void reverseString(char *str);

void setMatrixRowColToZero(int **pArray, int M, int N);

/*
Given a circular linked list, implement an algorithm which returns node at the begin-
ning of the loop
DEFINITION
Circular linked list: A (corrupt) linked list in which a node¡¯s next pointer points to an
earlier node, so as to make a loop in the linked list
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C
*/
struct Node
{
    int     value;
    Node*   next;
};

struct Node * FindLoopPort(Node* pHead);

int main()
{
    struct Node head;
    head.value = 1;
    head.next = NULL;

    struct Node *p = &head;
    for(int i = 0; i < 3; i++)
    {
        int data;
        cin >> data;

        struct Node * nd = (Node*)malloc(sizeof(Node));
        nd->value = data;
        nd->next = NULL;

        p->next = nd;
        p = nd;
    }

    p->next = head.next;

    struct Node * firstNode = FindLoopPort(&head);

    cout << firstNode->value << endl;

    return 0;
}

void setMatrixRowColToZero(int **pArray, int M, int N)
{
    int hasZeroRow[M], hasZeroCol[N];

    memset(hasZeroRow, 0, M*sizeof(int));
    memset(hasZeroCol, 0, N*sizeof(int));

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(*((int*)pArray+i*N+j) == 0)
            {
               hasZeroRow[i] = 1;
               break;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(*((int*)pArray+j*N+i) == 0)
            {
                hasZeroCol[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        if(hasZeroRow[i])
        {
            for(int j = 0; j < N; j++)
            {
                *((int*)pArray+i*N+j) = 0;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if(hasZeroCol[i])
        {
            for(int j = 0; j < M; j++)
            {
                *((int*)pArray+j*N+i) = 0;
            }
        }
    }
}



void reverseString(char *str)
{
    if (!str || str == '\0') return;

    char *p, *q;

    p = str;
    q = str;

    while(*(q+1) != '\0') q++;

    for (; p < q; p++, q--)
    {
        char temp = *p;
        *p = *q;
        *q = temp;
    }
}

struct Node * FindLoopPort(Node* pHead)
{
    Node* pSlow, *pFast;
    pSlow = pFast = pHead;

    while(pFast != NULL && pFast->next != NULL)
    {
        pSlow = pSlow->next;
        pFast= pFast->next->next;

        if(pSlow == pFast)
            break;
    }

    if(pFast == NULL || pFast->next == NULL)
        return NULL;

    pSlow = pHead;

    while(pSlow != pFast)
    {
        pSlow = pSlow->next;
        pFast = pFast->next;
    }

    return pSlow;
}
