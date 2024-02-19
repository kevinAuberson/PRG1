/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : robots.h
  Nom du labo : Labo 7 - Robot
  Auteur(s)   : Auberson Kevin - Rodrigues Fraga Brian
  Date        : 13.12.2022
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef TP7_ROBOTS_H
#define TP7_ROBOTS_H

class Robot {
public:
	Robot(int id, int x, int y); // Constructeur

    int getID ();                // Méthodes
    int getX ();
    int getY ();
	 enum Directions{UP, DOWN, RIGHT, LEFT};

private:
    int id;                      // Attributs
    int x, y;

    void moveRobot(Directions d);
};


#endif //TP7_ROBOTS_H
