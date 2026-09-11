#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int n, i, j, k;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &B[i][j]);


    // Matrix Addition
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nAddition:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }


    // Matrix Multiplication
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            C[i][j] = 0;

            for(k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("\nMultiplication:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }


    // Check symmetric
    int symmetric = 1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(A[i][j] != A[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    if(symmetric)
        printf("\nMatrix A is symmetric\n");
    else
        printf("\nMatrix A is not symmetric\n");


    // Transpose
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {

            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    printf("\nTranspose:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", A[i][j]);

        printf("\n");
    }

    return 0;
}