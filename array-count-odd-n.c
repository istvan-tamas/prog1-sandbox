#include <stdio.h>

int count_of_odds(int *numbers, int length){
    int count = 0;
    for(int i = 0; i<length; i++){
        int flag = 1;
        for (int j = 2; j <= numbers[i] / 2; j++) {
        if (numbers[i] % j == 0) {
            flag = 0;
            break;
        }
        if (flag) {
        count++;
    }
}

}
    return count;
}

int main(){

    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        int length;
        scanf("%d",&length);

        int numbers[length];
        for(int j = 0; j<length; j++){
            scanf("%d",&numbers[j]);
        }
        printf("%d\n",count_of_odds(numbers,length));
    }

    return 0;
}
