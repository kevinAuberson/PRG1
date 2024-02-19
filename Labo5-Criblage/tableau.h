/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : calendrier.h
  Nom du labo : Labo 5 - Crible Eratosthène
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago
  Date        : 15.11.2022
  But         : Déclaration des fonctions de la librairie tableau et nombre premier

  Remarque(s) : RAS

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef CRIBLE_ERATOSTHENE_TABLEAU_H
#define CRIBLE_ERATOSTHENE_TABLEAU_H

#include <iostream>
#include <vector>

std::vector<char> creerTableau(int derniereValeureTableau);

std::vector<char> criblerTableau(std::vector<char> tableau);

std::vector<int> recupererNombresPremiers(const std::vector<char>& tableau);


#endif //CRIBLE_ERATOSTHENE_TABLEAU_H
