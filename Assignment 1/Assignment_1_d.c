#include <stdio.h>

int main(){
    char str[100], fstr[100];
    scanf("%s", &str);
    for(int i = 0 ; i < 100; i++){
        if(str[i] <= 'z' && str[i] >= 'a') fstr[i] = str[i] - 32;
        else if (str[i] <= 'Z' && str[i] >= 'A')
            fstr[i] = str[i] + 32;
    }
    printf("%s", fstr);
    return 0;
}