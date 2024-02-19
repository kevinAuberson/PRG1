/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : terrain.cpp
  Nom du labo : Labo 7 - Robot
  Auteur(s)   : Auberson Kevin - Rodrigues Fraga Brian
  Date        : 13.12.2022
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "terrain.h"
#include "robots.h"
#include "annexe.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <thread>

using namespace std;

//----------------------------------------------------
// constructeurs
//----------------------------------------------------
Terrain::Terrain(int x, int y, size_t nbrRobots) {
    this->x = x;
    this->y = y;

    for (size_t i = 0; i < nbrRobots; ++i){
        robotsVivant.emplace_back((int)i, valeurAleatoire(1,x-1), valeurAleatoire(1,y-1));
    }
};

//----------------------------------------------------
// méthodes
//----------------------------------------------------
int Terrain::getX() const {
    return this->x;
}

int Terrain::getY() const {
    return this->y;
}

void Terrain::run() {
    //do {
        Terrain::bougerRobots();

        Terrain::afficher();
    //} while (robotsVivant.size() > 1);
}

void Terrain::afficher() {
    std::system("clear");
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (j == 0 or j == y-1) {
                cout << "|";
            } else if (i == 0 or i == x-1) {
                cout << "-";
            } else {
                for (size_t k = 0; k <= robotsVivant.size(); ++k) {
                    if (i == robotsVivant[k].getX() and j == robotsVivant[k].getY()) {
                        cout << (int)robotsVivant[k].getID();
                        ++j;
                    }
                }
                cout << " ";
            }
        }
        cout << endl;
    }
	std::this_thread::sleep_for(1ms);
}

void Terrain::bougerRobots() {
   Terrain::melangerRobot();
	for(size_t i = 0; i < robotsVivant.size(); ++i){

		robotsVivant[i].moveRobot();
	}
}

void Terrain::melangerRobot(){
    // repris de https://cplusplus.com/reference/algorithm/shuffle/
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(robotsVivant.begin(), robotsVivant.end(), std::default_random_engine(seed));
}
