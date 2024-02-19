/*
 -------------------------------------------------------------------------------------------------------------------
  Fichier     : serpents.h
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         : Prototypage des fonctions liées aux objets serpent.

  Remarque(s) : -

  Compilateur : Mingw-w64 g++ 12.2.0
 -------------------------------------------------------------------------------------------------------------------
*/

#ifndef LABO_08_SNAKES_SERPENTS_H
#define LABO_08_SNAKES_SERPENTS_H


#include <vector>

class Serpent {
public:

	/**
	 * Constructeur pour la classe Serpent
	 * @param ID            Le numéro du serpent
	 * @param x             La coordonnée X du point d'apparition du serpent entier
	 * @param y             La coordonnée Y du point d'apparition du serpent entier
	 * @param pommeX        La coordonnée X du point d'apparition de la pomme
	 * @param pommeY        La coordonnée Y du point d'apparition de la pomme
	 * @param valPomme      La valeur de la pomme
	 */
	Serpent(int ID, int x, int y, int pommeX, int pommeY, int valPomme);

	// Le [[nodiscard]] a du être ajouté pour éviter un warning de l'IDE

	[[nodiscard]] int getPommeX() const;

	[[nodiscard]] int getPommeY() const;

	[[nodiscard]] int getSerpentID() const;

	[[nodiscard]] int getTeteX() const;

	[[nodiscard]] int getTeteY() const;

	[[nodiscard]] std::size_t getSerpentSize() const;

	std::size_t couperSerpent(const std::vector<int> &searchVector);

	/**
	 * @return le vecteur du serpent, tous les couples de coordonnées de tout les points du serpent.
	 */
	std::vector<std::vector<int>> getSerpent();

	/**
	 * Fais grandir le serpent d'un pourcentage de la taille donnée
	 * @param taille      le size_t de la taille qu'il doit gagner
	 * @param pourcentage le pourcentage de taille qu'il doit gagner (en format compris entre 0 et 1, 50% = 0.5)
	 */
	void grandirSerpent(std::size_t taille, double pourcentage);

	bool trouverPomme();

	void newPomme(int newPommeX, int newPommeY, int newPommeVal);

	/**
	 * Décale les coordonnées et met à jour les coordonnées de la tête du serpent
	 * pour qu'il se dirige le plus rapidement possible à la pomme
	 */
	void deplacerSerpent();

	/**
	 * Vérifie la superposition des serpents
	 *  Si un serpent mord le corps d’un autre (tête sur corps),
	 *  ce dernier est coupé à cet endroit et 40% de la longueur coupée est ajoutée au serpent attaquant.
	 *  Si un serpent mord un autre par la tête (tête sur tête), le serpent le plus court meurt et 60%
	 *  de la longueur du serpent tué est ajoutée celle de l’attaquant.
	 * @param v Le vecteur contenant tous les serpents
	 * @return true si un serpent est tué et false si ce n'est pas le cas
	 */
	static bool serpentMangeSerpent(std::vector<Serpent> &v);

	// Permet de comparer deux objets serpents entre eux.
	bool operator==(const Serpent &rhs) const;

	bool operator!=(const Serpent &rhs) const;

	bool operator<(const Serpent &rhs) const;

private:
	int ID;
	int pommeX;
	int pommeY;
	int valPomme;
	bool surPomme = false;
	std::vector<std::vector<int>> serpent;
};


#endif //LABO_08_SNAKES_SERPENTS_H
