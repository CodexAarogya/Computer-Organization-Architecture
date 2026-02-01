#include <stdio.h>
#include <stdlib.h>

#define size 4
int A[size] = {0, 0, 0, 0};
int Q[size] = {0, 0, 1, 1};
int M[size] = {0, 1, 1, 1};
int M_comp[size] = {1, 0, 0, 1};

int *left_shift(int A[], int Q[])
{
    for (int i = 0; i < 4; i++)
    {
        printf("%d", Q[i]);
    }
    printf("\n");

    int *shift_array = (int *)malloc((size * 2) * sizeof(int));
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        shift_array[i] = A[i];
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d", shift_array[i]);
    }
    printf("\n");
    for (int i = size; i < size * 2; i++)
    {
        shift_array[i] = Q[j];
        j++;
    }
    for (int i = size; i < size * 2; i++)
    {
        printf("%d", shift_array[i]);
    }
    printf("\n");

    for (int i = 0; i < size * 2; i++)
    {
        shift_array[i] = shift_array[i + 1];
    }

    for (int i = 0; i < size * 2; i++)
    {
        printf("%d", shift_array[i]);
    }
    printf("\n");
    return shift_array;
}

int *sum(int A[], int M_comp[])
{
    int i, temp1, temp2, carry = 0, i_mediate_sum;
    int *result = (int *)malloc(size * sizeof(int));

    for (i = size - 1; i >= 0; i--)
    {
        temp1 = A[i];
        temp2 = M_comp[i];
        i_mediate_sum = (temp1 + temp2 + carry) % 2;
        carry = (temp1 + temp2 + carry) / 2;
        result[i] = i_mediate_sum;
    }

    return result;
}

int main()
{
    int *shift_array = (int *)malloc((size * 2) * sizeof(int));
    shift_array = left_shift(A, Q);
    for (int i = 0; i < size; i++)
    {
        A[i] = shift_array[i];
    }
    int j = 0;
    for (int i = size; i < size * 2; i++)
    {
        Q[j] = shift_array[i];
    }
    free(shift_array);
    shift_array = sum(A, M_comp);
    for (int i = 0; i < size; i++)
    {
        A[i] = shift_array[i];
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
}