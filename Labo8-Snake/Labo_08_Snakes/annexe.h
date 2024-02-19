/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : annexe.h
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         : Prototypage des fonctions annexes

  Remarque(s) : -

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef LABO_08_SNAKES_ANNEXE_H
#define LABO_08_SNAKES_ANNEXE_H

#include <string>

/**
 * Fonction qui utilise un générateur aléatoire pour retourner une valeur comprise entre 2 paramètres
 * @param valMax Valeur aléatoire maximale retournée (défaut = 1)
 * @param valMin Valeur aléatoire minimale retournée (défaut = 1)
 */
int aleatoire(int valMax = 1, int valMin = 1);

/**
 * Fonction qui demande a l'utilisateur d'entrer une valeur comprise entre les deux valeurs données
 * @param valMin   la valeur minimale entrée
 * @param valMaxla la valeur maximale entrée
 * @param str message d'entrée utilisateur spécifique
 */
int entreeUser(int valMin, int valMax,const std::string& str);



#endif //LABO_08_SNAKES_ANNEXE_H
