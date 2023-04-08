#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include "fonctionsSurElement.h"
#include "listeChainee.h"

#define VRAI 1
#define FAUX 0

LC_ListeChainee LC_listeChainee(){
  errno = 0;
  return NULL;
}

int LC_estVide(LC_ListeChainee liste){
  errno=0;
  return (liste==NULL);
}

void LC_ajouter(LC_ListeChainee *pl,void* source, FSE_copierDansSDD copierElement){
  LC_ListeChainee pNoeud = (LC_ListeChainee)malloc(sizeof(LC_Noeud));
  void *donnee = copierElement(source);
  if ((pNoeud!=NULL)&&(donnee!=NULL)){
    errno = 0;
    pNoeud->element = donnee;
    pNoeud->listeSuivante = *pl;
    *pl = pNoeud;
  } else {
    errno = LC_ERREUR_MEMOIRE;
  }
}

void* LC_obtenirElement(LC_ListeChainee liste){
  assert(!LC_estVide(liste));
  errno=0;
  return liste->element;
}

LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee liste){
  assert(!LC_estVide(liste));
  errno=0;
  return liste->listeSuivante;
}

void LC_fixerListeSuivante(LC_ListeChainee *liste, LC_ListeChainee suivant){
  assert (!LC_estVide(*liste));
  errno=0;
  (*liste)->listeSuivante=suivant;
}

void LC_fixerElement(LC_ListeChainee *liste, void *element, FSE_copierDansSDD copierElement, FSE_libererDansSDD libererElement){
  assert(!LC_estVide(*liste));
  errno=0;
  void *donnee = copierElement(element);
  libererElement((*liste)->element);
  (*liste)->element = donnee;
}

void LC_supprimerTete(LC_ListeChainee *liste, FSE_libererDansSDD libererFonction){
  LC_ListeChainee temp;
  assert(!LC_estVide(*liste));
  errno = 0;
  temp = *liste;
  (*liste)=LC_obtenirListeSuivante(*liste);
  libererFonction(LC_obtenirElement(temp));
  free(temp);
}

void LC_supprimer(LC_ListeChainee *liste, FSE_libererDansSDD libererFonction){
  errno = 0;
  if (!LC_estVide(*liste)){
    LC_supprimerTete(liste, libererFonction);
    LC_supprimer(liste, libererFonction);
  }
}

LC_ListeChainee LC_copier(LC_ListeChainee liste, FSE_copierDansSDD copierElement){
  LC_ListeChainee temp;
  errno = 0;
  if (LC_estVide(liste))
    return LC_listeChainee();
  else {
    temp = LC_copier(LC_obtenirListeSuivante(liste), copierElement);
    LC_ajouter(&temp, LC_obtenirElement(liste), copierElement);
    return temp;
  }
}

int LC_egales(LC_ListeChainee liste1, LC_ListeChainee liste2, FSE_comparerElementSDD comparerElements){
  errno = 0;
  if (LC_estVide(liste1) && LC_estVide(liste2)){
    return VRAI;
  } else if (LC_estVide(liste1) || LC_estVide(liste2)){
    return FAUX;
  } else if (comparerElements(LC_obtenirElement(liste1),LC_obtenirElement(liste2))!=0){
    return FAUX;
  } else {
		return LC_egales(LC_obtenirListeSuivante(liste1), LC_obtenirListeSuivante(liste2), comparerElements);
	}
}
