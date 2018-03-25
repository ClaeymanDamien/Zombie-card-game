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

    init_game(player,choixennemis,poolennemis,deck,main,defausse,poolcartes,choixcarte);

    while(1){
    create_card_choice(poolcartes,choixcarte);
    create_ennemy_choice(poolennemis,choixennemis);
    gameloop(player,choixennemis,deck,main,defausse,poolcartes,choixcarte);
    choix_nouvelle_carte(choixcarte,deck);
    }
    // Propose les cartes aux joueurs et il choisit

    return 0;
}
