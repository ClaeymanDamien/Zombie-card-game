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

    // Création des paquets de carte et des "pools" d'entité
    vector<Card*> deck, defausse, main, choixcarte,poolcartes;
    vector<Entite*> ennemis,choixennemis,poolennemis;
    Entite player(100,0,0); // Le joueur démarre avec 100HP

    srand (time(NULL));

    // Initialisation des variables selon les règles mises en place
    init_game(player,choixennemis,poolennemis,deck,main,defausse,poolcartes,choixcarte);

    while(1){
     // Initialise les cartes aux joueurs qu'il gagne en fin de combat
    create_card_choice(poolcartes,choixcarte);
    // Initialise la pool d'ennemis
    create_ennemy_choice(poolennemis,choixennemis);
    // Réinitialise les différents ennemis que l'on peut rencontrer
    reinit_ennemy_pool(poolennemis);
    // Gameloop de combat
    gameloop(player,choixennemis,deck,main,defausse,poolcartes,choixcarte);
    // Propose les cartes aux joueurs qu'il gagne en fin de combat
    choix_nouvelle_carte(choixcarte,deck);
    // Vide le tableau généré
    empty_card_choice(choixcarte);
    }

    return 0;
}
