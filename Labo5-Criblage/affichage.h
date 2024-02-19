/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : affichage.h
  Nom du labo : Labo 5 - Crible Eratosthène
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago
  Date        : 15.11.2022
  But         : Déclaration des fonctions de la librairie affichage.cpp

  Remarque(s) : RAS

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef CRIBLE_ERATOSTHENE_AFFICHAGE_H
#define CRIBLE_ERATOSTHENE_AFFICHAGE_H

#include <vector>

extern const int VALEUR_MIN, VALEUR_MAX;

void afficherBienvenue();

void afficherSaisie();

void msgErreurSaisie();

void msgRecommencer();

void afficherTableau(const std::vector<char>& tableau);

void afficherNombresPremiers(const std::vector<int>& tableau);

#endif //CRIBLE_ERATOSTHENE_AFFICHAGE_H
