#include <stdio.h>

int n;


void decimalToBinary(int num, int arr[]) {
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = num % 2;
        num /= 2;
    }
}


int binaryToDecimal(int arr[]) {
    int value = 0;
    for (int i = 0; i < n; i++) {
        value = value * 2 + arr[i];
    }
    return value;
}

void print(int arr[]) {
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
}

void leftShift(int A[], int Q[]) {
    int temp = Q[0];

    for (int i = 0; i < n - 1; i++)
        A[i] = A[i + 1];
    A[n - 1] = temp;

    for (int i = 0; i < n - 1; i++)
        Q[i] = Q[i + 1];
    Q[n - 1] = 0;
}

int subtract(int A[], int M[]) {
    int borrow = 0;
    for (int i = n - 1; i >= 0; i--) {
        int diff = A[i] - M[i] - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        A[i] = diff;
    }
    return borrow;
}

void add(int A[], int M[]) {
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int sum = A[i] + M[i] + carry;
        A[i] = sum % 2;
        carry = sum / 2;
    }
}

int main() {
    int dividend, divisor;
    int A[10] = {0}, Q[10], M[10];

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter dividend (decimal): ");
    scanf("%d", &dividend);

    printf("Enter divisor (decimal): ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Error: Division by zero not allowed\n");
        return 0;
    }

    
    decimalToBinary(dividend, Q);
    decimalToBinary(divisor, M);

    
    for (int i = 0; i < n; i++) {
        leftShift(A, Q);

        int borrow = subtract(A, M);

        if (borrow) {
            add(A, M);     
            Q[n - 1] = 0;
        } else {
            Q[n - 1] = 1;
        }
        printf("\n\nStep %d:", i + 1);
        printf("\nA = "); print(A);
        printf("\nQ = "); print(Q);
    }

  
    int quotient = binaryToDecimal(Q);
    int remainder = binaryToDecimal(A);

    printf("\nFinal Result:");
    printf("\nQuotient  = %d", quotient);
    printf("\nRemainder = %d\n", remainder);

    return 0;
}
