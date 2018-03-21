#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include "Entite.h"
#include "Card.h"
#include <iostream>
#include <algorithm> // std::move (ranges)
#include <utility> // std::move (objects)
#include <string>
#include <vector> // std

using namespace std;

void afficherui(vector<Entite> &ennemis,vector<Card> &deck,vector<Card> &main,vector<Card> &defausse);
void afficher_ennemis(vector<Entite> ennemi);
void clearconsole();
void loading();
void afficher(vector<Card> main);
void draw(int nbr_cartes,vector<Card> &deck,vector<Card> &main);
void deck_to_another(vector<Card> &deck,vector<Card> &anotherdeck);
void delay(float time_to_wait);
int prompt_card(int PA,vector<Card> &main);
void move_card(int choix_carte, vector<Card> &deck,vector<Card> &anotherdeck);
void card_played(int &PA,int choix_carte, int choix_ennemi, vector<Entite> &ennemis,vector<Card> &deck,vector<Card> &main,vector<Card> &defausse);
void gameloop(vector<Entite> &ennemis,vector<Card> &deck,vector<Card> &main,vector<Card> &defausse);


#endif // GAMELOOP_H_INCLUDED
