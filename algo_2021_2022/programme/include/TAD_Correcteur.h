/**
 * \file TAD_Correcteur.h
 * \brief Implantation du TAD CO_CorrecteurOrthographique pour itispell
 * \author Groupe 2-3
 * \version 1.0
 * \date 03/01/2022
 *
 */

#ifndef  __TAD_CORRECTEUR__
#define  __TAD_CORRECTEUR__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "TAD_Mot.h"
#include "TAD_Dictionnaire.h"
#include "TAD_Correcteur.h"
#include <stdbool.h>
#include <errno.h>

/**
 * \brief Le type CO_CorrecteurOrthographique permet de représenter le correcteur orthographique sous la forme d'un dictionnaire et d'une liste chaînée de corrections.
 *
 */

typedef struct {
    DICO_Dictionnaire dictionnaire;
    LC_ListeChainee corrections;
} CO_CorrecteurOrthographique;

/**
 * \fn CO_CorrecteurOrthographique CO_creerCorrecteur(DICO_Dictionnaire d)
 * \brief Fonction qui crée un correcteur orthographique à partir d'un dictionnaire
 *
 * \param d : le dictionnaire
 * \return CO_CorrecteurOrthographique
 */
CO_CorrecteurOrthographique CO_creerCorrecteur(DICO_Dictionnaire d);

/**
 * \fn void* CO_copierElement(void *mot)
 * \brief Fonction qui copie le mot d'un correcteur orthographique
 *
 * \param mot : le mot
 * \return void*
 */
void* CO_copierElement(void *mot);

/**
 * \fn bool CO_comparerElement(void* mot1, void* mot2)
 * \brief Fonction qui compare deux mots
 *
 * \param mot1 : le premier mot
 * \param mot2 : le deuxième mot
 * \return bool
 */
bool CO_comparerElement(void* mot1, void* mot2);

/**
 * \fn DICO_Dictionnaire CO_obtenirDictionnaire(CO_CorrecteurOrthographique c)
 * \brief Fonction qui renvoie le dictionnaire du correcteur orthographique
 *
 * \param c : le correcteur orthographique
 * \return DICO_Dictionnaire
 */
DICO_Dictionnaire CO_obtenirDictionnaire(CO_CorrecteurOrthographique c);

/**
 * \fn LC_ListeChainee CO_obtenirCorrections(CO_CorrecteurOrthographique c)
 * \brief Fonction qui renvoie les corrections du correcteur orthographique
 *
 * \param c : le correcteur orthographique
 * \return LC_ListeChainee
 */
LC_ListeChainee CO_obtenirCorrections(CO_CorrecteurOrthographique c);

/**
 * \fn void CO_fixerCorrections(CO_CorrecteurOrthographique c, LC_ListeChainee corrections)
 * \brief Procédure qui fixe les corrections du correcteur orthographique
 *
 * \param c : le correcteur orthographique
 * \param corrections : les corrections
 */
void CO_fixerCorrections(CO_CorrecteurOrthographique c, LC_ListeChainee corrections);

/**
 * \fn bool CO_estPresentDansDictionnaire(MOT_Mot mot, CO_CorrecteurOrthographique c)
 * \brief Fonction qui détermine si un mot est présent dans le dictionnaire du correcteur orthographique
 *
 * \param mot : le mot
 * \param c : le correcteur orthographique
 * \return bool
 */
bool CO_estPresentDansDictionnaire(MOT_Mot mot, CO_CorrecteurOrthographique c);

/**
 * \fn void CO_ajouterCorrection(CO_CorrecteurOrthographique c, MOT_Mot mot)
 * \brief Fonction qui détermine si un mot est présent dans le dictionnaire du correcteur orthographique
 *
 * \param mot : le mot
 * \param c : le correcteur orthographique
 * \return bool
 */
void CO_ajouterCorrection(CO_CorrecteurOrthographique c, MOT_Mot mot);

/**
 * \fn void CO_correctionParInversion(MOT_Mot mot, CO_CorrecteurOrthographique c);
 * \brief Fonction qui ajoute les corrections par inversion possibles d'un mot dans le correcteur orthographique
 * \attention précondition : MOT_longueur(mot)>=2
 *
 * \param mot : le mot
 * \param c : le correcteur orthographique
 */
void CO_correctionParInversion(MOT_Mot mot, CO_CorrecteurOrthographique c);

/**
 * \fn void CO_correctionParInsertion(MOT_Mot mot, CO_CorrecteurOrthographique c)
 * \brief Fonction qui ajoute les corrections par insertion possibles d'un mot dans le correcteur orthographique
 *
 * \param mot : le mot
 * \param c : le correcteur orthographique
 */
void CO_correctionParInsertion(MOT_Mot mot, CO_CorrecteurOrthographique c);

/**
 * \fn void CO_correctionParDecomposition(MOT_Mot mot, CO_CorrecteurOrthographique c)
 * \brief Fonction qui ajoute les corrections par décomposition possibles d'un mot dans le correcteur orthographique
 * \attention précondition : MOT_longueur(mot)>=2
 *
 * \param mot : le mot
 * \param c : le correcteur orthographique
 */
void CO_correctionParDecomposition(MOT_Mot mot, CO_CorrecteurOrthographique c);

/**
 * \fn void CO_correctionParSuppression(MOT_Mot mot, CO_CorrecteurOrthographique c)
 * \brief Fonction qui ajoute les corrections par suppression possibles d'un mot dans le correcteur orthographique
 * \attention précondition : MOT_longueur(mot)>=2
 *
 * \param mot : le mot
 * \param c : le correcteur orthographique
 */
void CO_correctionParSuppression(MOT_Mot mot, CO_CorrecteurOrthographique c);

/**
 * \fn void CO_correctionParRemplacement(MOT_Mot mot, CO_CorrecteurOrthographique c)
 * \brief Fonction qui ajoute les corrections par remplacement possibles d'un mot dans le correcteur orthographique
 * \attention précondition : MOT_longueur(mot)>=2
 *
 * \param mot : le mot
 * \param c : le correcteur orthographique
 */
void CO_correctionParRemplacement(MOT_Mot mot, CO_CorrecteurOrthographique c);

#endif