#include <iostream>
#include <string>
#include "gameloop.h"
#include "Card.h"
#include "Entite.h"
#include "vector"
#include "gameloop.h"
using namespace std;

int main()
{

    Entite naruto, sasuke;
    vector<Entite> ennemis;
    Entite *kakashi = new Entite;
    ennemis.push_back(*kakashi);
    Entite *sakura = new Entite;
    ennemis.push_back(*sakura);
    Entite *lee = new Entite;
    ennemis.push_back(*lee);

    cout << "Naruto: ";
    naruto.statistiques();
    cout << endl;
    cout << "sasuke: ";
    sasuke.statistiques();
    cout << endl;
    cout << "Les ennemis: " <<endl;
    ennemis[0].statistiques();
    cout << endl;
    ennemis[1].statistiques();
    cout <<endl;
    ennemis[2].statistiques();
    cout << endl;

    Medkit medkit;
    medkit.effect(naruto);
    Lancepierre lancepierre;
    lancepierre.effect(naruto,sasuke);
    Steroide steroide;
    steroide.effect(sasuke);
    Bouclier bouclier;
    bouclier.effect(sasuke);
    Grenade grenade;
    grenade.effect(naruto,ennemis);

    cout << "Naruto: ";
    naruto.statistiques();
    cout << endl;
    cout << "sasuke: ";
    sasuke.statistiques();
    cout << endl;
    cout << "Les ennemis: " <<endl;
    ennemis[0].statistiques();
    cout << endl;
    ennemis[1].statistiques();
    cout <<endl;
    ennemis[2].statistiques();
    cout << endl;

    cout << "Welcome to Card Z" << endl;

    vector<Card> deck, defausse, main;

    for (int i = 0; i < 5; i++){
        Card *lcp1=new Lancepierre;
        Card *bcl1=new Bouclier;
        deck.push_back(*lcp1);
        deck.push_back(*bcl1);
    }

    vector<Entite> adversaires; // Liste des ennemis

    afficher(deck);
    //Entite* player; // Liste des joueurs

    // Edit by Damien CLAEYMAN (Fonctionnel)
    draw(5,deck,main);
    cout << "Ca marche: " << endl;
    afficher(deck);

    /*afficher(deck);
    hand_to_cemetary(main,defausse);
    afficher(defausse);*/

}
