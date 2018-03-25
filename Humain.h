#ifndef HUMAIN_H_INCLUDED
#define HUMAIN_H_INCLUDED

#include <iostream>
#include <string>
#include "Entite.h"


class Medecin : public Entite
{

public:
    Medecin(int _pointsDeVie=20, int _resistance=0, int _pointsDeDegats=0, int _strength = 0,std::string _id="Medecin");
    void injection();
    void lanceSeringue(Entite &target);
    void lanceStethoscope(Entite &target);
    virtual void attaque(Entite &target);

private:


};


class Soldat : public Entite
{
public:
     Soldat(int _pointsDeVie=12, int _resistance=0, int _pointsDeDegats=0, int _strength = 0,std::string _id="Soldat");
     void mortier(Entite &target); // target represente le personnage choisi
     void lanceRoquette(Entite &target);
     //void bouclier(Entite &target, int value);
     virtual void attaque(Entite &target);


private:


};

#endif // HUMAIN_H_INCLUDED



