#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "TAD_Dictionnaire.h"
#include "TAD_Mot.h"
#include "listeChainee.h"
#include "elementsArbreNaire.h"


// Setter : 
void DICO_fixerBooleen(EAN_Element arbre, bool Booleen){
    arbre->estFinDeMot = Booleen;
}
void DICO_fixerCaractere(EAN_Element arbre, char c){
    arbre->caractere = c;
}

void DICO_fixerNbFils(EAN_Element arbre, int Nb){
    arbre->nbFils = Nb;
}

void DICO_fixerFils(EAN_Element a, EAN_Element b){
  LC_ajouter(&(a->fils), b, EAN_copierElement);
}
// Fin des Setter

// Getter
bool DICO_obtenirBooleen(EAN_Element arbre){
    return arbre->estFinDeMot;
}
char DICO_obtenirCaractere(EAN_Element arbre){
    return arbre->caractere;
}

int DICO_obtenirNbFils(EAN_Element arbre){
    return arbre->nbFils;
}

EAN_Element DICO_obtenirArbre(DICO_Dictionnaire d){
    return d;
}

LC_ListeChainee DICO_obtenirFils(EAN_Element arbre){
    return arbre->fils;
}

// Fin des Getter

EAN_Element DICO_arbreNAire(){
    EAN_Element a;
    a=(EAN_Element)malloc(sizeof(EAN_Noeud));
    DICO_fixerBooleen(a, false);
    DICO_fixerCaractere(a, ' ');
    DICO_fixerNbFils(a,0); 
    a->fils = LC_listeChainee();
    return a;
}

DICO_Dictionnaire DICO_dictionnaire(){
    return DICO_arbreNAire();
}

bool DICO_estVide(DICO_Dictionnaire d){
    return (DICO_obtenirCaractere(DICO_obtenirArbre(d)) == ' ');
}

bool DICO_estPresent(DICO_Dictionnaire d, MOT_Mot m){
    bool trouve, estPresent;
    int i,j;
    LC_ListeChainee l;
    EAN_Element a;
    estPresent = false;
    trouve = true;
    i = 1;
    a = DICO_obtenirArbre(d);
    while ((!estPresent) && (i <= MOT_longueur(m) && trouve)){
        l = DICO_obtenirFils(a); // Fonction Liste Chainee
	j = 1;
        trouve = false;
        while ( !trouve && (j <= DICO_obtenirNbFils(a)) ){
            if (MOT_iemeCaractere(m,i-1) == DICO_obtenirCaractere(LC_obtenirElement(l))) {
                trouve = true;
            }
            else {
                l = LC_obtenirListeSuivante(l);
                j = j+1;
            }
        }
        if (trouve) {
	  if ((i == MOT_longueur(m)) && DICO_obtenirBooleen(LC_obtenirElement(l))){
                estPresent = true;
            }
	    a = LC_obtenirElement(l);
	    i = i+1;
	}
    }
    return estPresent;
}

void DICO_ajoutMot(DICO_Dictionnaire d, MOT_Mot m){
    bool trouve, motAjoute;
    int i,j;
    LC_ListeChainee l;
    EAN_Element temp,a;
    motAjoute = false;
    trouve = true;
    i = 1;
    a = DICO_obtenirArbre(d);
    while (!motAjoute && (i <= MOT_longueur(m))) {
        l = DICO_obtenirFils(a);
        j = 1;
        trouve = false;
        while(!trouve && (j <= DICO_obtenirNbFils(a))) {
            if (MOT_iemeCaractere(m,i) == DICO_obtenirCaractere(LC_obtenirElement(l))) {
                trouve = true;
            }
            else {
                l = LC_obtenirListeSuivante(l);
                j = j+1;
            }
        }
        if (trouve) {
            if (i == MOT_longueur(m)) {
                if (!DICO_obtenirBooleen(a)) {
                    DICO_fixerBooleen(a,true);
                }
                motAjoute = true;
            }
            a = LC_obtenirElement(l);
        }
        else {
            temp = DICO_arbreNAire();
            DICO_fixerCaractere(temp,MOT_iemeCaractere(m,i));
            if (i == MOT_longueur(m)) {
                DICO_fixerBooleen(temp, true);
                motAjoute = true;
            }
            else {
                DICO_fixerBooleen(temp, false);
            }
            DICO_fixerFils(a,temp); // fixerFils(a,temp)
            DICO_fixerNbFils(a, DICO_obtenirNbFils(a)+1);
        }
        i = i+1;
    }
}
 
void DICO_dictionnaireEnFichier(FILE* fdico, DICO_Dictionnaire d){
    EAN_Element a;
    LC_ListeChainee temp;
    a = DICO_obtenirArbre(d);
    if (!(DICO_estVide(a))) {
        fprintf(fdico,"%c",DICO_obtenirCaractere(a));
		fprintf(fdico,"%d",DICO_obtenirBooleen(a));
		fprintf(fdico,"%d",DICO_obtenirNbFils(a));
		temp = DICO_obtenirFils(a);
        for (int i=1;i<=DICO_obtenirNbFils(a);i++) {
            DICO_dictionnaireEnFichier(fdico, LC_obtenirElement(temp));
			temp = LC_obtenirListeSuivante(temp);
        }
    }
}

void DICO_fichierEnDictionnaire(DICO_Dictionnaire d, FILE* fdico){
    EAN_Element temp,a;
    bool booleen;
    char car;
    int i,nbFils;
    a = DICO_obtenirArbre(d);
    if (fgetc(fdico) != EOF) {
        car = fgetc(fdico);
		DICO_fixerCaractere(a,car);
		booleen = fgetc(fdico);
		DICO_fixerBooleen(a,booleen);
		nbFils = fgetc(fdico);
		DICO_fixerNbFils(a,nbFils);
		temp = DICO_arbreNAire(); // 
        for (i=1;i<=nbFils;i++) {
            DICO_fichierEnDictionnaire(temp, fdico);
			DICO_fixerFils(a,temp);
        }
    }
}
