#include "Entity.h"
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Deck cartes
vector<Card> deck[Tirer,Tirer,Tirer,Tirer,Tirer,Armure,Armure,Armure,Armure,Armure];

// Main du joueur
vector<Card> main;

// Défausse
vector<Card> defausse;

vector<Entity> Ennemis;

Entity Player;

Entity player;

void gameloop(){
afficherui();
draw(5);
clearconsole();
}

void afficherui(){

}

void affichermain(){

}

void clearconsole(){

}

void lose(){

}

void draw(int nbr_cartes){

}


