#include <stdio.h>

// --             --
// |   1   2   3   |
// |               |
// |               |
// --             --


int main(){
    int stud[][2] = {{1,2}, {2,3}, {3,4}, {4,5}};
    for(int i =0 ; i < 4; i++)
    for(int j = 0 ; j < 2; j++)
        printf("%d\t", *(*(stud + i)+j));
    return 0;
}