#include <iostream>
#include <algorithm> // std::move (ranges)
#include <utility> // std::move (objects)
#include <string>
#include <vector> // std
#include <time.h>
#include "Card.h"
#include "Entite.h"


using namespace std;

Card::Card(std::string _id, std::string _description, int _cost) //Constructeur de Card
{
    id = _id;
    description = _description;
    cost = _cost;
}

Card::~Card()
{

}

//Les méthodes que pourront utiliser les classes Card et les classes filles de Card
int Card::nbr_random(int min_nbr, int max_nbr) const //Génération d'un nombre random
{
    srand(time(NULL));
    return (rand() % (max_nbr - min_nbr + 1)) + min_nbr;
}


void Card::effect(Entite &attacker, Entite *defender) const //Méthode effect pour utiliser le polymorphise sur les classe fille
{

};

void Card::add_life(int value,Entite &target) const //Ajout de vie à une entité
{
    if (target.m_pointsDeVie+value <= 100){ //Sécurisation pour ne pas dépasser les 100 points de vie
        target.m_pointsDeVie += value;
    }else{
        target.m_pointsDeVie  = 100;
    }

}

void Card::pull_life(int value, Entite &attacker, Entite *defender) const //Retire de la vie à une entité
{   //Sécurisation pour pas avoir une vie inférieur à 0
    if(defender->m_pointsDeVie - (value+attacker.m_strength-defender->m_resistance) >0){ //Sécurisation pour pas avoir une vie inférieur à 0
        defender->m_pointsDeVie -= value+attacker.m_strength-defender->m_resistance;
    }else{
        defender->m_pointsDeVie = 0;
    }
}

void Card::add_resistance(int value, Entite &target) const //Ajout de résistance
{
    target.m_resistance += value;
}

void Card::add_strength(int value, Entite &target) const //Ajout de puissance
{
    target.m_strength += value;
}


void Card::play_card(bool _played) //Savoir si une carte a été joué
{
    if(_played)
    {
        played = _played;
    }
    else
    {
        played = false;
    }

}

//Méthode de la carte Lance pierre
void Lancepierre::effect(Entite &attacker, Entite *defender) const //Effet du lance pierre
{
    pull_life(dommage,attacker,defender);
    cout << "Attention, Lancer de pierre" << endl;
}

//Constructeur lance pierre
Lancepierre::Lancepierre(std::string _id, std::string _description, int _cost, int _dommage, int _target_type)
{
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
    target_type = _target_type;
}
//Destructeur lance pierre
Lancepierre::~Lancepierre()
{

}

//Méthode de la carte Bouclier
void Bouclier::effect(Entite &attacker, Entite *defender) const
{
    add_resistance(resistance,attacker);
    cout << "Il est pas mal le bouclier" << endl;
}

Bouclier::Bouclier (std::string _id, std::string _description, int _cost, int _resistance, int _target_type)
{

    id = _id;
    description = _description;
    cost = _cost;
    resistance = _resistance;
    target_type = _target_type;

}

Bouclier::~Bouclier()
{

}

//Méthode de la carte Medkit
void Medkit::effect(Entite &attacker, Entite *defender) const
{
    add_life(life,attacker);
    cout << "Hop, un petit boost" << endl;
}

Medkit::Medkit(std::string _id, std::string _description, int _cost, int _life, int _target_type)
{
    id = _id;
    description = _description;
    cost = _cost;
    life = _life;
    target_type = _target_type;
}

Medkit::~Medkit()
{

}

//Méthode de la carte Steroide
void Steroide::effect(Entite &attacker, Entite *defender) const
{
    add_strength(strength, attacker);
    cout << "Miam c'est bon les steroides" << endl;
}

Steroide::Steroide(std::string _id, std::string _description, int _cost, int _strength, int _target_type)
{
    id = _id;
    description = _description;
    cost = _cost;
    strength = _strength;
    target_type = _target_type;
}

Steroide::~Steroide()
{

}

//Méthode de la carte Sniper
void Sniper::effect(Entite &attacker, Entite *defender) const
{
    if (nbr_random(0,2)<2) //Savoir si le jouer a atteint sa cible, avec un taux de 66%
    {
        pull_life(dommage,attacker,defender);
        cout << "Headshot ! Tu viens de retirer 13 points" << endl;
    }
    else
    {
        cout << "Tu as manque ta cible" << endl;
    }
}

Sniper::Sniper(std::string _id, std::string _description, int _cost, int _dommage, int _target_type)
{
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
    target_type = _target_type;
}

Sniper::~Sniper()
{

}

//Méthode de la carte Matraque
void Matraque::effect(Entite &attacker, Entite *defender) const
{
    for(int i=0; i<6; i++) //On donne 6 coups de matraque à l'adversaire
    {
        pull_life(dommage,attacker,defender);
        cout << i+1 << " ";
        clock_t endtime=clock()+(0.4*CLOCKS_PER_SEC); // Temps d'attendre pour afficher le message
        while(clock()<endtime);
    }
    cout << "coups de matraque !" << endl;
}

Matraque::Matraque(std::string _id, std::string _description, int _cost, int _dommage, int _target_type)
{
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
    target_type = _target_type;
}

Matraque::~Matraque()
{

}

//Méthode de la carte Poison
void Poison::effect(Entite &attacker, Entite *defender) const
{
    defender->m_empoisonnement += dommage;
    cout << "L'ennemi est empoisonne" << endl;
}

Poison::Poison(std::string _id, std::string _description, int _cost, int _dommage, int _target_type)
{
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
    target_type = _target_type;
}

Poison::~Poison()
{

}

//Méthode de la carte Acide
void Acide::effect(Entite &attacker, Entite *defender) const
{
    pull_life(dommage,attacker,defender); //On inflige des dommages à l'adversaire
    attacker.m_empoisonnement += poison; //Mais le joueur se fait empoisonner
    cout << "L'ennemie est entrain de fondre ! Il perd:" << dommage << "points de vie mais tu es empoisonne" << endl;

}

Acide::Acide(std::string _id, std::string _description, int _cost, int _dommage, int _poison, int _target_type)
{
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
    target_type = _target_type;
    poison = _poison;
}

Acide::~Acide()
{

}
