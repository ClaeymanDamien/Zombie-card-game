#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED
#include "Card.h"

class Entite
{
    friend class Card;
public:
    Entite(int _pointsDeVie=100, int _resistance=0, int _pointsDeDegats=0, int _strength = 0);
    void statistiques() const;
    void prendreDegats(int pointsDeDegats);
    void bouclier();
    void concentration();

protected:
    int m_pointsDeVie;
    int m_pointsDeDegats;
    int m_resistance;
    int m_strength;
};

#endif // ENTITE_H_INCLUDED
