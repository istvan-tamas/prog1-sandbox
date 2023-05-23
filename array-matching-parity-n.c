#include <stdio.h>

int has_matching_parity(int *numbers, int length){
    for(int j = 0; j<= length; j++){
        if(!numbers[j] == j){
            return 0;
        }
    }
    return 1;
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
        puts(has_matching_parity(numbers,length) ? "True" : "False");

    }
    return 0;
}
