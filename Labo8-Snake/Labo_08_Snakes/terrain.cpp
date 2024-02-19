/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : terrain.cpp
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         : Initialisation des fonctions membres de la classe terrain

  Remarque(s) : -

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "terrain.h"
#include "annexe.h"
#include <iostream>

using namespace std;


Terrain::Terrain(int hauteur, int largeur, size_t nbrSerpents) {
    this->hauteur     = hauteur;
    this->largeur     = largeur;
    this->nbrSerpents = nbrSerpents;
}

size_t Terrain::getnbrSerpents() const {
    return nbrSerpents;
}

void Terrain::reduireNbrSerpents() {
    nbrSerpents--;
}

void Terrain::creationSerpents(vector<Serpent>& vecSerpent) const{
    bool emplacementOccupe = false;
    for (size_t i = 0; i < (nbrSerpents); ++i) {
        int valPomme   = aleatoire(10);
        // Pour les nouvelles coords, on réduit de 1 la larg/haut car le dernier pixel n'est pas visible
        int randX      = aleatoire(largeur-1);
        int randY      = aleatoire(hauteur-1);
        int randPommeX = aleatoire(largeur-1);
        int randPommeY = aleatoire(hauteur-1);

        // Vérification de l'emplacement ou le serpent doit apparaître.
        // Si le i est dans la première boucle, il n'y a pas de vérifications à faire.
        if(i)
            vecSerpent.emplace_back(int(i), randX, randY, randPommeX, randPommeY, valPomme);
        else {
            for (Serpent& serpent: vecSerpent) {
                if (serpent.getTeteX() == randX and serpent.getTeteY() == randY) {
                    i--;
                    emplacementOccupe = true;
                }
            }
            if(!emplacementOccupe)
                vecSerpent.emplace_back(int(i), randX, randY, randPommeX, randPommeY, valPomme);
            else
                emplacementOccupe=false;
        }
    }
}

