#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[5];
    char name[50];
    char theme[30];
    int bricks;

}LEGO_SET;

int cmp(const void *a, const void *b){
    LEGO_SET *left = (LEGO_SET *) a;
    LEGO_SET *right = (LEGO_SET *) b;

    if(left->bricks != right->bricks){
        return -(left->bricks - right->bricks);
    }

    return strcmp(left->theme, right->theme);

    return strcmp(left->name, right->name);

    return strcmp(left->code, right->code);

}

int main(int argc, char *argv[]){
    
    LEGO_SET legos[20];
    char line[102];
    int length = 0;

    if(argc == 1){
        fprintf(stderr, "Nincs bemenet!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file){
        fprintf(stderr, "Nem sikerult megnyitni a fajlt!\n");
        return 2;
    }

    while(1){
        fgets(line, sizeof(line), file);
        line[sizeof(line)-1] = '\0';
        if(strcmp("END",line) == 0){
            break;
        }else{
            strcpy(legos[length].code, strtok(line, ";"));
            strcpy(legos[length].name, strtok(NULL, ";"));
            strcpy(legos[length].theme, strtok(NULL, ";"));
            legos[length].bricks = atoi(strtok(NULL, ";"));
            length++;
        }
    }

    fclose(file);

    qsort(legos, length, sizeof(LEGO_SET), cmp);

    if(argc == 2){
        fprintf(stderr, "Nincs kimeneti fajl!\n");
        return 3;
    }

    file = fopen(argv[2],"w");

    if(!file){
        fprintf(stderr, "Nem sikerult megnyitni a fajlt!\n");
        return 3;
    }

    for(int i = 0; i < length; i++){
        fprintf(file, "%d;%s;%s;%d\n", atoi(legos[i].code), legos[i].name, legos[i].theme, legos[i].bricks);
    }

    fclose(file);

    return EXIT_SUCCESS;
}