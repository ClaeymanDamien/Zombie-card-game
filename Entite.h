#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED
#include "Card.h"
#include "string"
#include <vector>


class gameloop;

class Entite
{
    friend class Card;
    friend void afficher_ennemis(std::vector<Entite*> ennemi);
    friend void afficherjoueur(Entite joueur);
    friend void lose(Entite &player);
    friend void ennemy_die (vector<Entite *> &ennemis);
    friend void gameloop(Entite &player,vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse,vector<Card*> &pool_of_cards,vector<Card*> &choice_of_cards);
public:
    Entite(int _pointsDeVie=10, int _resistance=0, int _pointsDeDegats=0, int _strength = 0,std::string _id="Zombie", int _empoisonnement=0);
    void statistiques() const;
    void prendreDegats(int pointsDeDegats);
    void bouclier();
    void concentration();
    virtual void attaque(Entite &target);
    /// Devrait être en protected, je le met en public tant que c'est pas fix


protected:
    std::string m_id;
    int m_pointsDeVie;
    int m_pointsDeDegats;
    int m_resistance;
    int m_strength;
    int m_empoisonnement;
};

#endif // ENTITE_H_INCLUDED
