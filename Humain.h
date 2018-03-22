#ifndef HUMAIN_H_INCLUDED
#define HUMAIN_H_INCLUDED

#include <iostream>
#include <string>
#include "Entite.h"


class Medecin : public Entite
{

public:
    Medecin();
    void injection();

private:
  //  xxx

};


class Soldat : public Entite
{
public:
    Soldat();
     void mortier(Entite &target); // target represente le personnage choisi
     void lanceRoquette(Entite &target);
     void bouclier(Entite &target, int value);
     void attaque(Entite &target);


private:


};

#endif // HUMAIN_H_INCLUDED

