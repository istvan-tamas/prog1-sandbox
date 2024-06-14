#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *delete_digits(char *original){
    char *result = (char *) calloc(strlen(original) + 1, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(original); i++){
        if (!isdigit(original[i])){
            result[j] = original[i];
            j++;
        }
    }
    return result;
}

int main(){

    char line[101];

    int n = atoi(gets(line));
    for(int i=0; i<n; i++){
        gets(line);
        char *result = delete_digits(line);
        puts(result);
        free(result);
    }

    return 0;
}
