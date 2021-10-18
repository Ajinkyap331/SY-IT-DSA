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
    printf("\n\n\nEnter another string to compare : ");
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
    printf(flag ? "Strings are equal" : "Strings are not equal");
}

void palindrome(char str[], int len)
{
    char str1[100], counter = 0, flag = 1;
    while (len--)
        str1[counter++] = str[len];
    for (int i = 0; i < len; i++)
    {
        if (str[i] != str1[i])
        {
            flag = 0;
            break;
        }
    }
    printf(flag ? "\n\n\nPalindrome" : "\n\n\nNot a Palindrome");
}

void substring(char str[], int len)
{
    printf("\n\n\nEnter another string to find substring : ");
    char str2[100];
    scanf("%s", &str2);
    int len2 = length(str2), flag = 0, con = 0;
    if (len2 <= len)
    {
        for (int i = 0, j = 0; i < len; i++)
        {
            if (str[i] == str2[j])
            {
                flag = 1;
                con = 1;
                j++;
            }
            else if (con && j < len2)
            {
                flag = 0;
                break;
            }
            else
            {
                con = 0;
            }
        }
    }
    printf(flag ? "\n\nYes It is a substring" : "\n\n   No It is not a substring");
}

int main()
{
    char str[100];
    scanf("%s", &str);
    int len = length(str);
    printf("Length of the String : %d\n\n\n", len);
    reverse(str, len);
    equals(str);
    palindrome(str, len);
    substring(str, len);
    return 0;
}