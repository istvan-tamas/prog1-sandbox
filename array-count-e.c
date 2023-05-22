#include <stdio.h>

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
    int length;
    while(scanf("%d",&length) != EOF){
        int numbers[length];
        for(int j = 0; j < length;j++){
            scanf("%d",&numbers[j]);
        }
        printf("%d",count_of_odds(numbers,length));
    }

    return 0;
}
