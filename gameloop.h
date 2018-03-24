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

void afficherui(Entite player,vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse);
void afficher_ennemis(vector<Entite*> ennemi);
void clearconsole();
void loading();
void afficherjoueur(Entite joueur);
void afficher(vector<Card*> main);
void draw(int nbr_cartes,vector<Card*> &deck,vector<Card*> &main);
void draw_with_care(int nbr_cartes,vector<Card*> &deck,vector<Card*> &main, vector <Card*> &defausse);
void deck_to_another(vector<Card*> &deck,vector<Card*> &anotherdeck);
void delay(float time_to_wait);
int prompt_card(int PA,vector<Card*> &main);
int prompt_card_choice(int PA,vector<Card*> &main);
void move_card(int choix_carte, vector<Card*> &deck,vector<Card*> &anotherdeck);
void copy_card(int choix_carte, vector<Card*> &deck,vector<Card*> &anotherdeck);
void create_card_choice(vector<Card*> &pool_of_cards,vector<Card*> &choice_of_cards);
void choix_nouvelle_carte(vector<Card*> &choice_of_cards, vector<Card*> &deck);
void move_entity(int choix_ennemi, vector<Entite*> &ennemis,vector<Entite*> &anotherennemis);
void card_played(int &PA,int choix_carte, Entite &player, vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse);
void create_ennemy_choice(vector<Entite*> &pool_of_ennemys, vector<Entite*> &choice_of_ennemys);
void ennemys_attack (Entite &player, vector<Entite *> &ennemis);
void ennemy_die (vector<Entite *> &ennemis);
void ennemy_phase (Entite &player, vector<Entite *> &ennemis);
void gameloop(Entite &player,vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse,vector<Card*> &pool_of_cards,vector<Card*> &choice_of_cards);


#endif // GAMELOOP_H_INCLUDED
