/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo 7 - Robot
  Auteur(s)   : Auberson Kevin - Rodrigues Fraga Brian
  Date        : 13.12.2022
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "annexe.h"
#include "terrain.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
int main(){

    // ===================== Déclarations des variables ===================== //
    const int VALEUR_MAX_TERRAIN = 1000;
    const int VALEUR_MIN_TERRAIN = 10;
    const int VALEUR_MIN_ROBOT   = 1;
    const int VALEUR_MAX_ROBOT   = 9;
    const string LARGEUR = "largeur [10..1000] : ";
    const string HAUTEUR = "hauteur [10..1000] : ";
    const string ROBOTS  = "nbre object [0..9] : ";
    const string MSG_ERREUR = "Erreur!\nLa valeur doit être dans l'intervalle [10..1000].";
    const string MSG_ERREUR_ROBOT = "Erreur!\nLa valeur doit être dans l'intervalle [0..9].";
    int largeur, hauteur;
    size_t robots;
    // ====================================================================== //
    // Début du programme
    // ====================================================================== //

    // Demander taille terrain
    largeur =  saisieUtilisateur(LARGEUR,MSG_ERREUR,VALEUR_MIN_TERRAIN,VALEUR_MAX_TERRAIN);
    hauteur =  saisieUtilisateur(HAUTEUR,MSG_ERREUR,VALEUR_MIN_TERRAIN,VALEUR_MAX_TERRAIN);

    // Demander nbr robots
    robots = (size_t)saisieUtilisateur(ROBOTS,MSG_ERREUR_ROBOT,VALEUR_MIN_ROBOT,VALEUR_MAX_ROBOT);

    Terrain terrain(largeur, hauteur, robots);
    terrain.run();

    // Boucle afficher terrain avec les robots qui bougent


    // ========================== Fin du programme ========================== //
    return EXIT_SUCCESS;
}
