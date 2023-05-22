#include <stdio.h>

int count_of_local_minimums(int *numbers, int length){
    int count = 0;
    for(int j = 1;j < length - 1; j++){
        if((numbers[j-1] > numbers[j]) && (numbers[j+1] > numbers[j])){
            count++;
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
        printf("%d",count_of_local_minimums(numbers,length));

    }
    return 0;
}
