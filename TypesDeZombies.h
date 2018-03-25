#ifndef TYPESDEZOMBIES_H_INCLUDED
#define TYPESDEZOMBIES_H_INCLUDED
#include <iostream>
#include <string>
#include "Entite.h"
#include "Zombie.h"

class Infecte : public Zombie
{
public:
    Infecte(int pointsDeVie = 16, std::string id = "Zombie");
    ~Infecte();
    void horde(Entite &target);
    virtual void attaque(Entite &target);
};

class Brute : public Zombie
{
public:
    Brute(int pointsDeVie = 24, std::string id = "Zombie brutal");
    ~Brute();
    void charge(Entite &target);
    virtual void attaque(Entite &target);
};

class Contagieux : public Zombie
{
public:
    Contagieux(int pointsDeVie = 22, std::string id = "Zombie contagieux");
    ~Contagieux();
    void empoisonnement(Entite &target);
    virtual void attaque(Entite &target);
};

class Exploseur : public Zombie
{
public:
    Exploseur(int pointsDeVie = 21, std::string id = "Zombie explosif");
    ~Exploseur();
    void explosion(Entite &target);
    virtual void attaque(Entite &target);
};


#endif // TYPESDEZOMBIES_H_INCLUDED


