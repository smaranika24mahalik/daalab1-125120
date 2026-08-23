#include <stdio.h>

#define MAX 64

// Add two matrices
void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Subtract two matrices
void subtract(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Divide-and-conquer multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    // Base case
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];

    int P1[MAX][MAX], P2[MAX][MAX];
    int P3[MAX][MAX], P4[MAX][MAX];

    int C1[MAX][MAX], C2[MAX][MAX];

    /*
        A = | A1 A2 |
            | A2 A1 |

        B = | B1 B2 |
            | B2 B1 |
    */

    // Extract unique blocks
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    /*
        C1 = A1*B1 + A2*B2
        C2 = A1*B2 + A2*B1
    */

    multiply(A1, B1, P1, k);
    multiply(A2, B2, P2, k);
    add(P1, P2, C1, k);

    multiply(A1, B2, P3, k);
    multiply(A2, B1, P4, k);
    add(P3, P4, C2, k);

    // Construct final matrix
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C1[i][j];
            C[i][j + k] = C2[i][j];

            C[i + k][j] = C2[i][j];
            C[i + k][j + k] = C1[i][j];
        }
    }
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n;

    printf("Enter size of matrix (power of 2): ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    multiply(A, B, C, n);

    printf("\nResult Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}