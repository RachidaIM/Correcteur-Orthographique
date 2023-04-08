#include<stdlib.h>
#include<CUnit/Basic.h>
#include <stdbool.h>
#include "TAD_Mot.h"
#include "TAD_Dictionnaire.h"
#include "listeChainee.h"
#include "elementsArbreNaire.h"
#include "fonctionsSurElement.h"
/* #define TRUE 1
#define FALSE 0 */

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

EAN_Element arbreTest(){
  EAN_Element test, a1, a2, a3;
  test = DICO_arbreNAire();
  a1 = DICO_arbreNAire();
  a2 = DICO_arbreNAire();
  a3 = DICO_arbreNAire();

  test->caractere = ' ';
  test->nbFils = 1;
  test->estFinDeMot = false;
  test->fils = LC_listeChainee();
    
  a1->nbFils = 2;
  a1->caractere = 't';
  a1->estFinDeMot = false;
  a1->fils = LC_listeChainee();
  LC_ajouter(&(test->fils),&a1, EAN_copierElement);

  a2->nbFils = 0;
  a2->caractere = 'a';
  a2->estFinDeMot = true;
  a2->fils = LC_listeChainee();
  LC_ajouter(&(a1->fils),&a2, EAN_copierElement);

  a3->nbFils = 0;
  a3->caractere = 'i';
  a3->estFinDeMot = false;
  a3->fils = LC_listeChainee();
  LC_ajouter(&(a1->fils),&a3, EAN_copierElement);
  return test;
}
  
void test_remplaceLettre(void){
  MOT_Mot mTest = MOT_creerMot("test");
  MOT_Mot mTest2 = MOT_remplaceLettre(mTest,'i',1);
  CU_ASSERT_TRUE(strcmp(MOT_obtenirData(mTest2),"tist")==0);
  MOT_supprimerMot(&mTest);
  MOT_supprimerMot(&mTest2);
}

void test_inverseLettre(void){
  MOT_Mot mTest = MOT_creerMot("test");
  MOT_Mot mTest2 = MOT_inverseLettres(mTest, 1);
  CU_ASSERT_TRUE(strcmp(MOT_obtenirData(mTest2),"tset")==0);
  MOT_supprimerMot(&mTest);
  MOT_supprimerMot(&mTest2);
}

void test_supprimeLettre(void){
  MOT_Mot mTest = MOT_creerMot("test");
  MOT_Mot mTest2 =MOT_supprimeLettre(mTest,2);
  CU_ASSERT_TRUE(strcmp(MOT_obtenirData(mTest2),"tet")==0);
  MOT_supprimerMot(&mTest);
  MOT_supprimerMot(&mTest2);
}

void test_insereLettre(void){
  MOT_Mot mTest = MOT_creerMot("test");
  MOT_Mot mTest2 = MOT_insereLettre(mTest,'i',1);
  CU_ASSERT_TRUE(strcmp(MOT_obtenirData(mTest2),"tiest")==0);
  MOT_supprimerMot(&mTest);
  MOT_supprimerMot(&mTest2);
}

void test_decomposeMot(void){
  MOT_Mot mTest = MOT_creerMot("test");
  MOT_Mot *mTest2 =MOT_decomposeMot(mTest,2);
  CU_ASSERT_TRUE((strcmp(MOT_obtenirData(mTest2[0]),"te")==0) && (strcmp(MOT_obtenirData(mTest2[1]),"st")==0));
  MOT_supprimerMot(&mTest);
  MOT_supprimerMot(&mTest2[0]);
  MOT_supprimerMot(&mTest2[1]);
  free(mTest2);
}

void test_estPresent(void){
  EAN_Element arbre = arbreTest();
  DICO_Dictionnaire dico = arbre;
  MOT_Mot m;
  m = MOT_creerMot("ta");
  CU_ASSERT_TRUE(DICO_estPresent(dico, m));
}

void test_ajoutMot(void){
  EAN_Element arbre = arbreTest();
  DICO_Dictionnaire dico = arbre;
  MOT_Mot m;
  m = MOT_creerMot("tir");
  DICO_ajoutMot(dico,m);
  CU_ASSERT_TRUE(DICO_estPresent(dico,m));
}

void test_dictionnaireEnFichier(){
  EAN_Element arbre = arbreTest();
  DICO_Dictionnaire dico = arbre;
  FILE *fdico;
  fdico = fopen("fichierTest", "w");
  DICO_dictionnaireEnFichier(fdico, dico);
  fclose(fdico);
  fdico = fopen("fichierTest", "r");
  DICO_fichierEnDictionnaire(dico, fdico);
  fclose(fdico);
  CU_ASSERT_TRUE(EAN_comparerElement(dico, arbre));
}

int main(int argc, char** argv){
    CU_pSuite pSuite = NULL;

    /* initialisation du registre de tests*/
    if (CUE_SUCCESS != CU_initialize_registry()){
        return CU_get_error();
    }

    pSuite = CU_add_suite("Tests ", init_suite_success, clean_suite_success);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "Test de la fonction remplaceLettre", test_remplaceLettre))
	  || (NULL == CU_add_test(pSuite, "Test de la fonction inverseLettres", test_inverseLettre))
	  || (NULL == CU_add_test(pSuite, "Test de la fonction supprimeLettre", test_supprimeLettre))
	  || (NULL == CU_add_test(pSuite, "Test de la fonction insereLettre", test_insereLettre))
	  || (NULL == CU_add_test(pSuite, "Test de la fonction decomposeMot", test_decomposeMot))
	  || (NULL == CU_add_test(pSuite, "Test de la fonction estPresent", test_estPresent))
	  || (NULL == CU_add_test(pSuite, "Test de la fonction ajoutMot", test_ajoutMot))
    || (NULL == CU_add_test(pSuite, "Test de la fonction dictionnaireEnFichier", test_dictionnaireEnFichier))
    ){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    CU_cleanup_registry();
    return CU_get_error();
}
