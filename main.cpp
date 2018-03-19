#include <iostream>
#include <string>
#include "gameloop.h"
#include "Card.h"
#include "Entite.h"
using namespace std;

int main()
{
    Entite naruto, sasuke;
    cout << "Naruto: ";
    naruto.statistiques();
    cout << endl;
    cout << "sasuke: ";
    sasuke.statistiques();
    cout << endl;
    Medkit medkit;
    medkit.effect(naruto);
    Lancepierre lancepierre;
    lancepierre.effect(naruto,sasuke);
    Bouclier bouclier;
    bouclier.effect(sasuke);
    cout << "Naruto: ";
    naruto.statistiques();
    cout << endl;
    cout << "sasuke: ";
    sasuke.statistiques();
    cout << endl;
    cout << "Welcome to Card Z" << endl;
    return 0;
}
