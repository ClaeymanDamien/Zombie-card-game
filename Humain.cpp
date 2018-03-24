#include "Humain.h"
#include "Entite.h"
#include <iostream>
#include "time.h"
#include "stdlib.h"

using namespace std;

// Cr�ation des constructeurs
Soldat::Soldat(int _pointsDeVie, int _resistance, int _pointsDeDegats, int _strength,string _id): Entite()
{
    m_pointsDeVie = _pointsDeVie;
    m_resistance = _resistance;
    m_pointsDeDegats = _pointsDeDegats;
    m_strength = _strength;
    m_id = _id;
}

Medecin::Medecin(int _pointsDeVie, int _resistance, int _pointsDeDegats, int _strength,string _id): Entite()
{
    m_pointsDeVie = _pointsDeVie;
    m_resistance = _resistance;
    m_pointsDeDegats = _pointsDeDegats;
    m_strength = _strength;
    m_id = _id;
}

// LES METHODES DE LA CLASSE SOLDAT



void Soldat::mortier(Entite &target) //Attaque mortier causant des d�gats � la cible (entree en param�tre)
{
    target.prendreDegats(9);
}

void Soldat::lanceRoquette(Entite &target) //Attaque lanceRoquette causant des d�gats � la cible (entree en param�tre)
{

    target.prendreDegats(13);
}

// methode permettant de choisir al�atoirement l'attaque d'un soldat
void Soldat::attaque(Entite &target){

    srand(time(NULL));
    int nb=rand()%(2)+1;

    if(nb==1){
        mortier(target);
    }

    else if (nb==2) {
        lanceRoquette(target);
    }

    else {
        cout << "Erreur" << endl;
    }

}

// LES METHODES DE LA CLASSE SOLDAT

void Medecin::lanceSeringue(Entite &target){

    target.prendreDegats(7);

}

void Medecin::lanceStethoscope(Entite &target){

    target.prendreDegats(11);
}


void Medecin::injection()
{
    m_pointsDeVie += 15;

    if(m_pointsDeVie > 100) //S�curisation pour que le PV personnage <= 100
    {
        m_pointsDeVie = 100;
    }
}



// Methode permettant de choisir al�atoirement l'attaque ou la d�fense d'un m�decin
void Medecin::attaque(Entite &target){

    srand(time(NULL));
    int nb=rand()%(3)+1;

    if(nb==1){
        lanceSeringue(target);
    }

    else if (nb==2) {
        injection();
    }
    else if (nb==3){
        lanceStethoscope(target);
    }
    else {
        cout << "Erreur" << endl;
    }

}


/*


void Soldat::bouclier(Entite &target,int value)
{
    target.m_resistance += value;
}
*/
