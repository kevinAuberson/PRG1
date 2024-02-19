/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : tondeuse.cpp
  Nom du labo : Labo 6 - Tondeuse
  Auteur(s)   : Auberson Kevin - Rayburn Nathan
  Date        : 29.11.2022
  But         : Les tondeuses automatiques se déplacent aléatoirement dans un espace délimité et
                contenant des obstacles.

  Remarque(s) : RAS

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <algorithm>
#include <thread>
#include "tondeuse.h"

using namespace std;

enum class Direction {
    NORD,
    EST,
    SUD,
    OUEST
};

/**
 * Cette fonction permet de gerer l'opperateur de flux pour un vector<char>
 *              Type
 * @param os    ostream
 * @param ligne Ligne
 * @return      ostream
 */
ostream& operator<< (ostream& os, const Ligne& ligne) {

    for (char i : ligne) {
        os << i << " ";
    }
    return os;
}

/**
 * Cette fonction permet de gerer l'operateur de flux pour une matrice
 *              Type
 * @param os    ostream
 * @param m     Terrain
 * @return      ostream
 */
ostream& operator<< (ostream& os, const Terrain& m) {
    for (const Ligne& ligne : m)
        os << ligne << endl;
    return os;
}
/**
 * Cette fonction permet de couper l'herbe lorsqu'elle est presente
 *                  Type
 * @param terrain   Terrain
 * @param tondeuse  Tondeuse
 */
void couperHerbe(Terrain& terrain, const Tondeuse& tondeuse)
{
    if(terrain[tondeuse[0]][tondeuse[1]] == H)
    {
        terrain[tondeuse[0]][tondeuse[1]] = C;
    }
}
/**
 * Cette fonction affiche le terrain
 *                  Type
 * @param terrain   Terrain
 */
void afficherTerrain (const Terrain& terrain) {

    system("cls");
    cout << terrain;
    std::this_thread::sleep_for(1ms);
}

/**
 * Cette fonction vérifie s'il y a un mur dans une des 4 positions possibles si il y a un
 * mur ajoute la position dans un vecteur mur
 *                  Type
 * @param terrain   Terrain
 * @param tondeuse  Tondeuse
 * @return          vector<Direction>
 */
vector<Direction> positionsMurs(const Terrain& terrain, const Tondeuse& tondeuse){

    vector<Direction> murs = {};

    if(terrain.at(tondeuse[0]-1).at(tondeuse[1]) == L or terrain.at(tondeuse[0]-1).at(tondeuse[1]) == X)
    {
        murs.push_back(Direction::OUEST);
    }
    if(terrain.at(tondeuse[0]+1).at(tondeuse[1]) == L or terrain.at(tondeuse[0]+1).at(tondeuse[1]) == X)
    {
        murs.push_back(Direction::EST);
    }
    if(terrain.at(tondeuse[0]).at(tondeuse[1]-1) == L or terrain.at(tondeuse[0]).at(tondeuse[1]-1) == X)
    {
        murs.push_back(Direction::NORD);
    }
    if(terrain.at(tondeuse[0]).at(tondeuse[1]+1) == L or terrain.at(tondeuse[0]).at(tondeuse[1]+1) == X)
    {
        murs.push_back(Direction::SUD);
    }
    return murs;
}
/**
 * Cette fonction permet de trier les directions possibles
 *                      Type
 * @param mur           vector<Direction>
 * @param directions    vector<Direction>
 */
void directionsPossible(const vector<Direction>& murs, vector<Direction>& directions)
{
    for(const Direction& i : murs)
    {
        directions.erase(remove(directions.begin(), directions.end(), i), directions.end());
    }
}
/**
 * Cette fonction permet de choisir la direction aleatoire de la tondeuse
 *                      Type
 * @param terrain       Terrain
 * @param directions    vector<Direction>
 */
void choisirUneDirection(Tondeuse& tondeuse, const vector<Direction>& directions)
{
    Direction directionChoisi = directions[valeurAleatoire((int)directions.size()-1)];
    switch (directionChoisi) {
        case Direction::NORD : tondeuse[1] -= 1;
            break;
        case Direction::EST: tondeuse[0] += 1;
            break;
        case Direction::SUD: tondeuse[1] += 1;
            break;
        case Direction::OUEST: tondeuse[0] -= 1;
            break;
    }
}
/**
 * Cette fonction permet de faire avancer la tondeuse
 *                  Type
 * @param terrain   Terrain
 * @param tondeuse  Tondeuse
 */
void avancerTondeuse(Terrain& terrain, Tondeuse& tondeuse)
{

    vector<Direction> murs = positionsMurs(terrain,  tondeuse);
    vector<Direction> directionsPossibleTondeuse = { Direction::NORD, Direction::SUD, Direction::EST , Direction::OUEST };

    if(!murs.empty())
    {
        directionsPossible(murs, directionsPossibleTondeuse);
    }
    choisirUneDirection(tondeuse, directionsPossibleTondeuse);
}

void tondre(Terrain& terrain, Tondeuse& tondeuse, int nombreDePas, const bool afficherAChaquePas)
{
    do{

        avancerTondeuse(terrain, tondeuse);
        couperHerbe(terrain,tondeuse);

        if(afficherAChaquePas)
        {
          afficherTerrain(terrain);
        }

        nombreDePas--;
    }while(nombreDePas);

    afficherTerrain(terrain);
}