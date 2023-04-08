#include <stdlib.h>
#include <stdio.h>
#include "TAD_Mot.h"
#include "completerDico.h"
#include "TAD_Dictionnaire.h"

void completerDico(FILE* ficEntree, FILE* ficSortie){
    MOT_Mot mot;
    char *s = " ";
    DICO_Dictionnaire d = DICO_dictionnaire();
    DICO_fichierEnDictionnaire(d,ficSortie);
    while (fgetc(ficEntree) != EOF) {
        fgets(s, 26, ficEntree);
        mot = MOT_creerMot(s);
        DICO_ajoutMot(d, mot);
    }
    DICO_dictionnaireEnFichier(ficSortie,d);
}
