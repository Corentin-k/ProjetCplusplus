//
// Created by koco on 14/06/2023.
//

#ifndef DOCUMENTS_ENNEMIS_H
#define DOCUMENTS_ENNEMIS_H

#include <iostream>
#include <string>
#include "personnage.h"
class personnage;
using namespace std;

class ennemi {
private:
    string nom;
    int pv;
    int attaque;
    int ID;

    int bouclier;//uy

public:
    ennemi(const string& nom, int pv, int attaque,int bouclier, int ID) : nom(nom), pv(pv), attaque(attaque),bouclier(bouclier),ID(ID) {}


    void affiche();

    inline int getBouclier() {return bouclier;};

    void attaquePersonnage(personnage& p);
    void reduirePV(int valeur);
    void reduireBouclier(int valeur);

    inline int getID() {return ID;};

};

/////////SQUELLETTE///////////

class Squelette : public ennemi {

private:

    static int dernierIDSquelette;
public:

    Squelette() : ennemi("", 0, 0,0,dernierIDSquelette) {}
    Squelette(const string& nom, int pv = 100, int attaque = 25, int bouclier=15,int ID=dernierIDSquelette++) : ennemi(nom, pv, attaque,bouclier,ID) {}
    void affiche() {
        ennemi::affiche();

    }


};

/////////SORCIER///////////

class Sorcier : public ennemi {
private:

    static int dernierIDSorcier;
public:
    Sorcier(const string& nom, int pv = 100, int attaque = 15, int mana = 100, int bouclier=25,int ID=dernierIDSorcier++) : ennemi(nom, pv, attaque,bouclier,ID) {}
    Sorcier() : ennemi("", 0, 0, 0,dernierIDSorcier) {}

    void affiche() {
        ennemi::affiche();
    }
};

#endif //DOCUMENTS_ENNEMIS_H
