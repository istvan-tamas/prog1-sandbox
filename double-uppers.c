#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *double_uppers(char *original){
    char *result = (char *) calloc(strlen(original) * 2 + 1, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(original); i++){
        if (isupper(original[i])){
            result[j] = original[i];
            j++;
        }
        result[j] = original[i];
        j++;
    }
    return result;
}

int main(){

    char line[101];

    int n = atoi(gets(line));
    for(int i=0; i<n; i++){
        gets(line);
        char *result = double_uppers(line);
        puts(result);
        free(result);
    }

    return 0;
}
