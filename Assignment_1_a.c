#include <stdio.h>

int main()
{
    int choice, num1, num2;
    printf("Enter two Numbers : ");
    scanf("%d%d", &num1, &num2);
    printf("Enter the task you want to perform :\n1.Addition\n2.Subtration\n3.Multipliction\n4.Division\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("The Addition of %d and %d is %d", num1, num2, num1 + num2);
        break;
    case 2:
        printf("The Subtraction of %d and %d is %d", num1, num2, num1 - num2);
        break;
    case 3:
        printf("The Multiplication of %d and %d is %d", num1, num2, num1 * num2);
        break;
    case 4:
        printf("The Division of %d and %d is %.2f", num1, num2, (float)num1 / num2);
        break;
    default:
        printf("Invalid Choice");
    }

    return 0;
}
