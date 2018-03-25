#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

class Entite;
class gameloop;

class Card
{
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
    int nbr_random(int min_nbr, int max_nbr) const;
    void message_delay(float nbr);
    void target_entity(Entite &cible);
    void play_card(bool _played);
    void add_life(int value, Entite &target) const;
    void pull_life(int value, Entite &attacker, Entite *defender) const;
    void add_resistance(int value, Entite &target) const;
    void add_strength(int value, Entite &target)const;
    virtual void effect(Entite &attacker, Entite *defender) const;


};

class Lancepierre :public Card
{
private:
    int dommage;
public:
Lancepierre(std::string _id = "Lance Pierre", std::string _description = "Inflige 6 points de degats a un ennemi", int _cost = 1, int _dommage = 6, int _target_type = 1);
virtual void effect(Entite &attacker, Entite *defender) const;
virtual ~Lancepierre();
};

class Bouclier :public Card
{
private:
    int resistance;
public:
    Bouclier(std::string _id = "Bouclier Shield Donadey", std::string _description = "Rajoutez-vous +1 de resistance ", int _cost = 1, int _resistance = 1, int _target_type = 0);
    virtual void effect(Entite &attacker, Entite *defender) const;
    virtual ~Bouclier();
};

class Medkit :public Card
{
private:
    int life;
public:
    Medkit(std::string _id = "Medkit", std::string _description = "Soignez vous de 8 points de vie", int _cost = 1, int _life = 8, int _target_type = 0);
    virtual void effect(Entite &attacker, Entite *defender) const;
    virtual ~Medkit();
};

class Steroide :public Card
{
private:
    int strength;
public:
    Steroide(std::string _id = "Steroidam", std::string _description = "Coach Damien de la salle te fait prendre +1 de force", int _cost = 1, int _strength = 1, int _target_type = 0);
    virtual void effect(Entite &attacker, Entite *defender) const;
    virtual ~Steroide();
};

class Sniper :public Card
{
private:
    int dommage;
public:
    Sniper(std::string _id = "Sniper", std::string _description = "Vous avez 66% chance de faire 13 degats à un ennemi", int _cost = 1, int _dommage = 13, int _target_type = 1);
    virtual void effect(Entite &attacker, Entite *defender) const;
    virtual ~Sniper();
};

class Matraque :public Card
{
private:
    int dommage;
public:
    Matraque(std::string _id = "Matraque", std::string _description = "Inflige 6 coups de matraques qui font 1 degat", int _cost = 1, int _dommage = 1, int _target_type = 1);
    virtual void effect(Entite &attacker, Entite *defender) const;
    virtual ~Matraque();
};

class Poison :public Card
{
private:
    int dommage;
public:
    Poison(std::string _id = "Poison", std::string _description = "Inflige 6 degats et -1 a chaque tour", int _cost = 2, int _dommage = 6, int _target_type = 1);
    virtual void effect(Entite &attacker, Entite *defender) const;
    virtual ~Poison();
};
class Acide :public Card
{
private:
    int dommage;
    int poison;
public:
    Acide(std::string _id = "Acide", std::string _description = "Inflige 20 degats mais tu attrapes 3 d'empoisonnement", int _cost = 2, int _dommage = 20, int _poison = 3, int _target_type = 1);
    virtual void effect(Entite &attacker, Entite *defender) const;
    virtual ~Acide();
};

#endif // CARD_H_INCLUDED
