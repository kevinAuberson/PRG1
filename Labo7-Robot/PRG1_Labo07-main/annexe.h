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
#ifndef TP7_ANNEXE_H
#define TP7_ANNEXE_H

#include <string>

int saisieUtilisateur(const std::string& msgUtilisateur, const std::string& msgErreur, const int& VALEUR_MIN, const int& VALEUR_MAX);
int valeurAleatoire(int valMin, int valMax);

#endif //TP7_ANNEXE_H
