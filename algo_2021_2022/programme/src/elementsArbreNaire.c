#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "elementsArbreNaire.h"
#include "TAD_Dictionnaire.h"

void* EAN_copierElement(void* e){
  EAN_Element *resultat = (EAN_Element*)malloc(sizeof(EAN_Noeud));
  memcpy((void*)resultat,e, sizeof(EAN_Element));
  return (void*)resultat;
}

int EAN_comparerElement(void* e1, void* e2){
  bool vrai = false; 
  vrai = (((EAN_Element)e1)->estFinDeMot == ((EAN_Element)e2)->estFinDeMot) && (((EAN_Element)e1)->caractere == ((EAN_Element)e2)->caractere) && (((EAN_Element)e1)->nbFils == ((EAN_Element)e2)->nbFils);
  if ((((EAN_Element)e1)->nbFils==0) || (((EAN_Element)e2)->nbFils==0)){
    return vrai;
  } else {
    return LC_egales(((EAN_Element)e1)->fils, ((EAN_Element)e2)-> fils, EAN_comparerElement);
  }
}
