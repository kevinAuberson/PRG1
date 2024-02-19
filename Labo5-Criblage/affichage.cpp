/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : affichage.cpp
  Nom du labo : Labo 5 - Crible Eratosthène
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago
  Date        : 15.11.2022
  But         : Libraire des fonctions d'affichage et des constantes de textes.

  Remarque(s) : RAS

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include "affichage.h"

using namespace std;

const int VALEUR_MIN = 2, VALEUR_MAX = 100;

#define SAUT_DE_LIGNE    cout << endl

//*******************************************************************************************************************

// nom         afficherBienvenue
// but         Afficher le premier message du programme qui contient les instructions à suivre
//
// param       aucun
// return      void
// exception   n/a
void afficherBienvenue() {
   const string MSG_BIENVENUE = "Bonjour, ce programme affichera la liste des \n"
                                "nombres premiers contenus dans un tableau.\n"
                                "La valeur du tableau doit etre contenue entre "s;


   cout << MSG_BIENVENUE << VALEUR_MIN << " et " << VALEUR_MAX;
   SAUT_DE_LIGNE;
}

//*******************************************************************************************************************

// nom         afficherSaisie
// but         Afficher le message qui demande à l'utilisateur sa saisie
//
// param       aucun
// return      void
// exception   n/a
void afficherSaisie() {
   string MSG_SAISIE_DEBUT    = "Veuillez entrer votre valeur [2 - "s,
          MSG_SAISIE_FIN      = "] :"s;
   SAUT_DE_LIGNE;
   cout << MSG_SAISIE_DEBUT << VALEUR_MAX << MSG_SAISIE_FIN;

}

//*******************************************************************************************************************

// nom         msgErreurSaisie
// but         Afficher un message d'erreur si l'utilisateur entre une année hor intervalle
//
// param       aucun
// return      void
// exception   n/a
void msgErreurSaisie() {
   const string MSG_ERREUR   = "La valeur doit etre comprise entre "s;
   const string SYMB_SEPARATION = " - "s;

   cout << MSG_ERREUR << VALEUR_MIN << SYMB_SEPARATION << VALEUR_MAX;
   SAUT_DE_LIGNE;
}

//*******************************************************************************************************************

// nom         msgRecommencer
// but         Afficher le message pour recommencer
//
// param       aucun
// return      void
// exception   n/a
void msgRecommencer(){
   const string MSG_RECOMMENCER   = "Voulez vous recommencer [O/N] ? : "s;
   SAUT_DE_LIGNE;
   SAUT_DE_LIGNE;
   cout << MSG_RECOMMENCER;
}

//*******************************************************************************************************************

// nom         afficherTableau
// but         Affiche un tableau (vector<char>) et applique un saut de ligne toutes les 10 valeurs.
//
// param       const vector<char>& tableau de caractères 'O' et 'X'
// return      void
// exception   n/a
void afficherTableau(const std::vector<char>& tableau){

   const string MESSAGE_INITIALISATION= "Criblage du tableau"s;
   int nombreElements = 0;
   cout << MESSAGE_INITIALISATION;
   SAUT_DE_LIGNE;

   for(char valeur : tableau){
      cout << valeur << " ";
      nombreElements++;
      if(nombreElements == 10){
         SAUT_DE_LIGNE;
         nombreElements =0;
      }

   }

   SAUT_DE_LIGNE;
   SAUT_DE_LIGNE;

}

//*******************************************************************************************************************

// nom         afficherNombresPremiers
// but         Affiche un tableau (vector<int>) valeure par valeure.
// param       const vector<int>& tableau de nombres
// return      void
// exception   n/a
void afficherNombresPremiers(const std::vector<int>& tableau){

   const string MESSAGE_INITIALISATION_DEBUT = "Il y a "s,
                MESSAGE_INITIALISATION_FIN   = " nombres premiers : "s;
   cout << MESSAGE_INITIALISATION_DEBUT << tableau.size() << MESSAGE_INITIALISATION_FIN;
   SAUT_DE_LIGNE;

   for(int val: tableau){
      cout << val << " ";
   }

   SAUT_DE_LIGNE;
   SAUT_DE_LIGNE;

}