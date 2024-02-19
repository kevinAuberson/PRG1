/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo 7 - Robot
  Auteur(s)   : Auberson Kevin - Rodrigues Fraga Brian
  Date        : 13.12.2022
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <limits>
#include <random>
#include "annexe.h"

using namespace std;

int saisieUtilisateur(const string& msgUtilisateur, const string& msgErreur, const int& VALEUR_MIN, const int& VALEUR_MAX) {
    int valeurUtilisateur;
    bool erreur;
    do{
        cout << msgUtilisateur << endl;
        erreur = not(cin >> valeurUtilisateur) or valeurUtilisateur < VALEUR_MIN
                 or valeurUtilisateur > VALEUR_MAX;
        if(erreur){
            cout << msgErreur << endl;
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }while(erreur);

    return valeurUtilisateur;
}

/**
 * Cette fonction génère un nombre aléatoire entre 0 et valMax
 * @param valMax
 * @return valeurAleatoire
 */
int valeurAleatoire(const int valMin,const int valMax)
{

	const int RANGE_FROM = valMin;
	const int RANGE_TO = valMax;

	random_device                  rand_dev;
	default_random_engine          generator(rand_dev());
	uniform_int_distribution<int>  distr(RANGE_FROM, RANGE_TO);

	return distr(generator);
}