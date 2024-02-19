/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : tondeuse.h
  Nom du labo : Labo 6 - Tondeuse
  Auteur(s)   : Auberson Kevin - Rayburn Nathan
  Date        : 29.11.2022
  But         : Header du fichier tondeuse.cpp

  Remarque(s) : RAS

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#ifndef LABO_06_TONDEUSE_H
#define LABO_06_TONDEUSE_H

#include <array>
#include <vector>
#include "annexe.h"

using Tondeuse = std::array<int, 2>;
using Ligne = std::vector<char>;
using Terrain = std::vector<Ligne>;

enum charTerrain {
             // In char :
    L = 35,  // '#'
    X = 88,  // 'X'
    H = 126, // '~'
    C = 46   // '.'
};

/**
 * Cette fonction permet de couper l'herbe lorsqu'elle est presente
 *                           Type
 * @param terrain            Terrain
 * @param tondeuse           Tondeuse
 * @param nombreDePas        int
 * @param afficherAChaquePas bool
 */
void tondre(Terrain& terrain, Tondeuse& tondeuse, int nombreDePas, bool afficherPas);

#endif //LABO_06_TONDEUSE_H