#include "Entite.h"
#include "Card.h"
#include "gameloop.h"
#include <iostream>
#include <algorithm> // std::move (ranges)
#include <utility> // std::move (objects)
#include <string>
#include <vector> // std
#include <time.h>

using namespace std;


// FONCTIONS

void delay(float time_to_wait){
    clock_t endtime=clock()+(time_to_wait*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter
    while(clock()<endtime);
}

void loading(){
    cout << endl ;
    delay(0.5);
    cout << "." ;
    delay(0.5);
    cout << "." ;
    delay(0.5);
    cout << "." ;
    delay(0.5);
}

void afficher_ennemis(vector<Entite> ennemi){

    if (ennemi.size() == 0){
            cout << "Pas d'ennemi" <<endl;
    }else{
        for (unsigned int i = 0; i<ennemi.size();i++){
            cout << "- " << i+1 << " | Type: "<< ennemi[i].m_id << " HP: " << ennemi[i].m_pointsDeVie << " Res: "<<ennemi[i].m_resistance <<" Puiss: "<< ennemi[i].m_strength << endl;
        }
    }
    cout << "___________________________________________________________" << endl;
}

void afficherui(vector<Entite> &ennemis,vector<Card> &deck,vector<Card> &main,vector<Card> &defausse){
cout <<endl<<"- Ennemis: "<< endl;
afficher_ennemis(ennemis);
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
            cout << "- " << i+1 << " | Cout: " << main[i].cost << " " << main[i].id <<endl;
        }
    }
}

void clearconsole(){
system("cls");
}

void lose(){

}

void draw(int nbr_cartes,vector<Card> &deck,vector<Card> &main){
     for (int i = 0; i < nbr_cartes; i++){
        int tirage = rand()%deck.size();
        //cout << tirage << deck[tirage]->id <<endl; // Debug, ligne fonctionnelle
        // copy (deck[tirage],deck[tirage],main.begin()); // Utilisable seulement si multiple copie
        main.push_back(deck[tirage]); // Ajoute la carte du deck à la main
        deck.erase(deck.begin()+tirage); // Supprime la carte du deck
    }
}

void deck_to_another(vector<Card> &deck,vector<Card> &anotherdeck){
draw(deck.size(),deck,anotherdeck);
}

int prompt_card(int PA,vector<Card> &main){
    cout << endl << "Quelle carte allez vous jouer ? Il vous reste " << PA << " points d'action." << endl << "Votre choix: " ;
    int taille_main_max = main.size(),choix;
    cin >> choix;
    if (choix >= 0 && choix <= taille_main_max){
        return choix;
    } else {
    cout << endl << "Choix invalide !" << endl;
    prompt_card(PA, main);
    }
    return 0;
}

int prompt_entity(vector<Entite> &ennemis){
    cout << endl << "Quelle va etre votre cible ?" << endl << "Votre choix: " ;
    int taille_ennemis_max = ennemis.size(),choix;
    cin >> choix;
    if (choix >= 0 && choix <= taille_ennemis_max){
        return choix;
    } else {
    cout << endl << "Choix invalide !" << endl;
    prompt_entity(ennemis);
    }
    return 0;
}

// Pour bouger une carte d'un deck à l'autre
void move_card(int choix_carte, vector<Card> &deck,vector<Card> &anotherdeck){

    anotherdeck.push_back(deck[choix_carte]); // Ajoute la carte du deck � la main
    deck.erase(deck.begin()+choix_carte); // Supprime la carte du deck
}

// Grosse fonction à réfléchir avec damien, comment détecter le type de carte utilisée ?? Car si heal ou AOE, pas besoin de choisir une cible ! :D
void card_played(int &PA,int choix_carte, int choix_ennemi, vector<Entite> &ennemis,vector<Card> &deck,vector<Card> &main,vector<Card> &defausse){

PA = PA - main[choix_carte].cost;
move_card(choix_carte,main,defausse); // On trash la carte après l'avoir joué
}


// Gameloop finale

void gameloop(vector<Entite> &ennemis,vector<Card> &deck,vector<Card> &main,vector<Card> &defausse){
    int PA=3,choix_carte,choix_ennemi;

    // Démarrage de la partie
    afficherui(ennemis,deck,main,defausse);
    loading();
    draw(5,deck,main);
    clearconsole();

    // Début de la boucle de jeu
    while(PA > 0){
        afficherui(ennemis,deck,main,defausse);
        choix_carte=prompt_card(PA, main);
        // If card_type =! AOE =! HEAL =! BOOST
        choix_ennemi=prompt_entity(ennemis);
        card_played(PA,choix_carte,choix_ennemi,ennemis,deck,main,defausse);
        loading();
        clearconsole();

    }

}
