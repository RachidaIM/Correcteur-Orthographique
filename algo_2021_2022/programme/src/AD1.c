#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "AD1.h"
#include "TAD_Mot.h"
#include "TAD_Dictionnaire.h"
#include "TAD_Correcteur.h"
#include "elementsArbreNaire.h"

void corrigerTexte(char *phraseACorriger, FILE* fdico){
  DICO_Dictionnaire dico = DICO_dictionnaire();
    LC_ListeChainee motsACorriger, corrections;
    int nbMots = 0;
    MOT_Mot *motCourant;
    DICO_fichierEnDictionnaire(dico, fdico);
    motsACorriger = decouperTexteEnMots(phraseACorriger,&nbMots);
    for (int i = 1; i<nbMots ;i++){
        motCourant = (MOT_Mot*)LC_obtenirElement(motsACorriger);
        if (estCorrect(dico, *motCourant)){
	    printf("* /n");
	}else {
	    corrections = traiterMot(dico, *motCourant);
	    afficherCorrections(corrections, *motCourant);
	}
        printf("\n");
        motsACorriger = LC_obtenirListeSuivante(motsACorriger);
    }
}

LC_ListeChainee decouperTexteEnMots(char *phraseACorriger, int *nbMots){
  LC_ListeChainee mots= LC_listeChainee();
  MOT_Mot testMot;
  char *phraseCoupee=strtok(phraseACorriger, " ");
  while (phraseCoupee!=NULL){
        testMot = MOT_creerMot(phraseCoupee);
        phraseCoupee = strtok(NULL, " ");
        LC_ajouter(&mots, &testMot, CO_copierElement);
        nbMots++;
  }
  return mots;
}

LC_ListeChainee traiterMot(DICO_Dictionnaire dico, MOT_Mot mot){
    CO_CorrecteurOrthographique corr;
    corr = CO_creerCorrecteur(dico);
    proposerCorrections(corr, mot);
    return corr.corrections;
}

void afficherCorrections(LC_ListeChainee corrections, MOT_Mot motACorriger){
    MOT_Mot *motCourant;
    printf("& %s", MOT_obtenirData(motACorriger));
    while (!LC_estVide(corrections)){
        motCourant = (MOT_Mot*)LC_obtenirElement(corrections);
        printf("%s ", MOT_obtenirData(*motCourant));
        corrections = LC_obtenirListeSuivante(corrections);
    }
}

bool estCorrect(DICO_Dictionnaire dico, MOT_Mot motAVerifier){
    return DICO_estPresent(dico, motAVerifier);
}

void proposerCorrections(CO_CorrecteurOrthographique corr, MOT_Mot motACorriger){
    CO_correctionParInsertion(motACorriger, corr);
    CO_correctionParRemplacement(motACorriger, corr);
    CO_correctionParInsertion(motACorriger, corr);
    CO_correctionParDecomposition(motACorriger, corr);
    CO_correctionParSuppression(motACorriger, corr);
}
