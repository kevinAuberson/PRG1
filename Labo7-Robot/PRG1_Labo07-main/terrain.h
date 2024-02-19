/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : terrain.h
  Nom du labo : Labo 7 - Robot
  Auteur(s)   : Auberson Kevin - Rodrigues Fraga Brian
  Date        : 13.12.2022
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef TP7_TERRAIN_H
#define TP7_TERRAIN_H

#include <cstdlib> // std::
#include <vector>
#include "robots.h"

class Terrain{
public:
	 Terrain (int x, int y, size_t nbrRobots);		//constructeur terrain

     int getX() const;
     int getY() const;
     void run();
     void afficher();

private:
	 int x;
	 int y;
	 std::vector<Robot> robotsVivant;
     void bougerRobots();
     void melangerRobot();
};

#endif //TP7_TERRAIN_H
