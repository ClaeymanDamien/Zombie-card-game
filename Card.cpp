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
void Card::effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const
{

};

void Card::add_life(int value,Entite &target) const{
    target.m_pointsDeVie += value;
}

void Card::pull_life(int value, Entite &attacker, Entite *defender) const{
    defender->m_pointsDeVie -= value+attacker.m_strength-defender->m_resistance;
}

void Card::add_resistance(int value, Entite &target) const{
    target.m_resistance += value;
}

/*
void Card::damage_zone(int value, Entite attacker, std::vector<Entite*> &defenders) const{
    for(unsigned int i=0; i<defenders.size(); i++){
        pull_life(value,attacker,&defenders[i]);
    }
}
*/
void Card::add_strength(int value, Entite &target) const{
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

void Lancepierre::effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const {
    pull_life(dommage,attacker,defender);
}

Lancepierre::Lancepierre(std::string _id, std::string _description, int _cost, int _dommage, int _target_type){
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
    target_type = _target_type;
}

Lancepierre::~Lancepierre(){

}

void Bouclier::effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const {
    add_resistance(resistance,attacker);
}

Bouclier::Bouclier (std::string _id, std::string _description, int _cost, int _resistance, int _target_type){

    id = _id;
    description = _description;
    cost = _cost;
    resistance = _resistance;
    target_type = _target_type;

}

Bouclier::~Bouclier(){

}

void Medkit::effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const {
    add_life(life,attacker);
}

Medkit::Medkit(std::string _id, std::string _description, int _cost, int _life, int _target_type){
    id = _id;
    description = _description;
    cost = _cost;
    life = _life;
    target_type = _target_type;
}

Medkit::~Medkit(){

}
/*
void Grenade::effect(Entite &attacker, Entite &defender,vector<Entite*> &ennemis) const {
    damage_zone(dommage, attacker, ennemis);
}

Grenade::Grenade(std::string _id, std::string _description, int _cost, int _dommage, int _target_type){
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
    target_type = _target_type;
}

Grenade::~Grenade(){

}
*/
void Steroide::effect(Entite &attacker, Entite *defender,vector<Entite*> &ennemis) const {
    add_strength(strength, attacker);
}

Steroide::Steroide(std::string _id, std::string _description, int _cost, int _strength, int _target_type){
    id = _id;
    description = _description;
    cost = _cost;
    strength = _strength;
    target_type = _target_type;
}

Steroide::~Steroide(){

}
