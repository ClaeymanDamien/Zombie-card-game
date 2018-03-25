#include "Humain.h"
#include "Entite.h"
#include <iostream>
#include "time.h"
#include "stdlib.h"

using namespace std;

// Création des constructeurs
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

void Soldat::mortier(Entite &target) //Attaque mortier causant des dégats à la cible (entree en paramètre)
{
    target.prendreDegats(9);
    cout << "Surveillez mieux le ciel, le mortier vous a touche et vous fait perdre 9 points de vie" << endl;
}

void Soldat::lanceRoquette(Entite &target) //Attaque lanceRoquette causant des dégats à la cible (entree en paramètre)
{

    target.prendreDegats(13);
    cout << "Hou, le lance-roquette est passe tout pret de votre position, vous n'avez presque rien mais vous perdez 13 points de vie" << endl;

}

// methode permettant de choisir aléatoirement l'attaque d'un soldat
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
    cout << "Ce medecin est fou, il vous a lance des seringues contaminees! Vous etes legerement blesse et vous perdez 7 points de vie" << endl;

}

void Medecin::lanceStethoscope(Entite &target){

    target.prendreDegats(11);
    cout << "Ce medecin fou, il vous a carrement lance son stethoscope dans vos yeux! Vous etes  blesse et vous perdez 9 points de vie" << endl;
}


void Medecin::injection()
{
    m_pointsDeVie += 15;

    if(m_pointsDeVie > 100) //Sécurisation pour que le PV personnage <= 100
    {
        m_pointsDeVie = 100;
    }

    cout << "La medecine peut sauver des vie, il gagne 15 points de vie" << endl;
}




// Methode permettant de choisir aléatoirement l'attaque ou la défense d'un médecin
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
