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
    cout << "Vous vous etes fait mordre légèrement." << endl;
}

void Zombie::furie(Entite &target)
{
    int nombreDeCoups = (rand() % 5) + 1;

    for(int i = 0; i < nombreDeCoups; i++)
    {
        target.prendreDegats(2);
    }
    cout << "Vous avez subis une ruade." << endl;
}
