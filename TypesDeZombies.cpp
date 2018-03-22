#include <iostream>
#include <string>
#include <cstdlib>
#include "Entite.h"
#include "Zombie.h"
#include "TypesDeZombies.h"

using namespace std;

Infecte::Infecte() : Zombie()
{

}

void Infecte::horde(Entite &cible) // 1/4 de faire spawn un autre infecté
{

}

/*//////////////////////////////////////////////////////////////////////*/

Brute::Brute() : Zombie()
{

}

void Brute::charge(Entite &cible) // plaque violement
{
    cible.prendreDegats(85);
}

/*//////////////////////////////////////////////////////////////////////*/

Contagieux::Contagieux() : Zombie()
{

}

void Contagieux::empoisonnement(Entite &cible)
{

}

/*//////////////////////////////////////////////////////////////////////*/

Exploseur::Exploseur() : Zombie()
{

}

void Exploseur::explosion(Entite &cible)
{

}
