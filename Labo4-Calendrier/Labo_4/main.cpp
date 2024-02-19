/*  -----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Kevin Auberson et Martin Derleth
Date creation  : 02.11.2022

Description    : Utilise les sous programmes de la librairie calendrier

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 12.2.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include "calendrier.h"

using namespace std;

int main() {

	char recommencer;
	do {
		int annee = saisieAnnee();

		afficheCalendrier(annee);

		cout << "Voulez-vous recommencer [O/N] ?";

		cin >> recommencer;

	} while (recommencer == 'O');

    return EXIT_SUCCESS;
}
