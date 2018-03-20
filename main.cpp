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

    Entite zombie, rampant, infecte;
    vector<Entite> ennemis;
    Entite *kakashi = new Entite;
    ennemis.push_back(*kakashi);
    Entite *sakura = new Entite;
    ennemis.push_back(*sakura);
    Entite *lee = new Entite;
    ennemis.push_back(*lee);

    cout << "zombie: ";
    zombie.statistiques();
    cout << endl;
    cout << "rampant: ";
    rampant.statistiques();
    cout << endl;
    cout << "infecte: ";
    infecte.statistiques();
    cout << endl;


    cout << "Les ennemis: " <<endl;
    ennemis[0].statistiques();
    cout << endl;
    ennemis[1].statistiques();
    cout <<endl;
    ennemis[2].statistiques();
    cout << endl;

    Medkit medkit;
    medkit.effect(zombie);
    Lancepierre lancepierre;
    lancepierre.effect(zombie,rampant);
    Steroide steroide;
    steroide.effect(rampant);
    Bouclier bouclier;
    bouclier.effect(rampant);
    Grenade grenade;
    grenade.effect(zombie,ennemis);
    lancepierre.effect(infecte, zombie);

    cout << "zombie: ";
    zombie.statistiques();
    cout << endl;
    cout << "rampant: ";
    rampant.statistiques();
    cout << endl;
    cout << "infecte: ";
    infecte.statistiques();
    cout << endl;
    cout << "Les ennemis: " <<endl;
    ennemis[0].statistiques();
    cout << endl;
    ennemis[1].statistiques();
    cout <<endl;
    ennemis[2].statistiques();
    cout << endl;

    cout << "Welcome to Card Z" << endl;

    vector<Card*> deck, defausse, main;

    for (int i = 0; i < 5; i++){
        Card* lcp1=new Lancepierre();
        Card* bcl1=new Bouclier;
        deck.push_back(lcp1);
        deck.push_back(bcl1);
    }

    vector<Entite*> Ennemis; // Liste des ennemis

    //Entite* player; // Liste des joueurs

    // Problème ici, affichage fonctionne, mais pas les transferts d'un tas à l'autre, pb de pointeurs probablement
    draw(5,deck,main);
    afficher(main);
    afficher(deck);
    hand_to_cemetary(main,defausse);
    afficher(defausse);

}
