#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED
#include "Card.h"
#include "string"
#include <vector>


class gameloop;

class Entite
{
    friend class Card;
    friend void afficher_ennemis(std::vector<Entite> ennemi);
public:
    Entite(int _pointsDeVie=100, int _resistance=0, int _pointsDeDegats=0, int _strength = 0,std::string _id="Zombie");
    void statistiques() const;
    void prendreDegats(int pointsDeDegats);
    void bouclier();
    void concentration();

    /// Devrait être en protected, je le met en public tant que c'est pas fix


protected:
    std::string m_id;
    int m_pointsDeVie;
    int m_pointsDeDegats;
    int m_resistance;
    int m_strength;
};

#endif // ENTITE_H_INCLUDED
