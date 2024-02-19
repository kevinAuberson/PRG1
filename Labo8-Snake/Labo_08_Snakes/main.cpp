/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo 8 - Snake
  Auteur(s)   : Auberson Kevin - Surbeck Léon
  Date        : 11.01.2023
  But         : Programme principal qui gère l'interface graphique et appelle
                les fonctions nécessaire au bon fonctionnement du jeu.

  Remarque(s) : -

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <algorithm>
#include "terrain.h"
#include "serpents.h"
#include "annexe.h"

using namespace std;

int main(int argc, char *argv[]) {
	// Ces arguments sont nécessaire au bon fonctionnement de SDL sur Windows,
	// grâce aux 2 lignes suivantes les warning sont ignorés
	(void) argc;
	(void) argv;


	const int LARGEUR_MAX = 1200;
	const int LARGEUR_MIN = 50;
	const int HAUTEUR_MAX = 800;
	const int HAUTEUR_MIN = 50;
	const int SERPENT_MAX = 1000;
	const int SERPENT_MIN = 2;
	const int SDL_DELAY_MS = 10;
	const int SCALE = 2;

	int largeur = entreeUser(LARGEUR_MIN, LARGEUR_MAX, "largeur [");
	int hauteur = entreeUser(HAUTEUR_MIN, HAUTEUR_MAX, "hauteur [");
	auto nbreSerpents = size_t(entreeUser(SERPENT_MIN, SERPENT_MAX, "nbre snakes ["));
	bool appIsRunning = true;

	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(largeur * SCALE, hauteur * SCALE, SDL_WINDOW_SHOWN,
										 &window, &renderer);

	if (window == nullptr or renderer == nullptr) {
		cout << "SDL not ready ... quitting" << endl;
	}
	SDL_SetWindowTitle(window, "Bataille de serpents");
	SDL_RenderSetScale(renderer, SCALE, SCALE);

	Terrain terrain(hauteur, largeur, nbreSerpents);

	vector<Serpent> vecSerpent;

	terrain.creationSerpents(vecSerpent);

	while (appIsRunning) {


		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT) {
			appIsRunning = false;
			break;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);


		for (Serpent &serpent: vecSerpent) {
			{
				// Pour la nouvelle pomme, on réduit de 1 la larg/haut car le dernier pixel n'est pas visible
				if (serpent.trouverPomme())
					serpent.newPomme(aleatoire(largeur - 1),
										  aleatoire(hauteur - 1),
										  aleatoire(10));

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);


				for (const vector<int> &coords: serpent.getSerpent()) {
					SDL_RenderDrawPoint(renderer, coords.at(0), coords.at(1));
				}

				serpent.deplacerSerpent();

				SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderDrawPoint(renderer, serpent.getPommeX(), serpent.getPommeY());

			}

		}

		if (Serpent::serpentMangeSerpent(vecSerpent))terrain.reduireNbrSerpents();
		SDL_Delay(SDL_DELAY_MS);
		SDL_RenderPresent(renderer);

		if (terrain.getnbrSerpents() <= 1) {
			cout << "Le serpent : " << vecSerpent.front().getSerpentID() << " a gagne !"
				  << endl;
			cout << "Appuyez sur ENTER pour quitter ...";
			cin.ignore();
			appIsRunning = false;
		}
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return EXIT_SUCCESS;
}