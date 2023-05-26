#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_strictly_monotone_increasing(int* numbers, int length){
    for(int i=1;i<length-1;i++){
        if(numbers[i]>numbers[i-1]&&numbers[i+1]>numbers[i]){
            return 1;
        }
    }
    return 0;
}

int main(){

    int length;
    while(scanf("%d",&length) != EOF){
        int numbers[length];
        for(int i=0; i<length;i++){
            scanf("%d",&numbers[i]);
        }
        puts(is_strictly_monotone_increasing(numbers,length) ? "igaz" : "hamis");
    }
    return 0;
}
