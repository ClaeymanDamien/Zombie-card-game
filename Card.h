#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

class Entite;
class gameloop;

class Card{

    friend class Entite;
    friend void afficher(std::vector<Card*> main);
    friend void card_played(int &PA,int choix_carte, Entite &player, vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse);
    friend void gameloop(Entite &player,vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse,vector<Card*> &pool_of_cards,vector<Card*> &choice_of_cards);


protected:

    bool played; //Si joue true;
    std::string id;
    std::string description;
    int cost;
    int target_type; //0 = buff, 1 = 1 attack one entite, 2 = AOE

public:

Card(std::string _id = "Inconnue", std::string _description = "Pas de description", int _cost = 1);
virtual ~Card();
void target_entity(Entite &cible);
void play_card(bool _played);
void add_life(int value, Entite &target) const;
void pull_life(int value, Entite &attacker, Entite *defender) const;
void add_resistance(int value, Entite &target) const;
//void damage_zone(int value, Entite attacker, std::vector<Entite*> &defenders) const;
void add_strength(int value, Entite &target)const;
virtual void effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const;


};

class Lancepierre :public Card{
private:
    int dommage;
public:
Lancepierre(std::string _id = "Lance Pierre", std::string _description = "Lance des cailloux aigises dans la gueule des zombies", int _cost = 1, int _dommage = 6, int _target_type = 1);
virtual void effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const;
virtual ~Lancepierre();

};

class Bouclier :public Card{
private:
    int resistance;
public:
    Bouclier(std::string _id = "Bouclier Shield Donadey", std::string _description = "C'est une plaque abdominale de protection. Cela permet +1 de resistance", int _cost = 1, int _resistance = 1, int _target_type = 0);
    virtual void effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const;
    virtual ~Bouclier();
};

class Medkit :public Card{
private:
    int life;
public:
    Medkit(std::string _id = "Medkit", std::string _description = "C'est de la poudre de Perlimpinpin permettra. +4 points de vie", int _cost = 1, int _life = 4, int _target_type = 0);
    virtual void effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const;
    virtual ~Medkit();
};
/*
class Grenade :public Card{
private:
    int dommage;
public:
    Grenade(std::string _id = "Grenade", std::string _description = "L'orgie du paradis. -5 points de vie a tous les ennemies", int _cost = 1, int _dommage = 5, int _target_type = 2);
    virtual void effect(Entite &attacker, Entite &defender,vector<Entite*> &ennemis) const;
    virtual ~Grenade();
};
*/
class Steroide :public Card{
private:
    int strength;
public:
    Steroide(std::string _id = "Steroidam", std::string _description = "Coach Damien de la salle te fait prendre de la masse. +1 de force", int _cost = 1, int _strength = 1, int _target_type = 0);
    virtual void effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const;
    virtual ~Steroide();
};


#endif // CARD_H_INCLUDED
