#include <stdio.h>

struct Passenger
{
    char name[30];
    int PRN, age, seat;
} p[30];

void read_passenger(int val)
{
    for (int i = 0; i < val; i++)
    {
    }
}

void write_data(FILE *ptr, int i)
{
    printf("Enter the Passeger Name : ");
    scanf("%s", &p[i].name);
    printf("Enter the Passenger Age : ");
    scanf("%d", &p[i].age);
    printf("Enter the Passenger Seat No. : ");
    scanf("%d", &p[i].seat);
    printf("Enter The PRN number : ");
    scanf("%d", &p[i].PRN);
    fprintf(ptr, "%s %d %d %d", p[i].name, p[i].age, p[i].seat, p[i].PRN);
    fputc('\n', ptr);
}

int main()
{
    FILE *ptr = fopen("data.txt", "r");
    int count = 0;
    char c = getc(ptr);
    while (c != EOF)
    {
        if (c == '\n')
            count++;
        c = getc(ptr);
    }
    count++;
    printf("%d", count);
    if (ptr == NULL)
        printf("Error");
    else
    {
        int choice;
        printf("Choose the Option : \n1.Read the Passenger Data\n2.Add a Passenger\n3. Delete a Passenger");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            read_passenger(count);
            break;
        case 2:
            write_data(ptr, count);
            break;
        case 3:
            break;
        default:
            printf("Invalid Option");
        }
    }
    fclose(ptr);
    return 0;
}