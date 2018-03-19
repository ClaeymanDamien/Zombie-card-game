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

void Card::play_card(bool _played){
    if(_played){
        played = _played;
    }
    else{
        played = false;
    }
}

void Lancepierre::effect(){
    //pull_life();
}

void Bouclier::effect(){
    //add_resistance();
}

void Medkit::effect(){
    //add_life();
}

void Grenade::effect(){

}


