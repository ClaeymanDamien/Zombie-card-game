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

// Permet de temporiser
void delay(float time_to_wait)
{
    clock_t endtime=clock()+(time_to_wait*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter
    while(clock()<endtime);
}

// Effet graphique de chargement
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

// Initialisation du jeu (Selon les règles instaurées)
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
    Poison *chx7 = new Poison;
    Acide *chx8 = new Acide;
    poolcartes.push_back(chx1);
    poolcartes.push_back(chx2);
    poolcartes.push_back(chx3);
    poolcartes.push_back(chx4);
    poolcartes.push_back(chx5);
    poolcartes.push_back(chx6);
    poolcartes.push_back(chx7);
    poolcartes.push_back(chx8);


}

void afficherjoueur(Entite joueur)
{
    cout << "- Joueur" << " HP: " << joueur.m_pointsDeVie;
    if (joueur.m_resistance) cout << " Res: " << joueur.m_resistance ;
    if (joueur.m_strength) cout << " Puiss: " << joueur.m_strength ;
    if (joueur.m_empoisonnement) cout << " Poison: " << joueur.m_empoisonnement;
    cout << endl;
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
            cout << "- " << i+1 << " | Type: "<< ennemi[i]->m_id << " HP: " << ennemi[i]->m_pointsDeVie;
            cout << " Res: "<<ennemi[i]->m_resistance;
            cout <<" Puiss: "<< ennemi[i]->m_strength;
            if (ennemi[i]->m_empoisonnement) cout <<" Pois: " << ennemi[i]->m_empoisonnement;
            cout << endl;
        }
    }
    cout << "___________________________________________________________" << endl;
}

// Affiche l'interface entière du jeu
void afficherui(Entite player,vector<Entite*> &ennemis,vector<Card*> &deck,vector<Card*> &main,vector<Card*> &defausse)
{
    afficherjoueur(player);
    cout <<endl<<"- Ennemis: "<< endl;
    afficher_ennemis(ennemis);
    cout <<endl<<"- Deck: "<< deck.size() << " cartes" << endl;
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

// Si le joueur perd, on arrête le programme
void lose(Entite &player)
{
    if (player.m_pointsDeVie <= 0)
    {

        cout << "Vous avez succombe ... Nous nous reverrons en enfer !" << endl << endl;
        exit(EXIT_FAILURE);
    }
}

// Pioche aléatoirement une carte
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

// Pioche aléatoirement une carte et fait attention que le deck soit toujours rerempli par la défausse
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

// Vide le deck dans un autre paquet de cartes
void deck_to_another(vector<Card*> &deck,vector<Card*> &anotherdeck)
{
    draw(deck.size(),deck,anotherdeck);
}

// Demande une carte
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

// Demande quelle entité choisir
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

void copy_entity(int choix_ennemi, vector<Entite*> &ennemis,vector<Entite*> &anotherennemis)
{
    anotherennemis.push_back(ennemis[choix_ennemi]); // Ajoute la carte du deck � la main
}

// Permet de réinitialiser le pool d'ennemis, servira plus tard éventuellement à changer le pool d'ennemis selon la difficulté
void reinit_ennemy_pool(vector<Entite*> &pool_of_ennemis){
    size_t size_pool = pool_of_ennemis.size();
    for (unsigned int i=0; i<size_pool; i++){
        pool_of_ennemis.erase(pool_of_ennemis.begin());
    }

    Entite *enmy1 = new Medecin;
    pool_of_ennemis.push_back(enmy1);
    Entite *enmy2 = new Soldat;
    pool_of_ennemis.push_back(enmy2);
    Entite *enmy3 = new Infecte;
    pool_of_ennemis.push_back(enmy3);
    Entite *enmy4 = new Brute;
    pool_of_ennemis.push_back(enmy4);
    Entite *enmy5 = new Contagieux;
    pool_of_ennemis.push_back(enmy5);
    Entite *enmy6 = new Brute;
    pool_of_ennemis.push_back(enmy6);
    Entite *enmy7 = new Exploseur;
    pool_of_ennemis.push_back(enmy7);

}

// Crée le choix de cartes en fin de combat
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
        int tirage = rand() % pool_of_ennemys.size();
        move_entity(tirage,pool_of_ennemys,choice_of_ennemys);
    }
}

// Si une carte est jouée, on applique son effet sur les entités en combat
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

// Phase d'attaque des ennemis
void ennemys_attack (Entite &player, vector<Entite *> &ennemis)
{
    for (unsigned int i = 0; i < ennemis.size() ; i++)
    {
        ennemis[i]->attaque(player);
    }
}

// Affichage de l'empoisonnement des ennemis
void ennemys_poisoning(vector<Entite *> &ennemis){
    for (unsigned int i = 0; i < ennemis.size() ; i++)
    {
        if (ennemis[i]->m_empoisonnement>0){
            if (ennemis[i]->m_pointsDeVie - ennemis[i]->m_empoisonnement > 0){
                ennemis[i]->m_pointsDeVie = ennemis[i]->m_pointsDeVie - ennemis[i]->m_empoisonnement;
                cout << "L'ennemi " << i+1 << " a perdu " << ennemis[i]->m_empoisonnement << " point(s) de vie" << endl;
                ennemis[i]->m_empoisonnement--;
            }else{
                ennemis[i]->m_pointsDeVie = 0;
                ennemis[i]->m_empoisonnement = 0;
            }
        }
    }
}

// Si l'ennemi meurt, on le supprime
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
        ennemys_poisoning(ennemis);
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
