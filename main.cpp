#include <iostream>
#include <string>
#include "gameloop.h"
#include "Card.h"
#include "Entite.h"
#include "vector"
#include "gameloop.h"
#include "time.h"
#include "Humain.h"
#include "Zombie.h"
#include "TypesDeZombies.h"

using namespace std;

int main()
{


    vector<Card*> deck, defausse, main, choixcarte,poolcartes;
    vector<Entite*> ennemis,choixennemis,poolennemis;
    Entite player(70,0,0);

    srand (time(NULL));

    // Deck de base
    for (int i = 0; i < 5; i++){
        Lancepierre *lcp1=new Lancepierre;
        Bouclier *bcl1=new Bouclier;
        deck.push_back(lcp1);
        deck.push_back(bcl1);
    }

    // Pool d'ennemis

    Entite *enmy1 = new Medecin;
    poolennemis.push_back(enmy1);
    Entite *enmy2 = new Soldat;
    poolennemis.push_back(enmy2);
    Entite *enmy3 = new Infecte;
    poolennemis.push_back(enmy3);
    Entite *enmy4 = new Brute;
    poolennemis.push_back(enmy4);
    Entite *enmy5 = new Contagieux;
    poolennemis.push_back(enmy5);
    Entite *enmy6 = new Brute;
    poolennemis.push_back(enmy6);
    Entite *enmy7 = new Exploseur;
    poolennemis.push_back(enmy7);

    // Pool de cartes
    Lancepierre *chx1 = new Lancepierre;
    Medkit *chx2 = new Medkit;
//    Grenade *chx3 = new Grenade;
    Bouclier *chx4 = new Bouclier;
    Steroide *chx5 = new Steroide;
    poolcartes.push_back(chx1);
    poolcartes.push_back(chx2);
    //poolcartes.push_back(chx3);
    poolcartes.push_back(chx4);
    poolcartes.push_back(chx5);

    // Ajout des ennemis
    for (int i = 0; i < 2; i++){
        Entite *enmy1=new Entite;
        ennemis.push_back(enmy1);
    }

    while(1){
    create_card_choice(poolcartes,choixcarte);
    create_ennemy_choice(poolennemis,choixennemis);
    gameloop(player,choixennemis,deck,main,defausse,poolcartes,choixcarte);
    choix_nouvelle_carte(choixcarte,deck);
    }
    // Propose les cartes aux joueurs et il choisit
    return 0;
}
