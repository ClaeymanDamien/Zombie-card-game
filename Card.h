#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>

class Entite;


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
void pull_life(int value, Entite attacker, Entite &defender);
void add_resistance();
void add_strength();


};

class Lancepierre : Card{
private:
    int dommage;
public:

void effect(Entite attacker, Entite &defender);
Lancepierre(std::string _id = "Lance Pierre", std::string _description = "Lance des cailloux aigises dans la gueule des zombies", int _cost = 1, int _dommage = 6);

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
