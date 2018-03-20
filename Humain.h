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
     void mortier(Entite &cible);

private:
    int m_armure;

};

#endif // HUMAIN_H_INCLUDED
