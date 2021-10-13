#include <stdio.h>

int length(char str[])
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void reverse(char str[], int len)
{
    printf("Reverse String is : ");
    while (len--)
        printf("%c", str[len]);
}

void equals(char str[])
{
    printf("\nEnter another string to compare : ");
    char str2[100];
    int flag = 1;
    scanf("%s", &str2);
    int len1 = length(str), len2 = length(str2);
    if (len1 == len2)
    {
        for (int i = 0; i < len1; i++)
        {
            if (str[i] != str2[i])
            {
                flag = 0;
                break;
            }
        }
    }
    else
        flag = 0;
    printf(flag ? "YES" : "NO");
}

int main()
{
    char str[100];
    scanf("%s", &str);
    int len = length(str);
    printf("Length of the String : %d\n", len);
    reverse(str, len);
    equals(str);
    return 0;
}