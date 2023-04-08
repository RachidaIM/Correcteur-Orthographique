/**
 * \file TAD_Mot.h
 * \brief Implantation du TAD Mot pour itispell
 * \author Groupe 2-3
 * \version 1.0
 * \date 29/12/2021
 *
 */

#ifndef __TAD_MOT__
#define __TAD_MOT__
#include <stdbool.h>

/**
 * \brief Le type MOT_Mot permet de représenter un mot en stockant la chaîne de caractère du mot et sa longueur.
 *
 */

typedef struct{
    char *data;
    int longueur;
} MOT_Mot;

/**
 * \fn MOT_Mot MOT_creerMot(char *CdC)
 * \brief Fonction qui crée d'un mot à partir d'une chaîne de caractères
 * \attention précondition : MOT_estUnMot(CdC)
 *
 * \param CdC : la chaîne de caractères
 * \return MOT_Mot
 */
MOT_Mot MOT_creerMot(char *CdC);

/**
 * \fn void MOT_supprimerMot(MOT_Mot *mot)
 * \brief Fonction qui supprime un mot
 *
 * \param mot : un pointeur sur le mot à supprimer
 */
void MOT_supprimerMot(MOT_Mot *mot);

/**
 * \fn MOT_Mot MOT_copieMot(MOT_Mot mot)
 * \brief Fonction qui permet de copier un mot
 *
 * \param mot : le mot à copier
 * \return MOT_Mot
 */
MOT_Mot MOT_copieMot(MOT_Mot mot);

/**
 * \fn char *MOT_obtenirData(MOT_Mot mot)
 * \brief Fonction qui permet d'obtenir la chaîne de caractère d'un mot
 *
 * \param mot : le mot
 * \return char *
 */
char *MOT_obtenirData(MOT_Mot mot);

/**
 * \fn void MOT_fixeData(MOT_Mot *mot, char *CdC)
 * \brief Procédure qui fixe la chaîne de caractère d'un mot
 *
 * \param mot : un pointeur sur le mot
 * \param CdC : la chaîne de caractère
 */
void MOT_fixeData(MOT_Mot *mot, char *CdC);

/**
 * \fn int MOT_longueur(MOT_Mot mot)
 * \brief Fonction qui renvoie la longueur d'un mot
 *
 * \param mot : le mot
 * \return int
 */
int MOT_longueur(MOT_Mot mot);

/**
 * \fn void MOT_fixeLongueur(MOT_Mot *mot, int l)
 * \brief Procédure qui fixe la longueur d'un mot
 *
 * \param mot : un pointeur sur le mot
 * \param l : la longueur
 */
void MOT_fixeLongueur(MOT_Mot *mot, int l);

/**
 * \fn MOT_estUnMot(char *CdC)
 * \brief Fonction qui permet de savoir si une chaîne de caractère vérifie les caractéristiques d'un mot ou non
 *
 * \param CdC : la chaîne de caractères
 * \return bool
 */
bool MOT_estUnMot(char *CdC);

/**
 * \fn char MOT_iemeCaractere(MOT_Mot mot, int i)
 * \brief Fonction qui renvoie le ième caractère d'un mot
 * \attention précondition : i <= MOT_longueur(mot)
 *
 * \param mot : le mot
 * \param i : le numéro du caractère voulu
 * \return char
 */
char MOT_iemeCaractere(MOT_Mot mot, int i);

/**
 * \fn void MOT_insereiemeCaractere(MOT_Mot mot, char c, int i)
 * \brief Procédure qui insère un caractère dans un mot à une position voulue
 * \attention précondition : i <= MOT_longueur(mot)+1
 *
 * \param mot : le mot
 * \param c : le caractère
 * \param l : la position du caractère à insérer
 */
void MOT_insereiemeCaractere(MOT_Mot mot, char c, int i);

/**
 * \fn MOT_Mot MOT_remplaceLettre(MOT_Mot mot, char c, int i)
 * \brief Fonction qui permet de remplacer le caractère d'un mot à une position voulue par un autre caractère
 * \attention précondition : i <= MOT_longueur(mot)
 *
 * \param mot : le mot
 * \param c : le caractère que l'on veut insérer
 * \param i : la position de la lettre à remplacer
 * \return MOT_Mot
 */
MOT_Mot MOT_remplaceLettre(MOT_Mot mot, char c, int i);

/**
 * \fn MOT_Mot MOT_inverseLettres(MOT_Mot mot, int i)
 * \brief Fonction qui permet d'inverser deux lettres consécutives d'un mot
 * \attention précondition : i < MOT_longueur(mot)
 *
 * \param mot : le mot
 * \param i : la position de la première lettre à inverser
 * \return MOT_Mot
 */
MOT_Mot MOT_inverseLettres(MOT_Mot mot, int i);

/**
 * \fn MOT_Mot MOT_supprimeLettre(MOT_Mot mot, int i)
 * \brief Fonction qui permet de supprimer une lettre à une position donnée un mot
 * \attention précondition : i <= MOT_longueur(mot) et MOT_longueur(mot)>=2
 *
 * \param mot : le mot
 * \param i : la position de la lettre
 * \return MOT_Mot
 */
MOT_Mot MOT_supprimeLettre(MOT_Mot mot, int i);

/**
 * \fn MOT_Mot MOT_insereLettre(Mot mot, char c, int i)
 * \brief Fonction qui permet de copier d'insérer un caractère dans un mot à une position voulue
 * \attention précondition : i <= MOT_longueur(mot)+1 et MOT_estUnCaractereValide(c)
 *
 * \param mot : le mot
 * \param c : le caractère
 * \param i : la position de la lettre à insérer
 * \return MOT_Mot
 */
MOT_Mot MOT_insereLettre(MOT_Mot mot, char c, int i);

/**
 * \fn MOT_Mot *MOT_decomposeMot(MOT_Mot mot, int i)
 * \brief Fonction qui permet de décomposer un mot en deux mots différents
 * \attention précondition : i <= MOT_longueur(mot)-1 et MOT_longueur(mot)>=2
 *
 * \param mot : le mot à décomposer
 * \param i : indice du caractère où commence le deuxième mot
 * \return MOT_Mot*
 */
MOT_Mot *MOT_decomposeMot(MOT_Mot mot, int i);

/**
 * \fn bool MOT_estUnCaractereValide(char c)
 * \brief Fonction qui permet de savoir si un caractère est valide pour être inséré dans un mot
 *
 * \param c : le caractère
 * \return bool
 */
bool MOT_estUnCaractereValide(char c);

#endif
