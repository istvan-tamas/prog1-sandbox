#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[30];
    char world[30];
    int height;
    int time;
} ROLLER_COASTER;

int cmp_rc(const void *a, const void *b){
    ROLLER_COASTER *left = (ROLLER_COASTER *) a;
    ROLLER_COASTER *right = (ROLLER_COASTER *) b;

    if(left->time != right->time){
        return - (right->time - left->time);
    }

    if(left->time != right->time){
        return - (right->time - left->time);
    }

    return strcmp(left->name,right->name);

}

int main(){

    char line[101];
    ROLLER_COASTER rc[20];
    int length = 0;
    while(1) {
        gets(line);
        if(strcmp(line, "END") == 0) {
            break;
        }
        strcpy(rc[length].name,strtok(line,";"));
        strcpy(rc[length].world,strtok(NULL,";"));
        rc[length].height = atoi(strtok(NULL,";"));
        rc[length].time = atoi(strtok(NULL,";"));
        length++;
    }

    qsort(rc,length,sizeof(ROLLER_COASTER),cmp_rc);

    for(int i = 0; i < length; i++){
        printf("%s (%s): %d\n", rc[i].name, rc[i].world, rc[i].time);
    }

    return 0;
}
