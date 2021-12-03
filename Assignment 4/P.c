#include <stdio.h>
#include <string.h>

struct Data
{
    char name[100], country[30];
    int age, odi, inter, category, avgbat, wikets;
} data[100];

int players = 0;

void input(int pos[])
{
    for (int i = 0; i < players; i++)
    {
        printf("Enter the Name of Player %d : ", i + 1);
        scanf("%s", &data[i].name);
        printf("Enter the Age of Player %d : ", i + 1);
        scanf("%d", &data[i].age);
        printf("Enter the Country of Player %d : ", i + 1);
        scanf("%s", &data[i].country);
        printf("Enter the Category of Player %d : \n1.Batsman\n2.Bowler\n3.Wicket kepper\n4.All Rounder\n", i + 1);
        scanf("%d", &data[i].category);
        printf("Enter the Average Batting Score of Player %d : ", i + 1);
        scanf("%d", &data[i].avgbat);
        printf("Enter the Number of ODIs played by Player %d : ", i + 1);
        scanf("%d", &data[i].odi);
        printf("Enter the Number of Internation Match played by Player %d : ", i + 1);
        scanf("%d", &data[i].inter);
        printf("Enter the Wickets Taken %d : ", i + 1);
        scanf("%d", &data[i].wikets);
        pos[i] = i;
    }
}

void swap(int *xp, int *yp, int pos[], int j)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    int t = pos[j];
    pos[j] = pos[j + 1];
    pos[j + 1] = t;
}

void sort(struct Data data1[], int pos[])
{

    for (int i = 0; i < players - 1; i++)
        for (int j = 0; j < players - i - 1; j++)
            if (data1[j].avgbat < data1[j + 1].avgbat)
                swap(&data1[j].avgbat, &data1[j + 1].avgbat, pos, j);
    printf("\n");
    for (int i = 0; i < players; i++)
        printf("%s %s %d\n", data1[pos[i]].name, data1[pos[i]].country, data[i].avgbat);
}

void search()
{
    int max = 0, index = 0;
    for (int i = 0; i < players; i++)
        if (max <= data[i].age)
        {
            max = data[i].age;
            index = i;
        }
    printf("Max Age is of Player : %s\n", data[index].name);
}

void maxwikets()
{
    int max = 0, index = 0;
    for (int i = 0; i < players; i++)
        if (max <= data[i].wikets)
        {
            max = data[i].wikets;
            index = i;
        }
    printf("Max Wickets is of Player : %s\n", data[index].name);
}

void batsman()
{
    int batsman = 0;
    printf("Enter The Country Name : ");
    char con[30];
    scanf("%s", &con);
    for (int i = 0; i < players; i++)
        if (!strcmp(con, data[i].country) && (data[i].category == 1 || data[i].category == 4))
            batsman++;
    printf("There are %d batsman in %s", batsman, con);
}

void bowlers()
{
    int bowler = 0;
    printf("Enter The Country Name : ");
    char con[30];
    scanf("%s", &con);
    for (int i = 0; i < players; i++)
        if (!strcmp(con, data[i].country) && (data[i].category == 2 || data[i].category == 4))
            bowler++;
    printf("There are %d bowlers in %s", bowler, con);
}

void display()
{
    printf("Enter The Player Name : ");
    char pla[30];
    scanf("%s", &pla);
    int i;
    for (i = 0; i < players; i++)
        if (!strcmp(pla, data[i].name))
        {
            printf("Name : %s\nCountry : %s\nAge : %d\nODI : %d\nInternational : %d\nAverage Batting : %d\n Wickets : \nCategory : ", data[i].name, data[i].country, data[i].age, data[i].odi, data[i].inter, data[i].avgbat, data[i].wikets);
            if (data[i].category == 1)
                printf("Batsman");
            else if (data[i].category == 2)
                printf("Bowler");
            else if (data[i].category == 3)
                printf("Wicket Keeper");
            else
                printf("All Rounder");
            break;
        }
    if (i == players)
        printf("NO PLAYER FOUND");
}
int main()
{

    printf("Enter the Number of Players : ");
    scanf("%d", &players);
    int pos[players];
    input(pos);
    int choice;
    printf("Choice from the Following :\n1. Batsman from Particular Country\n2. Max Average Batting\n3. Batsman with Highest Age\n4. Number of Bowler from a Particular Country\n5. Maximum Wickets\n6. Player Entire Data\n");
    scanf("%d", &choice);
    while (1)
    {
        switch (choice)
        {
        case 1:
            batsman();
            break;
        case 2:
            sort(data, pos);
            break;
        case 3:
            search();
            break;
        case 4:
            bowlers();
            break;
        case 5:
            maxwikets();
            break;
        case 6:
            display();
            break;
        default:
            break;
        }
        printf("\nEnter 0 to exit 1 to continue : ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        printf("Choice from the Following :\n1. Batsman from Particular Country\n2. Max Average Batting\n3. Batsman with Highest Age\n4. Number of Bowler from a Particular Country\n5. Maximum Wickets\n6. Player Entire Data\n");
        scanf("%d", &choice);
    }
    return 0;
}