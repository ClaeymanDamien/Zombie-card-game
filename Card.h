#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>
#include "Entite.h"

class Card{
protected:
    std::string id;
    std::string description;
    int cost;
    bool played; //Si joué true;

public:

Card(std::string _id = "Inconnue", std::string _description = "Pas de description", int _cost = 1);
~Card();
void target_entity();
void play_card(bool _played); //
void add_defense();
void add_life();
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
    void effect();

};

class Medkit : Card{
private:
    int life;
public:
    void effect();
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
