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
    Entite player(100,0,0); // Le joueur démarre avec 100HP

    srand (time(NULL));


    init_game(player,choixennemis,poolennemis,deck,main,defausse,poolcartes,choixcarte);

    while(1){
    create_card_choice(poolcartes,choixcarte);
    create_ennemy_choice(poolennemis,choixennemis);
    gameloop(player,choixennemis,deck,main,defausse,poolcartes,choixcarte);
    choix_nouvelle_carte(choixcarte,deck);
    empty_card_choice(choixcarte);


    }
    // Propose les cartes aux joueurs et il choisit

    return 0;
}
