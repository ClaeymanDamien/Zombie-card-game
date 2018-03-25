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
    cout << "La brute vous fonce dessus et vous envoie valser ! Vous reussissez a vous relever mais vous vous etes pris 9 points de degats" << endl;
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
    m_empoisonnement = 6;
    cout << "Le contagieux vous empoisonne avec un nuage toxique, vous etes intoxique ! Vous perdrez des points de vie à chaque tours." << endl;
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
        cout << "Le zombie a implosé ! Vous avez etes legerement blesse, vous perdez 10 points de vie." << endl;
    }
    else if(tirage == 2)
    {
        target.prendreDegats(20);
        m_pointsDeVie = 0;
        cout << "Le zombie a implosé ! Vous avez ete gravement touche, vous perdez 20 points de vie." << endl;
    }
    else
    {
        target.prendreDegats(30);
        m_pointsDeVie = 0;
        cout << "Le zombie a implosé ! Vous vous etes pris le souffle de l'explosion, vous perdez 30 points de vie." << endl;
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
