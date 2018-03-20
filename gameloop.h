#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include "Entite.h"
#include "Card.h"
#include <iostream>
#include <algorithm> // std::move (ranges)
#include <utility> // std::move (objects)
#include <string>
#include <vector> // std

void gameloop();
void afficherui(std::vector<Card> &deck,std::vector<Card> &main,std::vector<Card> &defausse);
void afficher_ennemis(std::vector<Entite> ennemi);
void clearconsole();
void afficher(std::vector<Card> main);
void draw(int nbr_cartes,std::vector<Card> &deck,std::vector<Card> &main);
void deck_to_another(std::vector<Card> &deck,std::vector<Card> &anotherdeck);


#endif // GAMELOOP_H_INCLUDED
