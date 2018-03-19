#include <iostream>
#include <string>
#include "Card.h"
#include "Entite.h"
using namespace std;

Card::Card(std::string _id, std::string _description, int _cost){
    id = _id;
    description = _description;
    cost = _cost;
}

Card::~Card(){

}

void Card::add_life(int value,Entite &target){
    target.m_pointsDeVie += value;
}

void Card::pull_life(int value, Entite attacker, Entite &defender){
    defender.m_pointsDeVie -= value+attacker.m_strength-defender.m_resistance;
}

void Card::add_resistance(int value, Entite &target){
    target.m_resistance += value;

}
void Card::add_strength(int value, Entite &target){
    target.m_strength += value;
    
}

void Card::play_card(bool _played){
    if(_played){
        played = _played;
    }
    else{
        played = false;
    }
}

void Lancepierre::effect(Entite attacker, Entite &defender){
    pull_life(dommage,attacker,defender);
}

Lancepierre::Lancepierre(std::string _id, std::string _description, int _cost, int _dommage){
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
}
void Bouclier::effect(Entite &target){
    add_resistance(resistance,target);
}
Bouclier::Bouclier (std::string _id, std::string _description, int _cost, int _resistance){

    id = _id;
    description = _description;
    cost = _cost;
    resistance = _resistance;

}


void Medkit::effect(Entite &target){
    add_life(life,target);
}

Medkit::Medkit(std::string _id, std::string _description, int _cost, int _life){
    id = _id;
    description = _description;
    cost = _cost;
    life = _life;
}

void Grenade::effect(){

}


