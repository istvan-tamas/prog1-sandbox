#include <stdio.h>
#include <string.h>
#include <ctype.h>

int delete_consonants(char *original){
    char *result = (char *) calloc(strlen(original) + 1, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(original); i++){
        if (!strchr("bcdfghjklmnpqrstvwxyz",tolower(original[i]))){
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
        char *result = delete_consonants(line);
        puts(result);
        free(result);
    }

    return 0;
}
