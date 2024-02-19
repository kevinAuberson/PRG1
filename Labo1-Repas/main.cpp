/*-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s) 		: Kevin Auberson & Evan Rothen
Date creation 	: 29.09.2022

Description 	: Programme permettant la saisie du nombre de chacun des
					  éléments de la carte du restaurant ainsi calculer le prix total du repas.

Remarque(s) 	: -

Compilateur 	: Mingw-w64 g++ 12.1.0
-----------------------------------------------------------------------------------*/

#include <iomanip> 	// setw(...) et setprecision(...)
#include <cstdlib> 	// EXIT_SUCCESS
#include <iostream> 	// cout et cin
#include <limits>    // numeric_limits<streamsize>

using namespace std;

int main() {
	//Initialisation des constantes
	const double 	PRIX_ENTREE 	= 4.3;
	const double 	PRIX_PLAT 		= 12.5;
	const double 	PRIX_BOISSON 	= 3.;
	const double 	PRIX_DESSERT 	= 6.;
	const double 	PRIX_CAFE 		= 2.9;
	const int 		LARGEUR 			= 11;

	//Initialisation des variables
	int nbrEntree;
	int nbrPlat;
	int nbrBoisson;
	int nbrDessert;
	int nbrCafe;
	double total;

	//-----------------------------------------------------------------------------------
	cout << "bonjour, ce programme ..."  << endl;
	cout << "voici le prix des elements" << endl;
	cout << "==========================" << endl;
	cout << fixed << setprecision(2);
	cout << " - entree  :" << setw(LARGEUR) << PRIX_ENTREE 	<< endl;
	cout << " - plat    :" << setw(LARGEUR) << PRIX_PLAT		<< endl;
	cout << " - boisson :" << setw(LARGEUR) << PRIX_BOISSON 	<< endl;
	cout << " - dessert :" << setw(LARGEUR) << PRIX_DESSERT 	<< endl;
	cout << " - cafe    :" << setw(LARGEUR) << PRIX_CAFE 		<< endl << endl;

	cout << "votre commande" << endl;
	cout << "==============" << endl;
	cout << "- nbre d'entree   :";
	cin >> nbrEntree;
	cout << "- nbre de plat    :";
	cin >> nbrPlat;
	cout << "- nbre de boisson :";
	cin >> nbrBoisson;
	cout << "- nbre de dessert :";
	cin >> nbrDessert;
	cout << "- nbre de cafe    :";
	cin >> nbrCafe;
	cout << endl << endl;

	total = PRIX_ENTREE * nbrEntree + PRIX_PLAT * nbrPlat + PRIX_BOISSON * nbrBoisson + PRIX_DESSERT * nbrDessert + PRIX_CAFE * nbrCafe;

	cout << "votre Ticket" << endl;
	cout << "============" << endl;
	cout << " - " << nbrEntree 	<< " entrees  :" << setw(LARGEUR) << PRIX_ENTREE * nbrEntree << endl;
	cout << " - " << nbrPlat 		<< " plats    :" << setw(LARGEUR) << PRIX_PLAT * nbrPlat << endl;
	cout << " - " << nbrBoisson 	<< " boissons :" << setw(LARGEUR) << PRIX_BOISSON * nbrBoisson << endl;
	cout << " - " << nbrDessert 	<< " desserts :" << setw(LARGEUR) << PRIX_DESSERT * nbrDessert << endl;
	cout << " - " << nbrCafe 		<< " cafes    :" << setw(LARGEUR) << PRIX_CAFE * nbrCafe << endl;
	cout << " -     total  :" 		<< setw(LARGEUR) << total << endl;
	cout << "merci de votre visite" << endl << endl;

	//-----------------------------------------------------------------------------------
	//Fin du programme
	cout << "presser ENTRER pour quitter";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   return EXIT_SUCCESS;
}