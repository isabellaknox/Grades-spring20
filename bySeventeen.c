#include <stdio.h>
#include <stdlib.h>

int main(int arg, char *arv[]){
    int N = atoi(arv[1]);
    int tot;
    int x;

    // get first N numbers divisible by 17 
    if(N>0){
    for (x =1; x <= N; x++){
        tot = 17 * x;
        printf("%d\n", tot);
        }
    }

    // successfully exit program
    return EXIT_SUCCESS;
}