#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int x;
    int tot;

    //get given integer
    printf("Enter integer to get answer: ");
    scanf("%d", &N);

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