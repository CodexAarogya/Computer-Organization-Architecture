// Addition of unsigned binary numbers in C
#include <stdio.h>  
#define size 5
int main(){
    int num1, num2, result[size];  // size_of num1, num2 = 4
    int temp1, temp2;
    int carry = 0, sum;
    int i = size-1;
    printf("Enter value for num1 and num2: ");
    scanf("%d %d", &num1,&num2);
    do
    {
        temp1 = num1 % 10;  // extracting last digit of num1
        temp2 = num2 % 10;  // extracting last digit of num2
        sum = (temp1 + temp2 + carry) % 2;  
        carry = (temp1 + temp2 + carry) / 2;
        result[i] = sum;
        num1 = num1 / 10;  // removing last digit of num1   
        num2 = num2 / 10;  // removing last digit of num2
        i--;
        
    } while (i > 0);
    result[i] = carry;  // storing final carry
    printf("Result of addition is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", result[i]);
    }
    
}   