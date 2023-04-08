/**
 * \file AD1.h
 * \brief Implantation des fonctions issues de l'analyse descendante pour itispell
 * \author Groupe 2-3
 * \version 1.0
 * \date 3/01/2022
 *
 */

#ifndef __AD1__
#define __AD1__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "TAD_Mot.h"
#include "TAD_Dictionnaire.h"
#include "TAD_Correcteur.h"

/**
 * \fn void corrigerTexte(char *phraseACorriger, FILE* fdico)
 * \brief Procédure qui corrige la chaîne de caractère entrée par rapport à un dictionnaire donné
 *
 * \param phraseACorriger : la chaine de caractère à corriger
 * \param fdico : le pointeur sur le fichier du dictionnaire
 */
void corrigerTexte(char *phraseACorriger, FILE* fdico);

/**
 * \fn LC_ListeChainee decouperTexteEnMots(char *phraseACorriger, int *nbMots)
 * \brief Fonction qui découpe une chaîne de caractères en différents mots et les stocke dans une liste chaînée
 *
 * \param phraseACorriger : la chaine de caractère à corriger
 * \param nbMots : pointeur sur le nom
 * \return LC_ListeChainee
 */
LC_ListeChainee decouperTexteEnMots(char *phraseACorriger, int *nbMots);

/**
 * \fn LC_ListeChainee traiterMot(DICO_Dictionnaire dico, MOT_Mot mot)
 * \brief Fonction qui renvoie une liste chaînée de corrections pour un mot donné par rapport à un dictionnaire donné (si le mot est juste, la liste renvoyée est vide)
 *
 * \param dico : le dictionnaire
 * \param mot : le mot
 * \return LC_ListeChainee
 */
LC_ListeChainee traiterMot(DICO_Dictionnaire dico, MOT_Mot mot);

/**
 * \fn void afficherCorrections(LC_ListeChainee corrections, MOT_Mot motACorriger)
 * \brief Procédure qui affiche les corrections pour un mot donné
 *
 * \param corrections : les corrections à afficher
 * \param motACorriger : le mot
 */
void afficherCorrections(LC_ListeChainee corrections, MOT_Mot motACorriger);

/**
 * \fn bool estCorrect(DICO_Dictionnaire dico, MOT_Mot motAVerifier)
 * \brief Fonction qui vérifie si un mot est correct ou non par rapport à un dictionnaire donné
 *
 * \param dico : le dictionnaire
 * \param motAVerifier : le mot
 * \return bool
 */
bool estCorrect(DICO_Dictionnaire dico, MOT_Mot motAVerifier);

/**
 * \fn void proposerCorrections(CO_CorrecteurOrthographique corr, MOT_Mot motACorriger)
 * \brief Procédure qui propose les différentes corrections pour un mot à corriger par rapport à un correcteur orthographique
 *
 * \param corr : le correcteur orthographique
 * \param motACorriger : le mot
 */
void proposerCorrections(CO_CorrecteurOrthographique corr, MOT_Mot motACorriger);

#endif