#include <iostream>
#include <string.h>

using namespace std;

void reverseString(char *str);

void setMatrixRowColToZero(int **pArray, int M, int N);

int main()
{
    int a[4][3] = {{1,2,3},
                   {2,0,5},
                   {3,2,0},
                   {4,7,8}
                    };

    cout << "the original array:" << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    setMatrixRowColToZero((int **)a, 4, 3);

    cout << "now the array is:" << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

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
