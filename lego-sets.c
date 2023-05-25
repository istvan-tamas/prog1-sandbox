#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char code[5];
    char name[50];
    char theme[30];
    int bricks;

}LEGO_SET;

int cmp(const void *a, const void *b) {
    LEGO_SET *left = (LEGO_SET *) a;
    LEGO_SET *right = (LEGO_SET *) b;

    if(left->bricks != right->bricks) {
        return - (left->bricks - right->bricks);
    }
    if(strcmp(left->theme, right->theme)){
        return strcmp(left->theme, right->theme);
    }
    if(strcmp(left->name, right->name)){
        return strcmp(left->name, right->name);
    }
    if(strcmp(left->code, right->code)){
        return strcmp(left->code, right->code);
    }
}

int main() {

    char line[201];

    int n = atoi(gets(line));
    LEGO_SET lego_sets[n];


    for(int i = 0; i < n; i++){
        gets(line);
        char *code = strtok(line, ";");
        char *name = strtok(NULL, ";");
        char *theme = strtok(NULL, ";");
        char *bricks = strtok(NULL, ";");

        strcpy(lego_sets[i].code, code);
        strcpy(lego_sets[i].name, name);
        strcpy(lego_sets[i].theme, theme);
        lego_sets[i].bricks = atoi(bricks);

}
    qsort(lego_sets, n, sizeof(LEGO_SET), cmp);

    for(int i=0; i<n; i++) {
        printf("%s (%s): %d\n", lego_sets[i].name,
            lego_sets[i].theme, lego_sets[i].bricks);
    }

    return EXIT_SUCCESS;
}
