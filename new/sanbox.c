#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[31];
    char world[31];
    int height;
    int time;
} ROLLER_COASTER;

int cmp(const void *a, const void *b){
    ROLLER_COASTER *left = (ROLLER_COASTER *) a;
    ROLLER_COASTER *right = (ROLLER_COASTER *) b;

    if(left->time != right->time){
        return (left->time - right->time);
    }

    if(left->height != right->height){
        return -(left->height - right->height);
    }

    return strcmp(left->name, right->name);

}


int main(int argc, char *argv[]){
    char line[101];
    int length = atoi(gets(line));
    ROLLER_COASTER coasters[length];

    if(argc == 1){
        fprintf(stderr, "Nincs input fajl\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if(!file){
        fprintf(stderr, "Nem lehet megnyitni a fajlt\n");
        return 2;
    }

    for(int i = 0; i < length; i++){
        gets(line);
        strcpy(coasters[i].name, strtok(line, ";"));
        strcpy(coasters[i].world, strtok(line, NULL));
        coasters[i].height = atoi(strtok(line,NULL));
        coasters[i].time = atoi(strtok(line,NULL));
    }

    fclose(file);

    qsort(coasters, length, sizeof(ROLLER_COASTER), cmp);

    if(argc == 2){
        fprintf(stderr, "Nincs output fajl\n");
        return 3;
    }

    file = fopen(argv[2], "w");

    for(int i = 0; i < length; i++){
        fprintf(file, "%s;%s;%d;%d\n", coasters[i].name, coasters[i].world, coasters[i].height, coasters[i].time);
    }

    fclose(file);
    
    return EXIT_SUCCESS;
}