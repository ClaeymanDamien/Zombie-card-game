#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

Card::Card(std::string _id, std::string _description, int _cost){
    id = _id;
    description = _description;
    cost = _cost;
}
