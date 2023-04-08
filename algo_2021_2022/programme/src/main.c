#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "AD1.h"
#include "completerDico.h"
#include "aide.h"

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF){
        c = getchar();
    }
}
 
int lire(char *chaine, int longueur){
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL){
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL){
            *positionEntree = '\0';
        } else {
            viderBuffer();
        }
        return 1;
    } else {
        viderBuffer();
        return 0;
    }
}

int main(int argc, char *argv[]){
    if (strcmp(argv[1],"-d") == 0){
        if (strcmp(argv[3],"-f") == 0){
            FILE* f1 = NULL;
            FILE* f2 = NULL;
            f1 = fopen(argv[2],"r+");
            f2 = fopen(argv[4],"r+");
            completerDico(f1,f2);
            fclose(f1);
            fclose(f2);
        } else if (strcmp(argv[3],"") == 0){
            char saisie[120]; // la phrase de l'utilisateur ne prend que 120 caracteres maximum (choisie arbitrairement)
            lire(saisie,120);
            FILE* f = NULL;
            f = fopen(argv[2],"r+");
            corrigerTexte(saisie,f);
            fclose(f);
        }
    } else {
        aide();
    }
}