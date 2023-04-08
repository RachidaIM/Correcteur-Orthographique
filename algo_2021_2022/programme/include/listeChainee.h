#ifndef __LISTE_CHAINEE__
#define __LISTE_CHAINEE__
#include <errno.h>
#include "fonctionsSurElement.h"

typedef struct LC_Noeud *LC_ListeChainee;

typedef struct LC_Noeud{
  void* element;
  LC_ListeChainee listeSuivante;
} LC_Noeud;

#define LC_ERREUR_MEMOIRE 1


LC_ListeChainee LC_listeChainee();

int LC_estVide(LC_ListeChainee liste);

void LC_ajouter(LC_ListeChainee *liste, void* element, FSE_copierDansSDD);

void* LC_obtenirElement(LC_ListeChainee liste);

LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee liste);


void LC_fixerListeSuivante(LC_ListeChainee *liste, LC_ListeChainee suivant);


void LC_fixerElement(LC_ListeChainee *liste, void *element, FSE_copierDansSDD, FSE_libererDansSDD);


void LC_supprimerTete(LC_ListeChainee *liste, FSE_libererDansSDD);


void LC_supprimer(LC_ListeChainee *liste, FSE_libererDansSDD);


LC_ListeChainee LC_copier(LC_ListeChainee liste, FSE_copierDansSDD);


int LC_egales(LC_ListeChainee liste1, LC_ListeChainee liste2, FSE_comparerElementSDD);

#endif
