#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED

class Entite
{
public:
    Entite();
    void statistiques() const;
    void prendreDegats(int pointsDeDegats);
    void mortier(Entite &cible);
    void injection();
    void bouclier();
    void concentration();

private:
    int m_pointsDeVie;
    int m_pointsDeDegats;
    int m_defense;
    int m_force;
    int m_armure;
};

#endif // ENTITE_H_INCLUDED
