#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED
#include "Card.h"

class Entite
{
    friend class Card;
public:
    Entite();
    void statistiques() const;
    void prendreDegats(int pointsDeDegats);
    void mortier(Entite &cible);
    void injection();
    void bouclier();
    void concentration();

protected:
    int m_pointsDeVie;
    int m_pointsDeDegats;
    int m_defense;
    int m_force;
    int m_armure;
};

#endif // ENTITE_H_INCLUDED
