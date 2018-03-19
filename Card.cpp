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
<<<<<<< HEAD
void Card::pull_life(int value, Entite attacker, Entite &defender){
    defender.m_pointsDeVie -= value+attacker.m_force-defender.m_defense;
=======
void Card::add_resistance(int value, Entite &target){
    target.m_defense += value;
>>>>>>> 05cc0c1994b60f518aa1d120a9e706154bafee44
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

<<<<<<< HEAD
Lancepierre::Lancepierre(std::string _id, std::string _description, int _cost, int _dommage){
    id = _id;
    description = _description;
    cost = _cost;
    dommage = _dommage;
}
void Bouclier::effect(){
    //add_resistance();
=======
Bouclier::Bouclier (std::string _id, std::string _description, int _cost, int _defense){
    
    id = _id;
    description = _description;
    cost = _cost;
    defense = _defense;
>>>>>>> 05cc0c1994b60f518aa1d120a9e706154bafee44
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


