#include <stdio.h>
#include <string.h>

int is_monotone_decreasing(int *numbers, int length){
    int flag = 0;
    for(int j = 1;j < length; j++){
        if(numbers[j] >= numbers[j+1]){
            flag = 1;
        }
    }
    return flag;
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
        puts(is_monotone_decreasing(numbers,length) ? "True" : "False");



    }
    return 0;
}
