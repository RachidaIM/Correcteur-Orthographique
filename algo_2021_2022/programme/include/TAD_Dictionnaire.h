/**
 * \file TAD_Dictionnaire.h
 * \brief Implantation du TAD DICO_Dictionnaire pour itispell
 * \author Groupe 2-3
 * \version 1.0
 * \date 3/01/2022
 *
 */

#ifndef __TAD_DICTIONNAIRE__
#define __TAD_DICTIONNAIRE__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "TAD_Mot.h"
#include "listeChainee.h"
#include "elementsArbreNaire.h"

/**
 * \brief Le type DICO_Dictionnaire permet de représenter le dictionnaire sous la forme d'un arbre n-aire.
 *
 */

typedef EAN_Element DICO_Dictionnaire;

/**
 * \fn void DICO_fixerBooleen(EAN_Element arbre, bool Booleen)
 * \brief Procédure qui fixe le booléen qui vérifie s'il s'agit d'une fin de mot ou non dans le dictionnaire
 *
 * \param arbre : l'arbre représentant le dictionnaire
 * \param Booleen : le booleen
 */
void DICO_fixerBooleen(EAN_Element arbre, bool Booleen);

/**
 * \fn void DICO_fixerCaractere(EAN_Element arbre, char c)
 * \brief Procédure qui fixe le caractère du dictionnaire
 *
 * \param arbre : l'arbre représentant le dictionnaire
 * \param c : le caractère
 */
void DICO_fixerCaractere(EAN_Element arbre, char c);

/**
 * \fn void DICO_fixerNbFils(EAN_Element arbre, int NbFils)
 * \brief Procédure qui fixe le nombre de fils du dictionnaire
 *
 * \param arbre : l'arbre représentant le dictionnaire
 * \param NbFils : le nombre de fils
 */
void DICO_fixerNbFils(EAN_Element arbre, int NbFils);

/**
 * \fn void DICO_fixerFils(EAN_Element a, EAN_Element b)
 * \brief Procédure qui fixe le fils du dictionnaire
 *
 * \param a : l'arbre représentant le dictionnaire
 * \param b : le fils
 */
void DICO_fixerFils(EAN_Element a, EAN_Element b);

/**
 * \fn bool DICO_obtenirBooleen(EAN_Element arbre)
 * \brief Fonction qui renvoie le booléen du dictionnaire
 *
 * \param arbre : l'arbre représentant le dictionnaire
 * \return bool
 */
bool DICO_obtenirBooleen(EAN_Element arbre);

/**
 * \fn char DICO_obtenirCaractere(EAN_Element arbre)
 * \brief Fonction qui renvoie le caractère du dictionnaire
 *
 * \param arbre : l'arbre représentant le dictionnaire
 * \return char
 */
char DICO_obtenirCaractere(EAN_Element arbre);

/**
 * \fn int DICO_obtenirNbFils(EAN_Element arbre)
 * \brief Fonction qui renvoie le nombre de fils du dictionnaire
 *
 * \param arbre : l'arbre représentant le dictionnaire
 * \return int
 */
int DICO_obtenirNbFils(EAN_Element arbre); 

/**
 * \fn EAN_Element DICO_obtenirArbre(DICO_Dictionnaire d)
 * \brief Fonction qui renvoie l'arbre du dictionnaire
 *
 * \param d : le dictionnaire
 * \return EAN_Element
 */
EAN_Element DICO_obtenirArbre(DICO_Dictionnaire d);

/**
 * \fn LC_ListeChainee DICO_obtenirFils(EAN_Element arbre)
 * \brief Fonction qui renvoie le fils du dictionnaire
 *
 * \param a : l'arbre représentant le dictionnaire
 * \return LC_ListeChainee
 */
LC_ListeChainee DICO_obtenirFils(EAN_Element arbre);

/**
 * \fn EAN_Element DICO_arbreNAire()
 * \brief Fonction qui renvoie un arbre n-aire vide
 *
 * \return EAN_Element
 */
EAN_Element DICO_arbreNAire();

/**
 * \fn DICO_Dictionnaire DICO_dictionnaire()
 * \brief Fonction qui renvoie un dictionnaire vide
 *
 * \return DICO_Dictionnaire
 */
DICO_Dictionnaire DICO_dictionnaire();

/**
 * \fn bool DICO_estVide(DICO_Dictionnaire d)
 * \brief Fonction qui permet de savoir si un dictionnaire est vide
 *
 * \param d : le dictionnaire
 * \return bool
 */
bool DICO_estVide(DICO_Dictionnaire d);

/**
 * \fn bool DICO_estPresent(DICO_Dictionnaire d, MOT_Mot m)
 * \brief Fonction qui permet de savoir si un mot est présent dans le dictionnaire
 * \attention précondition : non DICO_estVide(d)
 *
 * \param d : le dictionnaire
 * \param m : le mot
 * \return bool
 */
bool DICO_estPresent(DICO_Dictionnaire d, MOT_Mot m); /*assertion : non estVide(d) */

/**
 * \fn void DICO_ajoutMot(DICO_Dictionnaire d, MOT_Mot m)
 * \brief Procédure qui permet d'ajouter un mot dans le dictionnaire
 *
 * \param d : le dictionnaire
 * \param m : le mot
 */
void DICO_ajoutMot(DICO_Dictionnaire d, MOT_Mot m);

/**
 * \fn void DICO_dictionnaireEnFichier(FILE* fdico, DICO_Dictionnaire d)
 * \brief Procédure qui permet de transformer un dictionnaire en fichier
 * \attention précondition : estOuvert(fdico)
 *
 * \param fdico : le fichier
 * \param d : le dictionnaire
 */
void DICO_dictionnaireEnFichier(FILE* fdico, DICO_Dictionnaire d);

/**
 * \fn void DICO_fichierEnDictionnaire(DICO_Dictionnaire d, FILE* fdico)
 * \brief Procédure qui permet de transformer un fichier en dictionnaire
 * \attention précondition : estOuvert(fdico)
 *
 * \param d : le dictionnaire
 * \param fdico : le fichier
 */
void DICO_fichierEnDictionnaire(DICO_Dictionnaire d, FILE* fdico);

#endif