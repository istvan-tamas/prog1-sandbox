#include <stdio.h>
#include <stdlib.h>

int count_of_odds(int *numbers, int length){
    int count = 0;
    for(int j = 0;j < length; j++){
        if(numbers[j] % 2 != 0){
            count++;
        }
    }
    return count;
}

int main(){
    while(1){
        int length;
        scanf("%d",&length);
        if(length == 0){
            break;
        }
        int numbers[length];
        for(int j = 0; j < length;j++){
            scanf("%d",&numbers[j]);
        }
        printf("%d",count_of_odds(numbers,length));
    }

    return EXIT_SUCCESS;
}
