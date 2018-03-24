#include "Entite.h"
#include <iostream>

using namespace std;

Entite::Entite(int _pointsDeVie, int _resistance, int _pointsDeDegats, int _strength,string _id, int _empoisonnement)  //m_pointsDeVie(100), m_resistance(0), m_pointsDeDegats(0), m_strength(0)
{
    m_pointsDeVie = _pointsDeVie;
    m_resistance = _resistance;
    m_pointsDeDegats = _pointsDeDegats;
    m_strength = _strength;
    m_id = _id;
    m_empoisonnement = _empoisonnement;
}

void Entite::statistiques() const
{
    cout << "PV : " << m_pointsDeVie << " R : " << m_resistance << " F : " << m_strength  <<endl;
}

void Entite::prendreDegats(int pointsDeDegats)
{
    m_pointsDeVie -= pointsDeDegats;

    if(m_pointsDeVie < 0)
    {
        m_pointsDeVie = 0;
    }
}


void Entite::bouclier()
{

}

void Entite::concentration()
{

}
