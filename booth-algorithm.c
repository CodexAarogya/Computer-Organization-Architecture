#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int A[SIZE] = {0, 0, 0, 0};
int Q[SIZE] = {0, 1, 0, 1};
int M[SIZE] = {0, 1, 1, 1};
int M_comp[SIZE] = {1, 0, 0, 1};
int Qo = 0;
int count = 4;

int *right_shift(int A[], int Q[], int Qo)
{
    int *shift_array = (int *)malloc(((SIZE * 2) + 1) * sizeof(int));
    static int i;
    int j = 0;
    for (i = 0; i < SIZE; i++)
    {
        shift_array[i] = A[i];
    }
    for (i = SIZE; i < (SIZE * 2); i++)
    {
        shift_array[i] = Q[j];
        j++;
    }
    shift_array[i] = Qo;

    while (i > 0)
    {
        shift_array[i] = shift_array[i - 1];
        i--;
    }

    return shift_array;
}

int *sum(int A[], int M[])
{
    int i, temp1, temp2, carry = 0, i_mediate_sum;
    int *result = (int *)malloc(SIZE * sizeof(int));

    for (i = SIZE - 1; i >= 0; i--)
    {
        temp1 = A[i];
        temp2 = M[i];
        i_mediate_sum = (temp1 + temp2 + carry) % 2;
        carry = (temp1 + temp2 + carry) / 2;
        result[i] = i_mediate_sum;
    }

    return result;
}

int *compare(int A[], int Q[], int M[], int M_comp[], int Qo)
{
    int LSB_Q = Q[SIZE - 1];
    int check = LSB_Q * 10 + Qo;
    int *temp_acc = (int *)malloc(SIZE * sizeof(int));
    if (check == 10)
    {
        temp_acc = sum(A, M_comp);
    }
    if (check == 1)
    {
        temp_acc = sum(A, M);
    }

    return temp_acc;
}

int main()
{
    int *temp_acc;
    for (int test = 0; test < 2; test++)
    {
        static int j;
        int i = 0;

        temp_acc = compare(A, Q, M, M_comp, Qo);

        for (int i = 0; i < SIZE; i++)
        {
            A[i] = temp_acc[i];
        }

        free(temp_acc);

        temp_acc = right_shift(A, Q, Qo);
        for (int i = 0; i < 9; i++)
        {
            printf(".%d.", temp_acc[i]);
        }
        printf("end");
        for (j = 0; j < (SIZE); j++)
        {
            A[j] = temp_acc[j];
        }
        for (j = SIZE; j < (SIZE * 2); j++)
        {
            Q[i] = temp_acc[j];
        }
        Qo = temp_acc[j];

        printf("\n");
        printf("A: ");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d", A[i]);
        }

        printf("\n");
        printf("Q: ");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d", Q[i]);
        }

        printf("\n");
        printf("Qo: %d", Qo);
        free(temp_acc);
    }
}
