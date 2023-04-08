#include <stdlib.h>
#include <stdio.h>
#include "aide.h"

void aide(){
    printf("Aide de asispell :\n");
    printf("asispell -h : cette aide\n");
    printf("asispell -d dico : correction de l'entree standard a l'aide du dictionnaire dico\n");
    printf("asispell -d dico -f fic : completer le dictionnaire dico a l'aide des mots du fichier fic (un mot par ligne)");
}
