/*
  ---------------------------------------------------------------------------
  Fichier     : calendrier.cpp
  Nom du labo : Labo 5 - Crible Eratosthène
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago
  Date        : 15.11.2022
  But         : Librairie qui contient les fonctions permettant de créer un tableau, le cribler et trouver les
                valeurs premières du tableau.

  Remarque(s) : 0 et 1 ne sont pas premiers dans notre cas.

  Compilateur : Mingw-w64 g++ 12.2.0
  ---------------------------------------------------------------------------
*/

#include "tableau.h"

using namespace std;

#define SAUT_DE_LIGNE    cout << endl

//*******************************************************************************************************************

// nom         creerTableau
// but         Crée un tableau de characteres 'O' selon la taille attribuée lors de l'appel de la fonction
//
// param       int derniereValeureTableau
// return      vector<char> Tableau avec x nombres de charactères 'O'
// exception   n/a
vector<char> creerTableau(int valeurTableau){

   //Crée un tableau (vector<char>) de capacité égale à la valeure entrée en paramètre
   vector<char> tableau (valeurTableau);

   //Transforme toutes les valeurs du tableau en caractères 'O'
   for(char &i : tableau){
         i = 'O';
   }

   return tableau;
}

//*******************************************************************************************************************

// nom         criblerTableau
// but         Va vérifier chaque position su tablea, si elle est d'ite impaire, le charcatère 'O' sera remplacé par
//             un 'X'. Exception pour la postion 0 et 1
//
// param       vector<char> Tableau remplis avec x caractères 'O'
// return      vector<char> Tableau avec x nombres de caractères 'O' et les positions impaires
// exception   n/a
vector<char> criblerTableau(vector<char> tableau) {

   //Parcours le tableau à partir de la 2ème position
   //Pour chaque position, vérifie si elle est divisible par le diviseur actuel, si c'est le cas, la valeure à la
   //position x sera remplacée par le caractère 'X'
   for(int diviseur = 2; diviseur < tableau.size(); ++diviseur){
      for(int dividende = diviseur + 1; dividende < tableau.size(); ++dividende) {
         if (!(dividende %  diviseur) and tableau[dividende] != 'X') {
            tableau[dividende] = 'X';
         }
      }

   }

   //Définit la position 0 et 1 avec le caractère 'X', ces valeurs ne sont pas censée être impaires.
   tableau[0] = tableau[1] = 'X';

   return tableau;
}

//*******************************************************************************************************************

// nom         recupererNombresPremiers
// but         Scanne un tableau recu de caractères 'O' et 'X', si la position du tableau est 'X', stocke sa position
//             dans un tableau nommé "nombresPaires" et le retourne
//
// param       int derniereValeureTableau
// return      vector<char> Tableau avec x nombres de charactères 'O'
// exception   n/a
vector<int> recupererNombresPremiers(const vector<char>& tableau){

   //Création d'un tableau (vector<int>) de capacité 0
   vector<int> nombresPaires;

   //Vérifie chaque valeure du tableau à partir de la 2ème position (0 et 1 ne doivent pas être inclus)
   // Si la postion est églae à 'X', enregistre la valeure dans le tableau nombre impaires et augmente la capacité de
   // celui-ci en conséquance
   for(int nombreActuel = 2; nombreActuel < tableau.size(); ++nombreActuel){
      if(tableau[nombreActuel] == 'O'){
         nombresPaires.push_back(nombreActuel);
      }
   }

   return nombresPaires;
}







