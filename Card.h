#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>

class Card{
protected:
    std::string id;
    std::string description;
    int cost;

public:

Card(std::string _id = "Inconnue", std::string _description = "Pas de description", int _cost = 1);
};

void target_entity();
void play_card();
void card_effect();

#endif // CARD_H_INCLUDED
