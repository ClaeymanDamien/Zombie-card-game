#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>
<<<<<<< HEAD
class Entite;
=======
#include "Entite.h"
>>>>>>> f3e2b39365b02d043087f7513c6fe7d6c1d9bf8a

class Card{

protected:
    std::string id;
    std::string description;
    int cost;
    bool played; //Si joué true;

public:

Card(std::string _id = "Inconnue", std::string _description = "Pas de description", int _cost = 1);
~Card();
void target_entity(Entite &cible);
void play_card(bool _played);
void add_defense();
void add_life(int value, Entite &target);
void pull_life();
void add_resistance();
void add_strength();


};

class Lancepierre : Card{
private:
    int dommage;
public:

void effect();
Lancepierre(std::string _id = "Lance Pierre", std::string _description = "Lance des cailloux aigises dans la gueule des zombies", int _cost = 1, int dommage = 5);

};

class Bouclier : Card{
private:
    int resistance;
public:
    void effect(Entite &target);
    Bouclier(std::string _id = "Bouclier Shield Donadey", std::string _description = "C'est une plaque abdominale de protection. Cela permet +1 de resistance", int _cost = 1, int _defense = 1 );
};

class Medkit : Card{
private:
    int life;
public:
    void effect(Entite &target);
    Medkit(std::string _id = "Medkit", std::string _description = "C'est de la poudre de Perlimpinpin permettra. +4 points de vie", int _cost = 1, int _life = 4);
};

class Grenade : Card{
private:
    int dommage;
public:
    void effect();
};

class Steroide : Card{
private:
    int strength;
public:
    void effect();
};


#endif // CARD_H_INCLUDED
