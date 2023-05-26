#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char title[41];
    int lenght;
    int plays;
} TRACK;


int cmp(const void *a, const void *b){
    TRACK *left = (TRACK *) a;
    TRACK *right = (TRACK *) b;
    if(left->plays != right->plays){
        return - (left->plays - right->plays);
    }
    if(left->lenght != right->lenght){
        return (left->lenght - right->lenght);
    }

    if(strcmp(left->title,right->title) == 0){
        return strcmp(left->title,right->title);
    }
}

int main(){
    char line[101];
    int n = atoi(gets(line));
    TRACK tracks[n];
    for(int i = 0; i<n; i++){

        gets(line);
        char *title = strtok(line,";");
        char *lenght = strtok(NULL,";");
        char *plays = strtok(NULL,";");
        strcpy(tracks[i].title,title);
        tracks[i].lenght = atoi(lenght);
        tracks[i].plays = atoi(plays);
    }

    qsort(tracks, n, sizeof(TRACK), cmp);

    printf("\n");
    for(int j = 0; j<n;j++){
        printf("%s;%d;%d\n",tracks[j].title,tracks[j].lenght,tracks[j].plays);
    }

    return EXIT_SUCCESS;
}
