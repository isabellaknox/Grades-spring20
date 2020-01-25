#include <stdio.h>
#include <stdlib.h>

int function(int N){
    if (N == 0){
        return 1;
    }
    if (N == 1){
        return 2;
    }
    return 3 * function(N-1)+ 4 * function(N-2) + 2;

}

int main(int arg, char *arv[]){
    int N = atoi(arv[1]);

    printf("%d\n", function(N));


// successfully exit program
    return EXIT_SUCCESS;
}