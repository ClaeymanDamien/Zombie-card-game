#include "Humain.h"
#include "Entite.h"
#include <iostream>
#include "time.h"
#include "stdlib.h"

using namespace std;


Soldat::Soldat(): Entite()
{

}

Medecin::Medecin(): Entite()
{

}

/*


void Soldat::bouclier(Entite &target,int value)
{
    target.m_resistance += value;
}
*/


void Soldat::mortier(Entite &target)
{
    target.prendreDegats(8);
}

void Soldat::lanceRoquette(Entite &target){

    target.prendreDegats(12);
}

void Medecin::injection()
{
    m_pointsDeVie += 8;

    if(m_pointsDeVie > 100)
    {
        m_pointsDeVie = 100;
    }
}


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

