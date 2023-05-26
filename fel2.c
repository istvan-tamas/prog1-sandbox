#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *delete_uppers(char *original){
    char *updated = (char *) calloc(strlen(original) + 1,sizeof(char));
    int j = 0;
    for(int i=0;i<strlen(original);i++){
        if(!isupper(original[i])){
            updated[j] = original[i];
            j++;
        }
    }
    return updated;
}

int main(){
    while(1){
        char line[101];
        gets(line);
        if(strcmp(line,"END") == 0){
            break;
        }
        char* test = delete_uppers(line);
        puts(test);
        free(test);
    }
    return 0;
}
