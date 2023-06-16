//
// Created by koco on 14/06/2023.
//

#ifndef DOCUMENTS_PERSONNAGE_H
#define DOCUMENTS_PERSONNAGE_H

#include <iostream>
#include <string>
#include "ennemis.h"
class ennemi;
using namespace std;
class personnage{

protected:
        string nom;
        int pv;
        int attaque;
        int bouclier;
        int vitesse_deplacement;
        int vitesse_attaque;

public:

    personnage(const string& nom, int pv, int attaque, int bouclier, int vitesse_deplacement, int vitesse_attaque);

    void affiche();
    void affiche_perso();

    inline int getBouclier() {return bouclier;};
    void attaqueEnnemi(ennemi& e);
    void reduirePV(int valeur);
    void reduireBouclier(int valeur);
    void utiliserObjet(const string& objet);
};

////////////CHEVALIER///////////////

class chevalier: public personnage{
public:
    //les constructeurs
    chevalier()=delete;  // obligatoire si d'autre constructeur sinon pas nécessaire
    chevalier(const string& nom="chevalier", int pv=150, int attaque=70, int bouclier=50, int vitesse_deplacement=5, int vitesse_attaque=5);
    void affiche_chevalier() ;


    inline int getAttaque() {return attaque;}; // inline permet d'augmenter la vitesse d'exécution car pas d'appel de fonction à la compilation

    //les actions




    void augmenterAttaque(int bonus);
    //on peut supprimer l'acces a une fonction en faisant fonction=delete;

    //on peut créée des classe amie qui pourront accéder a toutes les valeur de la classe page 277
};

//////////////MAGE/////////////////
class mage: public personnage {

public:
    mage()=default;
    mage(const string& nom, int pv = 150, int attaque = 50, int bouclier = 50, int vitesse_deplacement = 3, int vitesse_attaque = 5);

    void affiche_mage();

    void utiliserSort(const string& sort);
    void invoquerCreature(const string& creature);

};
#endif //DOCUMENTS_PERSONNAGE_H
