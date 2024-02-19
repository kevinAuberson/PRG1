/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : annexe.cpp
  Nom du labo : Labo 6 - Tondeuse
  Auteur(s)   : Auberson Kevin - Rayburn Nathan
  Date        : 29.11.2022
  But         : Librairie annexe contenant la/les fonction(s)
                - generation d'un nombre aleatoire

  Remarque(s) : RAS

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include "annexe.h"
#include <iostream>
#include <random>
using namespace std;
/**
 * Cette fonction génère un nombre aléatoire entre 0 et valMax
 * @param valMax
 * @return valeurAleatoire
 */
int valeurAleatoire(const int valMax)
{

    const int RANGE_FROM = 0;
    const int RANGE_TO = valMax;

    random_device                  rand_dev;
    default_random_engine          generator(rand_dev());
    uniform_int_distribution<int>  distr(RANGE_FROM, RANGE_TO);

    return distr(generator);
}

