#include "Humain.h"
#include "Entite.h"
#include <iostream>

using namespace std;


Soldat::Soldat(): Entite()
{

}

Medecin::Medecin(): Entite()
{

}

void Soldat::mortier(Entite &cible)
{
    cible.prendreDegats(100);
}

void Medecin::injection()
{
    m_pointsDeVie += 50;

    if(m_pointsDeVie > 100)
    {
        m_pointsDeVie = 100;
    }
}
