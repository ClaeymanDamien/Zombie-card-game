#include "Entite.h"
#include "Card.h"
#include "gameloop.h"
#include "Humain.h"
#include "Zombie.h"
#include "TypesDeZombies.h"
#include <iostream>
#include <algorithm> // std::move (ranges)
#include <utility> // std::move (objects)
#include <string>
#include <vector> // std
#include <time.h>

using namespace std;


// FONCTIONS

void delay(float time_to_wait)
{
    clock_t endtime=clock()+(time_to_wait*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter
    while(clock()<endtime);
}

void loading()
{
    cout << endl ;
    delay(0.4);
    cout << "." ;
    delay(0.4);
    cout << "." ;
    delay(0.4);
    cout << "." ;
    delay(0.4);
}

void init_game(Entite &player,vector<Entite*> &ennemis, vector<Entite*> &poolennemis, vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse,vector<Card*> &poolcartes, vector<Card*> &choice_of_cards){
    // Deck de base
    for (int i = 0; i < 5; i++){
        Lancepierre *lcp1=new Lancepierre;
        Bouclier *bcl1=new Bouclier;
        deck.push_back(lcp1);
        deck.push_back(bcl1);
    }

    // Pool d'ennemis

    Entite *enmy1 = new Medecin;
    poolennemis.push_back(enmy1);
    Entite *enmy2 = new Soldat;
    poolennemis.push_back(enmy2);
    Entite *enmy3 = new Infecte;
    poolennemis.push_back(enmy3);
    Entite *enmy4 = new Brute;
    poolennemis.push_back(enmy4);
    Entite *enmy5 = new Contagieux;
    poolennemis.push_back(enmy5);
    Entite *enmy6 = new Brute;
    poolennemis.push_back(enmy6);
    Entite *enmy7 = new Exploseur;
    poolennemis.push_back(enmy7);

    // Pool de cartes
    Lancepierre *chx1 = new Lancepierre;
    Medkit *chx2 = new Medkit;
    Bouclier *chx3 = new Bouclier;
    Steroide *chx4 = new Steroide;
    Sniper *chx5 = new Sniper;
    Matraque *chx6 = new Matraque;
    poolcartes.push_back(chx1);
    poolcartes.push_back(chx2);
    poolcartes.push_back(chx3);
    poolcartes.push_back(chx4);
    poolcartes.push_back(chx5);
    poolcartes.push_back(chx6);


}
void afficherjoueur(Entite joueur)
{
    cout << "- Joueur" << " HP: " << joueur.m_pointsDeVie << " Res: " << joueur.m_resistance << " Puiss: " << joueur.m_strength << " Poison: " << joueur.m_empoisonnement << endl;
    cout << "___________________________________________________________" << endl;
}

void afficher_ennemis(vector<Entite*> ennemi)
{

    if (ennemi.size() == 0)
    {
        cout << "Pas d'ennemi" <<endl;
    }
    else
    {
        for (unsigned int i = 0; i<ennemi.size(); i++)
        {
            cout << "- " << i+1 << " | Type: "<< ennemi[i]->m_id << " HP: " << ennemi[i]->m_pointsDeVie << " Res: "<<ennemi[i]->m_resistance <<" Puiss: "<< ennemi[i]->m_strength << endl;
        }
    }
    cout << "___________________________________________________________" << endl;
}

void afficherui(Entite player,vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse)
{
    afficherjoueur(player);
    cout <<endl<<"- Ennemis: "<< endl;
    afficher_ennemis(ennemis);
    cout <<endl<<"- Deck: "<< main.size() << " cartes" << endl;
    cout <<endl<<"- Defausse: "<< defausse.size() << " cartes" << endl;
    //afficher(deck);
    cout <<endl<<"- Main: "<< endl;
    afficher(main);

    //afficher(defausse);
}

void if_deck_empty()
{

}

void afficher(vector<Card*> main)
{

    if (main.size() == 0)
    {
        cout << "Vide" <<endl;
    }
    else
    {
        for (unsigned int i = 0; i<main.size(); i++)
        {
            cout << "- " << i+1 << " | Cout: " << main[i]->cost << " " << main[i]->id << " | " << main[i]->description << endl;
        }
    }
}

void clearconsole()
{
    system("cls");
}

void lose(Entite &player)
{
    if (player.m_pointsDeVie <= 0)
    {

        cout << "Vous avez succombe ... Nous nous reverrons en enfer !" << endl << endl;
        exit(EXIT_FAILURE);
    }
}

void draw(int nbr_cartes,vector<Card*> &deck,vector<Card*> &main)
{

    for (int i = 0; i < nbr_cartes; i++)
    {
        //if ()
        int tirage = rand()%deck.size();
        //cout << tirage << deck[tirage]->id <<endl; // Debug, ligne fonctionnelle
        // copy (deck[tirage],deck[tirage],main.begin()); // Utilisable seulement si multiple copie
        main.push_back(deck[tirage]); // Ajoute la carte du deck à la main
        deck.erase(deck.begin()+tirage); // Supprime la carte du deck
    }
}

void draw_with_care(int nbr_cartes,vector<Card*> &deck,vector<Card*> &main, vector <Card*> &defausse)
{

    size_t plus_de_cartes = 0; // Obligé de passer par size_t pour comparer à une size de vector

    for (int i = 0; i < nbr_cartes; i++)
    {

        if (deck.size() == plus_de_cartes)
        {
            deck_to_another(defausse,deck);
            //cout << "Debug Deck: " << deck.size() << " Debug Main: " << main.size() << " Debug Defausse: " << defausse.size() << endl;
        }


        int tirage = rand()%deck.size();
        main.push_back(deck[tirage]); // Ajoute la carte du deck à la main
        deck.erase(deck.begin()+tirage); // Supprime la carte du deck
    }
}

void deck_to_another(vector<Card*> &deck,vector<Card*> &anotherdeck)
{
    draw(deck.size(),deck,anotherdeck);
}

int prompt_card(int PA,vector<Card*> &main)
{
    cout << endl << "Quelle carte allez vous jouer ? Il vous reste " << PA << " points d'action." << endl << "Votre choix: " ;
    int taille_main_max = main.size(),choix;
    cin >> choix;
    if (choix >= 0 && choix <= taille_main_max)
    {
        return choix-1;
    }
    else
    {
        cout << endl << "Choix invalide !" << endl;
        prompt_card(PA, main);
    }
    return 0;
}

int prompt_card_choice(int PA,vector<Card*> &main)
{
    int taille_main_max = main.size(),choix;
    cin >> choix;
    if (choix >= 0 && choix <= taille_main_max)
    {
        return choix-1;
    }
    else
    {
        cout << endl << "Choix invalide !" << endl;
        prompt_card(PA, main);
    }
    return 0;
}

int prompt_entity(vector<Entite*> &ennemis)
{
    cout << endl << "Quelle va etre votre cible ?" << endl << "Votre choix: " ;
    int taille_ennemis_max = ennemis.size(),choix;
    cin >> choix;
    if (choix >= 0 && choix <= taille_ennemis_max)
    {
        return choix-1;
    }
    else
    {
        cout << endl << "Choix invalide !" << endl;
        prompt_entity(ennemis);
    }
    return 0;
}

// Pour bouger une carte d'un deck à l'autre
void move_card(int choix_carte, vector<Card*> &deck,vector<Card*> &anotherdeck)
{

    anotherdeck.push_back(deck[choix_carte]); // Ajoute la carte du deck � la main
    deck.erase(deck.begin()+choix_carte); // Supprime la carte du deck
}

void copy_card(int choix_carte, vector<Card*> &deck,vector<Card*> &anotherdeck)
{

    anotherdeck.push_back(deck[choix_carte]); // Ajoute la carte du deck � la main
}

void move_entity(int choix_ennemi, vector<Entite*> &ennemis,vector<Entite*> &anotherennemis)
{

    anotherennemis.push_back(ennemis[choix_ennemi]); // Ajoute la carte du deck � la main
    ennemis.erase(ennemis.begin()+choix_ennemi); // Supprime la carte du deck
}

void create_card_choice(vector<Card*> &pool_of_cards,vector<Card*> &choice_of_cards)
{
    for (int i = 0; i < 3; i++)
    {
        int tirage = rand()%pool_of_cards.size();
        copy_card(tirage,pool_of_cards,choice_of_cards);
    }
}

void empty_card_choice(vector<Card*> &choice_of_cards){
    for (unsigned int i = 0; i < choice_of_cards.size(); i++)
    {
        choice_of_cards.erase(choice_of_cards.begin()+i);
    }
}

void choix_nouvelle_carte(vector<Card*> &choice_of_cards, vector<Card*> &deck)
{
    cout << "Vous avez remporte ce combat, choisissez une recompense: " << endl << endl;
    afficher(choice_of_cards);
    move_card(prompt_card_choice(1,choice_of_cards),choice_of_cards,deck);
    clearconsole();
}

void create_ennemy_choice(vector<Entite*> &pool_of_ennemys, vector<Entite*> &choice_of_ennemys)
{

    int nombre_alea = 1+rand()%4;

    for (int i = 0; i < nombre_alea; i++)
    {
        int tirage = rand()%pool_of_ennemys.size();
        move_entity(tirage,pool_of_ennemys,choice_of_ennemys);
    }
}

void card_played(int &PA,int choix_carte, Entite &player, vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse)
{

    if(main[choix_carte]->target_type == 1)  // Attaque normale
    {
        main[choix_carte]->effect(player,ennemis[prompt_entity(ennemis)]);
    }
    else if(main[choix_carte]->target_type == 2)     // AOE
    {
        main[choix_carte]->effect(player,ennemis[0]);
    }
    else     // Buff car target_type == 0
    {
        main[choix_carte]->effect(player,ennemis[0]);
    }
    ennemy_die(ennemis);
    PA = PA - main[choix_carte]->cost;
    move_card(choix_carte,main,defausse); // On trash la carte après l'avoir joué
}

void ennemys_attack (Entite &player, vector<Entite *> &ennemis)
{
    for (unsigned int i = 0; i < ennemis.size() ; i++)
    {
        ennemis[i]->attaque(player);
        if (ennemis[i]->m_empoisonnement){
            ennemis[i]->m_pointsDeVie = ennemis[i]->m_pointsDeVie - ennemis[i]->m_empoisonnement;
            ennemis[i]->m_empoisonnement--;

        }
    }
}

void ennemy_die (vector<Entite *> &ennemis)
{
    for (unsigned int i=0; i < ennemis.size(); i++)
    {
        if (ennemis[i]->m_pointsDeVie <= 0)
        {
            ennemis.erase(ennemis.begin()+i);
        }
    }
}

// Gameloop finale

void gameloop(Entite &player,vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse,vector<Card*> &pool_of_cards,vector<Card*> &choice_of_cards)
{
    int PA=3,choix_carte; //,nbr_tour;//,choix_ennemi;

    size_t zero = 0;

    // Démarrage de la partie

    afficherui(player,ennemis,deck,main,defausse);
    loading();
    clearconsole();

    // Début de la boucle de jeu

    while(ennemis.size() != zero)
    {
        PA = 3;
        draw_with_care(5,deck,main,defausse);
        while(PA > 0 && ennemis.size() != zero)
        {
            afficherui(player,ennemis,deck,main,defausse);
            choix_carte=prompt_card(PA, main);
            // If card_type =! AOE =! HEAL =! BOOST
            // choix_ennemi=prompt_entity(ennemis); PAS UTILE
            card_played(PA,choix_carte, player,ennemis,deck,main,defausse);
            loading();
            clearconsole();
        }
        ennemys_attack(player,ennemis);
        lose(player);
        deck_to_another(main,defausse);

        // On prend en compte l'empoisonnement du player
        if ( player.m_empoisonnement)
        {
            player.m_pointsDeVie = player.m_pointsDeVie - player.m_empoisonnement;
            player.m_empoisonnement--;
        }
    }

    // On remet à 0 les statistiques du player
    player.m_empoisonnement = 0;
    player.m_resistance = 0;
    player.m_strength = 0;
}
