#include <stdio.h>

void prime(int A, int B){
    for(int i = A+1; i < B; i++){
        int _prime = 1;
        for(int j = 2; j < i-1 ; j++){
            if(i % j == 0) {
                _prime = 0;
                break;
            }
        }
        if(_prime) printf("%d ", i);
    }
}


int main(){
    printf("Enter two Numbers: ");
    int a, b;
    scanf("%d%d", &a, &b);
    prime(a, b);
    return 0;
}