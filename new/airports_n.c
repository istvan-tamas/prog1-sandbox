#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    
    char name[31];
    char city[31];
    int runways;
    int time;

}AIRPORT;

<<<<<<< HEAD
int cmp(const void *a, const void*b){

    AIRPORT *left = (AIRPORT *) a;
    AIRPORT *right = (AIRPORT *) b;

    if(left->runways != right->runways){
        return -(left->runways - right->runways);
=======
int cmp(const void *a, const void *b){
    AIRPORT *ap1 = (AIRPORT*)a;
    AIRPORT *ap2 = (AIRPORT*)b;
    if(ap1->runways != ap2->runways){
        return -(ap2->runways - ap1->runways);
>>>>>>> 90c0c1ee1aa070f291bd08bc1cf27a08d7edf6bc
    }
    if(ap1->time != ap2->time){
        return -(ap1->time - ap2->time);
    }

    return strcmp(ap1->name, ap2->name);
}

int main(int argc, char *argv[]){
<<<<<<< HEAD

    char line[101];
    
    if(argc == 1){
        fprintf(stderr, "Nincsen input megadva!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if(!file){
        fprintf(stderr, "Nem lehet megnyitni a bemeneti fajlt!\n");
        return 2;
    }

    int n = atoi(fgets(line, sizeof(line), file));
    AIRPORT airports[n];
=======
    if(argc == 1){
        fprintf(stderr, "Nincsen input file megadva!\n");
        return 1;
    }

        FILE *file = fopen(argv[1], "r");  
    if(!file){
        fprintf(stderr, "Nem sikerult megnyitni a fajlt!\n");
        return 2;
    }

    char line[101];
    int n = atoi(fgets(line, sizeof(line), file));
    AIRPORT ap[n];
>>>>>>> 90c0c1ee1aa070f291bd08bc1cf27a08d7edf6bc

    for(int i = 0; i < n; i++){
        fgets(line, sizeof(line), file);
        line[strlen(line)-1] = '\0';
        strcpy(ap[i].name, strtok(line, ";"));
        strcpy(ap[i].city, strtok(NULL, ";"));
        ap[i].runways = atoi(strtok(NULL, ";"));
        ap[i].time = atoi(strtok(NULL, ";"));
    }
<<<<<<< HEAD

    fclose(file);

    qsort(airports, n, sizeof(AIRPORT), cmp);
    
    if(argc == 2){
        fprintf(stderr, "Nincsen output megadva!\n");
        return 3;   
    }

    file = fopen(argv[2], "w");

    if(!file){
        fprintf(stderr, "Nem lehet megnyitni a kimeneti fajlt!\n");
        return 4;
    }

    for(int i = 0; i < n; i++){
        fprintf(file, "%s;%s;%d;%d\n", airports[i].name, airports[i].city,airports[i].runways, airports[i].time);
    }

    fclose(file);
=======
    
    fclose(file);
    qsort(ap, n, sizeof(AIRPORT), cmp);
>>>>>>> 90c0c1ee1aa070f291bd08bc1cf27a08d7edf6bc

    file = fopen(argv[2], "w");
    if(!file) {
        fprintf(stderr, "Nem nyithato meg az output\n");
        return 4;
    }
    
    for(int i = 0; i < n; i++){
        fprintf(file, "%s;%s;%d;%d\n", ap[i].name, ap[i].city, ap[i].runways, ap[i].time);
    }
    fclose(file);
    return EXIT_SUCCESS;
}
