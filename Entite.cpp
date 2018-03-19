#include "Entite.h"
#include <iostream>

using namespace std;

Entite::Entite() : m_pointsDeVie(100), m_defense(0), m_force(0)
{

}

void Entite::statistiques() const
{
    cout << "PV : " << m_pointsDeVie << endl;
}

void Entite::prendreDegats(int pointsDeDegats)
{
    m_pointsDeVie -= pointsDeDegats;

    if(m_pointsDeVie < 0)
    {
        m_pointsDeVie = 0;
    }
}

void Entite::mortier(Entite &cible)
{
    cible.prendreDegats(100);
}

void Entite::injection()
{
    m_pointsDeVie += 50;

    if(m_pointsDeVie > 100)
    {
        m_pointsDeVie = 100;
    }
}

void Entite::bouclier()
{

}

void Entite::concentration()
{

}
