/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : robots.cpp
  Nom du labo : Labo 7 - Robot
  Auteur(s)   : Auberson Kevin - Rodrigues Fraga Brian
  Date        : 13.12.2022
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "robots.h"

using namespace std;

Robot::Robot(int id, int x, int y) {
	this->id 	= id;
	this->x 	= x;
	this->y 	= y;
}

int Robot::getID() {
	return this->id;
}

int Robot::getX() {
	return this->x;
}

int Robot::getY() {
	return this->y;
}

void Robot::moveRobot(Directions d)
{
	switch (d) {
        case Directions::UP 		: {++y; break;}
        case Directions::RIGHT 	: {++x; break;}
		  case Directions::DOWN 	: {--y; break;}
        case Directions::LEFT 	: {--x; break;}
		default: {break;}
	}
}