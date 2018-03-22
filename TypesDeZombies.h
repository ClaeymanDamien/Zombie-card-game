#ifndef TYPESDEZOMBIES_H_INCLUDED
#define TYPESDEZOMBIES_H_INCLUDED
#include <iostream>
#include <string>
#include "Entite.h"
#include "Zombie.h"

class Infecte : public Zombie
{
public:
    Infecte();
    void horde(Entite &cible);
};

class Brute : public Zombie
{
public:
    Brute();
    void charge(Entite &cible);
};

class Contagieux : public Zombie
{
public:
    Contagieux();
    void empoisonnement(Entite &cible);
};

class Exploseur : public Zombie
{
public:
    Exploseur();
    void explosion(Entite &cible);
};


#endif // TYPESDEZOMBIES_H_INCLUDED
