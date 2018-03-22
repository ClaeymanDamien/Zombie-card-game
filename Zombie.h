#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED
#include <iostream>
#include <string>
#include "Entite.h"

class Zombie : public Entite
{
public:
    Zombie();
    void morsure(Entite &cible);
    void furie(Entite &cible);
};

#endif // ZOMBIE_H_INCLUDED
