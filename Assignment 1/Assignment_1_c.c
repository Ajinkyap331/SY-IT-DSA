#include <stdio.h>
#include <string.h>
struct Pro
{
    char code[10];
    char name[20];
    int price;
} product[4];

struct Bill
{
    char name[10];
    int quantity;
    int price;
} bill[100];

void setdata()
{
    strcpy(product[0].code, "ajwak");
    strcpy(product[0].name, "Pen");
    product[0].price = 10;

    strcpy(product[1].code, "efidf");
    strcpy(product[1].name, "Book");
    product[1].price = 50;

    strcpy(product[2].code, "iegge");
    strcpy(product[2].name, "Eraser");
    product[2].price = 5;

    strcpy(product[3].code, "iwefh");
    strcpy(product[3].name, "Ruler");
    product[3].price = 15;
}
int main()
{
    char cont = 'y';
    int counter = 0, fprice = 0;
    setdata();
    printf("\n\t\t\tWelcome to the Store\n\nWhat do you want to buy?\n\n");
    while (cont == 'y')
    {
        printf("Sr.No\tName\tCode\tprice\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d.\t%s\t%s\tRs.%d\n", i + 1, product[i].name, product[i].code, product[i].price);
        }
        int choice, quantity;
        scanf("%d", &choice);
        printf("Enter the quantity you want : ");
        scanf("%d", &quantity);
        switch (choice)
        {
        case 1:
            strcpy(bill[counter].name, product[0].name);
            bill[counter].quantity = quantity;
            bill[counter].price = product[0].price * quantity;
            break;
        case 2:
            strcpy(bill[counter].name, product[1].name);
            bill[counter].quantity = quantity;
            bill[counter].price = product[1].price * quantity;
            break;
        case 3:
            strcpy(bill[counter].name, product[2].name);
            bill[counter].quantity = quantity;
            bill[counter].price = product[2].price * quantity;
            break;
        case 4:
            strcpy(bill[counter].name, product[3].name);
            bill[counter].quantity = quantity;
            bill[counter].price = product[3].price * quantity;
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Do you want to buy more things (y/n) : ");
        scanf(" %c", &cont);
        counter++;
    }
    printf("\n\t\t\tYour Bill is\n");
    printf("Sr.No.\tName\tQuantity\tPrice\n");
    for (int i = 0; i < counter; i++)
    {
        printf("%d\t%s\t%d\t\t%d\n", i + 1, bill[i].name, bill[i].quantity, bill[i].price);
        fprice += bill[i].price;
    }
    printf("Final Bill : %d", fprice);
}