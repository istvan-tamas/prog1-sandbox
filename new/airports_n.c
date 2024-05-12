#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    char city[31];
    int runways;
    int time;

} AIRPORT;

int cmp(const void *a, const void*b){
    AIRPORT *left = (AIRPORT *) a;
    AIRPORT *right = (AIRPORT *) b;

    if(left->runways != right->runways){
        return -(left->runways - right->runways);
    }
    if(left->time != right->time){
        return -(left->time - right->time);
    }
    return strcmp(left->name, right->name);

}


int main(int argc, char *argv[]){
    char line[102];
    int n = atoi(gets(line));
    AIRPORT airports[n];
    

    if(argc == 1){
        fprintf(stderr, "Nincsen input\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if(!file){
        fprintf(stderr, "Nem lehet megnyitni a fajlt\n");
        return 2;
    }
/*
    while(fgets(line, sizeof(line), file)){
        line[strlen(line)-1] = '\0';
        strcpy(airports[length].name, strtok(line, ";"));
        strcpy(airports[length].city, strtok(NULL, ";"));
        airports[length].runways = atoi(strtok(NULL, ";"));
        airports[length].time = atoi(strtok(NULL, ";"));
        length++;
    }*/

    for(int i = 0; i < n; i++){
        fgets(line, sizeof(line), file);
        line[strlen(line)-1] = '\0';
        strcpy(airports[i].name, strtok(line, ";"));
        strcpy(airports[i].city, strtok(NULL, ";"));
        airports[i].runways = atoi(strtok(NULL, ";"));
        airports[i].time = atoi(strtok(NULL, ";"));
    }

    fclose(file);
    qsort(airports, n, sizeof(AIRPORT), cmp);
    
if(argc == 2){
    fprintf(stderr, "Nincsen output\n");
    return 3;
}

file = fopen(argv[2], "w");
if(!file){
    fprintf(stderr, "Nem lehet megnyitni a fajlt\n");
    return 4;
}

for(int i = 0; i< n; i++){
    fprintf(file, "%s (%s): %d\n", airports[i].name, airports[i].city, airports[i].time);
}

fclose(file);

    return EXIT_SUCCESS;
}