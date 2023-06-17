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
    virtual ~personnage(){cout<<"Le personnage est mort\n";} //destructeur
    personnage(const string& nom, int pv, int attaque, int bouclier, int vitesse_deplacement, int vitesse_attaque); //constructeur



    inline int getBouclier() {return bouclier;};
    void attaqueEnnemi(ennemi& e);
    void reduirePV(int valeur);
    void reduireBouclier(int valeur);
    void utiliserObjet(const string& objet);

    virtual void affiche_specificites();

    template <typename T>
    void affiche(T* perso) {
        perso->affiche_specificites();
        cout << "\033[31;40mPV : \033[0m\033[31m" << pv << "\033[0m\n"
             << "\033[32;40mATTAQUE : \033[0m\033[32m" << attaque << "\033[0m\n"
             << endl;
    }



};

////////////CHEVALIER///////////////

class chevalier: public personnage{
public:
    //les constructeurs
    chevalier()=delete;  // obligatoire si d'autre constructeur sinon pas nécessaire
    chevalier(const string& nom="chevalier", int pv=100, int attaque=20, int bouclier=50, int vitesse_deplacement=5, int vitesse_attaque=5);

    // destructeur
    ~chevalier(){cout<<"Le chevalier est mort\n";}
    void affiche_chevalier() ;


    inline int getAttaque() {return attaque;}; // inline permet d'augmenter la vitesse d'exécution car pas d'appel de fonction à la compilation

    //les actions

    void affiche_specificites() ; // rajouter le mot override a la fin si jamais je veux changer les parametres de la fonction ou en ajouter e t si je veux garder la fonction principal il suffit de l'appeler : perssonage::affiche_specificites
    void augmenterAttaque(int bonus);
    //on peut supprimer l'acces a une fonction en faisant fonction=delete;

    //on peut créée des classe amie qui pourront accéder a toutes les valeur de la classe page 277
};

//////////////MAGE/////////////////
class mage: public personnage {

public:

    mage()=default;
    mage(const string& nom, int pv = 100, int attaque = 35, int bouclier = 0, int vitesse_deplacement = 3, int vitesse_attaque = 5);

    // destructeur
    ~mage(){cout<<"Le mage est mort \n";}


    void affiche_specificites();

    void utiliserSort(const string& sort);
    void invoquerCreature(const string& creature);

};
#endif //DOCUMENTS_PERSONNAGE_H
