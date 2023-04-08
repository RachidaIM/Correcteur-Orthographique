#ifndef __ELEMENTS_ARBRE_NAIRE__
#define __ELEMENTS_ARBRE_NAIRE__
#include "listeChainee.h"
#include "fonctionsSurElement.h"
#include <stdbool.h>

typedef struct{
  bool estFinDeMot; 
  char caractere;
  int nbFils;
  LC_ListeChainee fils;
} EAN_Noeud;

typedef EAN_Noeud *EAN_Element;

void* EAN_copierElement(void*);
int EAN_comparerElement(void*, void*);
#endif
