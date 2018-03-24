#include <iostream>
#include <string>
#include <cstdlib>
#include "Entite.h"
#include "Zombie.h"
#include "TypesDeZombies.h"

using namespace std;

Infecte::Infecte(int pointsDeVie, std::string id) : Zombie()
{
    m_pointsDeVie = pointsDeVie;
    m_id = id;
}

Infecte::~Infecte() {}

void Infecte::horde(Entite &cible)
{
    // horde : l'infecté a 1 chance sur 4 de faire apparaître une autre entité en renfort.

}

void Infecte::attaque(Entite &target)
{
    int choix = (rand() % 3) + 1;

    if(choix == 1)
    {
        morsure(target);
    }
    else if(choix == 2)
    {
        furie(target);
    }
    else
    {
        horde(target);
    }
}

/*//////////////////////////////////////////////////////////////////////*/

Brute::Brute(int pointsDeVie, std::string id) : Zombie()
{
    m_pointsDeVie = pointsDeVie;
    m_id = id;
}

Brute::~Brute() {}

void Brute::charge(Entite &target)
{
    // charge : la brute plaque violemment le joueur
    target.prendreDegats(9);
}

void Brute::attaque(Entite &target)
{
    int choix = (rand() % 3) + 1;

    if(choix == 1)
    {
        morsure(target);
    }
    else if(choix == 2)
    {
        furie(target);
    }
    else
    {
        charge(target);
    }
}

/*//////////////////////////////////////////////////////////////////////*/

Contagieux::Contagieux(int pointsDeVie, std::string id) : Zombie()
{
    m_pointsDeVie = pointsDeVie;
    m_id = id;
}

Contagieux::~Contagieux() {}

void Contagieux::empoisonnement(Entite &target)
{
    // empoisonnement : empoisonne la cible pendant 6 tours, celle-ci perd des points de vie à chaque tour
    target.m_empoisonnement += 6;
    cout << "Vous avez ete empoisonne de 6 points !" << endl;
}

void Contagieux::attaque(Entite &target)
{
    int choix = (rand() % 3) + 1;

    if(choix == 1)
    {
        morsure(target);
    }
    else if(choix == 2)
    {
        furie(target);
    }
    else
    {
        empoisonnement(target);
    }
}

/*//////////////////////////////////////////////////////////////////////*/

Exploseur::Exploseur(int pointsDeVie, std::string id) : Zombie()
{
    m_pointsDeVie = pointsDeVie;
    m_id = id;
}

Exploseur::~Exploseur() {}

void Exploseur::explosion(Entite &target)
{
    // explosion : le zombie se fait exploser, causant des dégâts variables
    int tirage = (rand() % 3) + 1;

    if(tirage == 1)
    {
        target.prendreDegats(10);
        m_pointsDeVie = 0;
        cout << "Le zombie a explosé ! Vous avez etes legerement blesse." << endl;
    }
    else if(tirage == 2)
    {
        target.prendreDegats(20);
        m_pointsDeVie = 0;
        cout << "Le zombie a explosé ! Vous avez ete moderement touche." << endl;
    }
    else
    {
        target.prendreDegats(30);
        m_pointsDeVie = 0;
        cout << "Le zombie a explosé ! Vous avez ete tres gravement touche." << endl;
    }
}

void Exploseur::attaque(Entite &target)
{
    int choix = (rand() % 3) + 1;

    if(choix == 1)
    {
        morsure(target);
    }
    else if(choix == 2)
    {
        furie(target);
    }
    else
    {
        explosion(target);
    }
}
