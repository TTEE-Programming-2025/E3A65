#include <stdio.h>
#include <stdlib.h>

int formula(int N){
    int sum = 0;
    for (int i = 1; i <= N; i += 2){
        sum += i;
    }
    return sum;
}

int main ()
{
    int N, totalsum=0;

    while (1){
        printf("Please enter an odd number:");
        scanf("%d", &N);

        if (N == 0)
            break;
        
        if (N < 1 || N % 2 == 0){
            printf("Re-enter:\n");
            continue;
        } 

    int sum = formula(N);
    totalsum += sum; 
    }   

    printf("The total numbers are:%d\n", totalsum);
    
    return 0;
}