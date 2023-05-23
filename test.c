#include <stdio.h>
#include <stdlib.h>

int count_of_odds(int *numbers, int length) {
    // printf("%d\n", sizeof(numbers));
    int result = 0;
    for(int i=0; i<length; i++) {
        if(numbers[i] % 2 != 0){
            result++;
        }
    }
    return result;
}

void print_numbers(int *numbers, int length) {
    printf("%d", numbers[0]);
    for(int i=1; i<length; i++) {
        printf(" %d", numbers[i]);
    }
    printf("\n");
}

int main() {
    int length;
    while(scanf("%d", &length) != EOF) {
        int numbers[length];

        for(int j=0; j<length; j++) {
            scanf("%d", &numbers[j]); //numbers + j
        }

        // print_numbers(numbers, length);
        printf("%d\n", count_of_odds(
            numbers, length));
    }

    return EXIT_SUCCESS;
}
