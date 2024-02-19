/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : saisie.cpp
  Nom du labo : Labo 5 - Crible Eratosthène
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago
  Date        : 15.11.2022
  But         : Librairie qui permet le contrôle des saisies entrées par
                l'utilisateur.

  Remarque(s) : RAS

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <limits>
#include "saisie.h"
#include "affichage.h"

using namespace std;

#define VIDER_BUFFER cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

//*******************************************************************************************************************


// nom         saisie
// but         Vérifie la saisie si l'année choisie par l'utilisateur est dans l'intervalle défini
//
// param       aucun
// return      la valeur entrée par l'utilisateur
// exception   n/a
int verifierSaisieUtilisateur() {
   int valeurUtilisateur;
   bool erreur;
   do{
         afficherSaisie();
         erreur = not(cin >> valeurUtilisateur) or valeurUtilisateur < VALEUR_MIN
                  or valeurUtilisateur > VALEUR_MAX;
         if(erreur){
            msgErreurSaisie();
         }

         cin.clear();
         VIDER_BUFFER;

   }while(erreur);

   return valeurUtilisateur;
}

//*******************************************************************************************************************

// nom         recommencer
// but         Demander à l'utilisateur s'il veut recommencer le programme
//
// param       aucun
// return      bool vrai ou faux pour savoir si le programme doit être relancé ou non
// exception   n/a
bool recommencerProgramme(){

   bool erreur;
   char choixUtilisateur;

   // Tant que le choix de l'utilisateur est différant de O/N, lui redemande de refaire un choix
   do {
      msgRecommencer();
      erreur = not(cin >> choixUtilisateur) and (tolower(choixUtilisateur) == 'o'
               or tolower(choixUtilisateur) == 'n');


      erreur = tolower(choixUtilisateur) != 'o' and tolower(choixUtilisateur) != 'n';


      cin.clear();
      VIDER_BUFFER;
      cout << endl;

   } while (erreur);

   return tolower(choixUtilisateur) == 'o';
}

//*******************************************************************************************************************