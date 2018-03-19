#include "Entite.h"
#include "Card.h"
#include "gameloop.h"
#include <iostream>
#include <algorithm> // std::move (ranges)
#include <utility> // std::move (objects)
#include <string>
#include <vector> // std



using namespace std;
/*
void gameloop(){
afficherui();
draw(5);
clearconsole();
}
*/

// FONCTIONS
void afficherui(){

}

void afficher(vector<Card*> main){
    cout << "Main du joueur:" << endl;
        for (unsigned int i = 0; i<main.size();i++){
            cout << "- " << main[i]->cost << " " << main[i]->id <<endl;
        }
}

void clearconsole(){

}

void lose(){

}

void hand_to_cemetary(vector<Card*> main,vector<Card*> defausse){
    copy (main.begin(),main.end(),defausse.begin()); //
    main.clear();
}


void draw(int nbr_cartes,vector<Card*> deck,vector<Card*> main){
     for (int i = 0; i < nbr_cartes; i++){
        int tirage = rand()%deck.size();
        //cout << tirage << deck[tirage]->id <<endl; // Debug, ligne fonctionnelle
        // copy (deck[tirage],deck[tirage],main.begin()); // Utilisable seulement si multiple copie
        main.push_back(deck[tirage]); // Ajoute la carte du deck � la main
        deck.erase(deck.begin()+tirage); // Supprime la carte du deck
    }
}


void to_cemetery(){}

