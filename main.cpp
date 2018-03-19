#include <iostream>
#include <string>
#include "gameloop.h"
#include "Card.h"
#include "Entite.h"
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
    Bouclier bouclier;
    Grenade grenade;
    grenade.effect(naruto,ennemis);
    bouclier.effect(sasuke);
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
    return 0;
}
