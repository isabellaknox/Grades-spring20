#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int x;

    //get given integer
    printf("Enter integer: ");
    scanf("%s", N);

    // get first N numbers divisible by 17 
    for (x =0; x <= N; x++){
        printf("%d", 17*x)
    }

    // successfully exit program
    return EXIT_SUCCESS;
}