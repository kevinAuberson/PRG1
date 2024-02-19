/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo 5 - Crible Eratosthène
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago
  Date        : 15.11.2022
  But         : Créer un tableau selon une valeure entrée par un utilisateur puis calcule le nombre de valeures
                premières générées à l'interieur de ce tableau.

  Remarque(s) : Ce programme se base sur  le crible d'Eratosthène :
                https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne



  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include <cstdlib>
#include "affichage.h"
#include "saisie.h"
#include "tableau.h"

//*******************************************************************************************************************

// nom         main
// but         Fonction principale du programme
//
// return      int
// exception   n/a
int main() {


   std::vector<char> tableau;                      //Tableau utilisé pour généré et stocker les positions premières
   std::vector<int>  nombresPremiers;              //Tableau utilisé pour généré et stocker les valeurs premières
               int   valeurTableau;                //Valeure pour définir la taille du tableau

   do{
      afficherBienvenue();
      valeurTableau = verifierSaisieUtilisateur();
      tableau = creerTableau(valeurTableau);
      tableau = criblerTableau(tableau);
      afficherTableau(tableau);
      nombresPremiers = recupererNombresPremiers(tableau);
      afficherNombresPremiers(nombresPremiers);


   } while (recommencerProgramme());

   return EXIT_SUCCESS;
}

//*******************************************************************************************************************

