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
void afficherui();
void clearconsole();
void afficher(std::vector<Card*> main);
void hand_to_cemetary(std::vector<Card*> main,std::vector<Card*> defausse);
void draw(int nbr_cartes,std::vector<Card*> deck,std::vector<Card*> main);
void to_cemetery();


#endif // GAMELOOP_H_INCLUDED
