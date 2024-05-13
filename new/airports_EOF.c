#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    char city[31];
    int runways;
    int time;

}AIRPORT;

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

    AIRPORT airports[20];
    char line[101];
    int length = 0;

    if(argc == 1){
        fprintf(stderr, "Nincsen input megadva!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if(!file){
        fprintf(stderr, "Nem lehet megnyitni a bemeneti fajlt!\n");
        return 2;
    }

    while(fgets(line, sizeof(line), file)){
        line[strlen(line)-1] = '\0';
        strcpy(airports[length].name, strtok(line, ";"));
        strcpy(airports[length].city, strtok(NULL, ";"));
        airports[length].runways = atoi(strtok(NULL, ";"));
        airports[length].time = atoi(strtok(NULL, ";"));
        length++;
    }

    fclose(file);

    qsort(airports, length, sizeof(AIRPORT), cmp);
    
    if(argc == 2){
        fprintf(stderr, "Nincsen output megadva!\n");
        return 3;
    }

    file = fopen(argv[2], "w");

    if(!file){
        fprintf(stderr, "Nem lehet megnyitni a kimeneti fajlt!\n");
        return 4;
    }

    for(int i = 0; i< length; i++){
        fprintf(file, "%s (%s): %d\n", airports[i].name, airports[i].city, airports[i].time);
    }

    fclose(file);

    return EXIT_SUCCESS;
}