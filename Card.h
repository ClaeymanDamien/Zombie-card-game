#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>
#include <vector>

class Entite;


class Card{

protected:

    bool played; //Si joue true;

public:
/// En attendant, je les met en public
    std::string id;
    std::string description;
    int cost;


Card(std::string _id = "Inconnue", std::string _description = "Pas de description", int _cost = 1);
~Card();
void target_entity(Entite &cible);
void play_card(bool _played);
//void add_defense();
void add_life(int value, Entite &target);
void pull_life(int value, Entite attacker, Entite &defender);
void add_resistance(int value, Entite &target);
<<<<<<< HEAD
void damage_zone(int value, Entite attacker, std::vector<Entite> &defenders);
=======

void add_strength();
void damage_zone(int value, Entite attacker, std::vector<Entite> &defenders);

>>>>>>> 60e742fd536f6e5e7f07bd73e538024b90e034f5
void add_strength(int value, Entite &target);


};

class Lancepierre :public Card{
private:
    int dommage;
public:

void effect(Entite attacker, Entite &defender);
Lancepierre(std::string _id = "Lance Pierre", std::string _description = "Lance des cailloux aigises dans la gueule des zombies", int _cost = 1, int _dommage = 6);

};

class Bouclier :public Card{
private:
    int resistance;
public:
    void effect(Entite &target);
    Bouclier(std::string _id = "Bouclier Shield Donadey", std::string _description = "C'est une plaque abdominale de protection. Cela permet +1 de resistance", int _cost = 1, int _resistance = 1);
};

class Medkit :public Card{
private:
    int life;
public:
    void effect(Entite &target);
    Medkit(std::string _id = "Medkit", std::string _description = "C'est de la poudre de Perlimpinpin permettra. +4 points de vie", int _cost = 1, int _life = 4);
};

class Grenade :public Card{
private:
    int dommage;
public:
    void effect(Entite attacker,std::vector<Entite> &defenders);
    Grenade(std::string _id = "Grenade", std::string _description = "L'orgie du paradis. -5 points de vie à tous les ennemies", int _cost = 1, int _dommage = 5);
};

class Steroide :public Card{
private:
    int strength;
public:
    void effect(Entite &target);
    Steroide(std::string _id = "Steroidam", std::string _description = "Coach Damien de la salle te fait prendre de la masse. +1 de force", int _cost = 1, int _strength = 1);
};


#endif // CARD_H_INCLUDED
