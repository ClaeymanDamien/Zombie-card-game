#include <iostream>
#include <string>
#include <cstdlib>
#include "Entite.h"
#include "Zombie.h"

using namespace std;

Zombie::Zombie() : Entite()
{

}

void Zombie::morsure(Entite &target)
{
    target.prendreDegats(6);
    cout << "Le zombie vous a mordu ! Vous vous prenez 6 points de degats, mais par chance ca saigne pas." << endl;
}

void Zombie::furie(Entite &target)
{
    int nombreDeCoups = (rand() % 5) + 1;

    for(int i = 0; i < nombreDeCoups; i++)
    {
        target.prendreDegats(2);
    }
    cout << "Le zombie vous a retame, vous avez ete touche " << nombreDeCoups << " fois." << endl;
}

