#include <iostream>
#include <string>
#include "gameloop.h"
#include "Card.h"
#include "Entite.h"
#include "vector"
#include "gameloop.h"
#include "time.h"
using namespace std;

int main()
{
    /*
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
    cout << endl; */

    vector<Card> deck, defausse, main, choixcarte;
    vector<Entite> ennemis,poolmonstre;

    srand (time(NULL));
    //int mana,tour;

    // Deck de base
    for (int i = 0; i < 5; i++){
        Card *lcp1=new Lancepierre;
        Card *bcl1=new Bouclier;
        deck.push_back(*lcp1);
        deck.push_back(*bcl1);
    }

    // Ajout des ennemis
    for (int i = 0; i < 5; i++){
        Entite *enmy1=new Entite;
        ennemis.push_back(*enmy1);
    }

    gameloop(ennemis,deck,main,defausse);

    return 0;
}
