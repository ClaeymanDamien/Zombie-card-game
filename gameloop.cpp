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

void afficher_ennemis(vector<Entite> ennemi){

    if (ennemi.size() == 0){
            cout << "Pas d'ennemi" <<endl;
    }else{
        for (unsigned int i = 0; i<ennemi.size();i++){
            cout << "- " << ennemi[i].m_id << endl << "HP: " << ennemi[i].m_pointsDeVie <<endl <<"Résistance: "<<ennemi[i].m_resistance << endl <<"Puissance: "<< ennemi[i].m_strength;
        }
    }
}

void afficherui(vector<Card> &deck,vector<Card> &main,vector<Card> &defausse){
cout <<endl<<"- Deck: "<< endl;
afficher(deck);
cout <<endl<<"- Main: "<< endl;
afficher(main);
cout <<endl<<"- Defausse: "<< endl;
afficher(defausse);
}

void if_deck_empty(){

}

void afficher(vector<Card> main){

    if (main.size() == 0){
            cout << "Vide" <<endl;
    }else{
        for (unsigned int i = 0; i<main.size();i++){
            cout << "- " << main[i].cost << " " << main[i].id <<endl;
        }
    }
}

void clearconsole(){

}

void lose(){

}


void draw(int nbr_cartes,vector<Card> &deck,vector<Card> &main){
     for (int i = 0; i < nbr_cartes; i++){
        int tirage = rand()%deck.size();
        //cout << tirage << deck[tirage]->id <<endl; // Debug, ligne fonctionnelle
        // copy (deck[tirage],deck[tirage],main.begin()); // Utilisable seulement si multiple copie
        main.push_back(deck[tirage]); // Ajoute la carte du deck � la main
        deck.erase(deck.begin()+tirage); // Supprime la carte du deck
    }
}

void deck_to_another(vector<Card> &deck,vector<Card> &anotherdeck){
draw(deck.size(),deck,anotherdeck);
}
