/*  -----------------------------------------------------------------------------------
Nom du fichier : calendrier.cpp
Auteur(s)      : Kevin Auberson et Martin Derleth
Date creation  : 02.11.2022

Description    : Sous-programme permettant l'affichage du calendrier en fonction de l'année

Remarque(s)    : Méthode d'affichage inspirée de geeksforgeeks
					  Source : https://www.geeksforgeeks.org/print-calendar-for-a-given-year/

Compilateur    : Mingw-w64 g++ 12.2.0
-----------------------------------------------------------------------------------
*/

#include "calendrier.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int saisieAnnee(){

	int saisie;
	bool erreur;

	do {
		// saisie et vérification
		cout << "Entrer une annee dans cette intervalle [ 1800  - 2100 ] pour generer le calendrier : ";
		erreur = not(cin >> saisie) or saisie < 1800 or saisie > 2100;

		// gestion du flux
		if (erreur) {
			cout << "L'annee choisi doit etre dans l'intervalle [ 1800  - 2100 ]." << endl;
			cin.clear();
		}

		// vider buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while(erreur);

	return saisie;
}

bool bisextille(int annee){
	// divisible par 400      ou alors par 4 mais pas par 100
	return (annee % 400 == 0) or (annee % 4 == 0 and annee % 100 != 0);
}

string nomMois (int noMois) {
	//Retour du nom du mois en fonction du mois choisi
	switch (noMois) {
		case 0  :   return "Janvier"	;
		case 1  :   return "Fevrier"	;
		case 2  :   return "Mars"		;
		case 3  :   return "Avril"		;
		case 4  :   return "Mai"		;
		case 5  :   return "Juin"		;
		case 6  :   return "Juillet"	;
		case 7  :   return "Aout"		;
		case 8  :   return "Septembre";
		case 9  :   return "Octobre"	;
		case 10 :   return "Novembre"	;
		case 11 :   return "Decembre"	;
		default :	return ""			;
	}
}

int nbJourMois (int noMois, int annee) {
	//Retour du nombre de jours en fonction du mois choisi
	switch (noMois) {
		case 0  :   return 31;
		case 1  :   return 28 + bisextille(annee); //
		case 2  :   return 31;
		case 3  :   return 30;
		case 4  :   return 31;
		case 5  :   return 30;
		case 6  :   return 31;
		case 7  :   return 31;
		case 8  :   return 30;
		case 9  :   return 31;
		case 10 :   return 30;
		case 11 :   return 31;
		default :	return  0;
	}
}

void afficheCalendrier (int annee)  {

	//Variable pour connaître notre position dans la semaine lors d'un
	// passage à un nouveau mois
	int positionDansSemaine = 0;

	//Boucle par mois
	for (int i= 0; i < 12; i++) {
		//Affichage du mois et de l'année
		cout << " " << nomMois(i) << " " << annee << endl;

		//Affichage du nom des jours en entête
		cout << " L  M  M  J  V  S  D" << endl;

		//Ajout du nb de jours dans le mois dans une variable
		//pour l'utiliser dans une boucle
		int joursMois = nbJourMois(i,annee);

		//Ajout d'espace dans le mois suivant en fonction de la position dans
		// la semaine
		for (int k = positionDansSemaine; k > 0;--k) {
			cout << "   ";
		}

		//Boucle pour afficher du calendrier
		for (int j = 1; j <= joursMois; j++) {
			cout << setw(2) << j << " ";

			//incrémentation de la position de la semaine
			++positionDansSemaine;

			if (positionDansSemaine % 7 == 0) {
				cout << endl;
				//Retour à lundi dans la position de la semaine
				positionDansSemaine = 0;
			}
		}

		//Ajout d'une ligne pour l'espacement entre les mois
		cout << endl << endl;
	}

}