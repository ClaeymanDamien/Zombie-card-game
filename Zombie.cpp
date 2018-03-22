#include <iostream>
#include <string>
#include <cstdlib>
#include "Entite.h"
#include "Zombie.h"

using namespace std;

Zombie::Zombie() : Entite()
{

}

void Zombie::morsure(Entite &cible)
{
    cible.prendreDegats(60);
}

void Zombie::furie(Entite &cible)
{
    int nombreDeCoups = (rand() % 5) + 1;

    for(int i = 0; i < nombreDeCoups; i++)
    {
        cible.prendreDegats(18);
    }
}
