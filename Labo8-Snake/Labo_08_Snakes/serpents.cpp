/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : serpents.cpp
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         : Initialisation des fonctions membres de la classe serpent

  Remarque(s) : -

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "serpents.h"
#include <algorithm>
#include <iostream>


using namespace std;

Serpent::Serpent(int ID, int x, int y, int pommeX, int pommeY, int valPomme) {
	serpent.resize(10, {x, y});
	this->ID = ID;
	this->pommeX = pommeX;
	this->pommeY = pommeY;
	this->valPomme = valPomme;
}

int Serpent::getSerpentID() const {
	return this->ID;
}

int Serpent::getPommeX() const {
	return this->pommeX;
}

int Serpent::getPommeY() const {
	return this->pommeY;
}

int Serpent::getTeteY() const {
	return serpent[0][1];
}

int Serpent::getTeteX() const {
	return serpent[0][0];
}

bool Serpent::trouverPomme() {
	if (pommeX == getTeteX() and pommeY == getTeteY()) {
		surPomme = true;
		this->grandirSerpent(size_t(valPomme), 1);
	}
	return surPomme;
}

void Serpent::newPomme(int newPommeX, int newPommeY, int newPommeVal) {
	pommeX = newPommeX;
	pommeY = newPommeY;
	valPomme = newPommeVal;
	surPomme = false;
}

size_t Serpent::getSerpentSize() const {
	return serpent.size();
}

vector<vector<int>> Serpent::getSerpent() {
	return serpent;
}

size_t Serpent::couperSerpent(const vector<int> &searchVector) {
	auto taille = size_t(distance(find(serpent.begin(), serpent.end(), searchVector),
											serpent.end()));
	serpent.erase(find(serpent.begin(), serpent.end(), searchVector), serpent.end());
	return taille;
}

void Serpent::grandirSerpent(size_t taille, double pourcentage) {
	serpent.resize(size_t(serpent.size() + size_t(double(taille) * pourcentage)),
						serpent.back());
}


void Serpent::deplacerSerpent() {
	vector<int> temp;

	temp = serpent.front();

	shift_right(serpent.begin(), serpent.end(), 1);

	serpent.front() = temp;

	if (abs(pommeX - getTeteX()) > abs(pommeY - getTeteY())) {
		if (pommeX > getTeteX())
			serpent.front()[0] += 1;
		else
			serpent.front()[0] -= 1;
	} else {
		if (pommeY > getTeteY())
			serpent.front()[1] += 1;
		else
			serpent.front()[1] -= 1;
	}
}


bool Serpent::serpentMangeSerpent(vector<Serpent> &v) {
	bool serpKill, serpCoup;

	//Tri des serpents par coordonnées pour éviter de parcourir tous le tableau à chaque fois
	std::sort(v.begin(), v.end());

	for (Serpent &serpent1: v) {
		serpKill = false;
		serpCoup = false;

		for (Serpent &serpent2: v) {

			if (serpent2.getSerpentID() !=
				 serpent1.getSerpentID()) { //Evite qu'un serpent se bouffe lui même

				if (serpent1.getTeteX() == serpent2.getTeteX() and
					 serpent1.getTeteY() == serpent2.getTeteY()) {

					if (serpent1.getSerpentSize() >= serpent2.getSerpentSize()) {

						serpent1.grandirSerpent(serpent2.getSerpentSize(), 0.6);
						cout << serpent1.getSerpentID() << " killed "
							  << serpent2.getSerpentID() << endl;

						v.erase(find(v.cbegin(), v.cend(), serpent2));

						serpKill = true;
					} else {
						serpent2.grandirSerpent(serpent1.getSerpentSize(), 0.6);
						cout << serpent2.getSerpentID() << " killed "
							  << serpent1.getSerpentID() << endl;

						v.erase(find(v.cbegin(), v.cend(), serpent1));

						serpKill = true;
					}
				}
				if (serpKill)//passe au prochain serpent
					break;
				else { //
					for (vector<int> &coords: serpent2.getSerpent()) {
						if (serpent1.getTeteX() == coords.at(0) and
							 serpent1.getTeteY() == coords.at(1)) {
							size_t taille = serpent2.couperSerpent(coords);
							serpent1.grandirSerpent(taille, 0.4);
							serpCoup = true;
							break;
						}
					}
				}
			}
			if (serpCoup)
				break;
		}

		if (serpKill)
			break;
	}
	return serpKill;
}


bool Serpent::operator==(const Serpent &rhs) const {
	return ID == rhs.ID &&
			 pommeX == rhs.pommeX &&
			 pommeY == rhs.pommeY &&
			 valPomme == rhs.valPomme &&
			 surPomme == rhs.surPomme &&
			 serpent == rhs.serpent;
}

bool Serpent::operator!=(const Serpent &rhs) const {
	return !(rhs == *this);
}

bool Serpent::operator<(const Serpent &rhs) const {
	return getTeteX() < rhs.getTeteX() or
			 (getTeteX() == rhs.getTeteX() and getTeteY() < rhs.getTeteY());
}

