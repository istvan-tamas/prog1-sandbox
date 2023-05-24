#include <stdio.h>
#include <math.h>

int count_of_primes(int *numbers, int length){
    int count = 0;
    for(int i = 0; i < length; i++){
        if(numbers[i] == 2){
            count++;
            continue;
        }
        if(numbers[i] == 1){
            continue;
        }
        if(numbers[i] != 2){
            int flag = 1;
            for(int j = 2; j<numbers[i];j++){
                if(numbers[i]%j == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                count++;
                continue;
            }
        }
    }
    return count;
}


int main(){
    int num_arrays;
    printf("How many Arrays to test?\n");
    scanf("%d",&num_arrays);
    for(int i = 0;i<num_arrays;i++){
        int length;
        printf("How many elements?\n");
        scanf("%d",&length);
        int numbers[length];
        for(int j = 0; j< length;j++){
            scanf("%d",&numbers[j]);
        }
        printf("%d",count_of_primes(numbers,length));

    }
    return 0;
}
