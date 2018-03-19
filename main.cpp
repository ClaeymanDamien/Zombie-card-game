#include <iostream>
#include <string>
#include "gameloop.h"
#include "Card.h"
#include "Entite.h"
using namespace std;

int main()
{
    Entite naruto;
    naruto.statistiques();
    Card soin;
    soin.add_life(100,naruto);
    Medkit medkit;
    medkit.effect(naruto);
    naruto.statistiques();
    cout << "Welcome to Card Z" << endl;
    return 0;
}
