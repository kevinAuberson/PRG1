/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : terrain.h
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         : Prototypage des fonctions liées au terrain

  Remarque(s) : -

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef LABO_08_SNAKES_TERRAIN_H
#define LABO_08_SNAKES_TERRAIN_H

#include <vector>
#include "serpents.h"


class Terrain {

public:
    Terrain(int hauteur, int largeur, std::size_t nbSerpents);

    /**
     * Le [[nodiscard]] a du être ajouté pour éviter un warning de l'IDE
     * @return le nombre de serpents sur le terrain
     */
    [[nodiscard]] std::size_t getnbrSerpents() const;


    // Soustrait de un le nombre de serpents sur le terrain
    void reduireNbrSerpents();

    /**
     * Crée les différents serpents grâce a la largeur et hauteur du terrain
     * @param vecSerpent
     */
    void creationSerpents(std::vector<Serpent> &vecSerpent) const;


private:
    int largeur;
    int hauteur;
    std::size_t nbrSerpents;
};

#endif //LABO_08_SNAKES_TERRAIN_H
