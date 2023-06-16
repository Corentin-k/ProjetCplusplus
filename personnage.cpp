//
// Created by koco on 14/06/2023.
//

#include "personnage.h"


personnage::personnage(const string& nom,int pv, int attaque, int bouclier, int vitesse_deplacement, int vitesse_attaque):
        nom{nom},
        attaque{attaque},
        pv{pv},
        bouclier{bouclier},
        vitesse_deplacement{vitesse_deplacement},
        vitesse_attaque{vitesse_attaque}
        {}
void personnage::affiche_perso(){
    cout << "\033[35m";// Blanc
    cout << nom << "\033[0m\n";
    affiche();
}

void personnage::affiche(){

    cout<<"\033[31;40mPV : \033[0m\033[31m" << pv <<"\033[0m\n"
         << "\033[32;40mATTAQUE : \033[0m\033[32m" << attaque << "\033[0m\n" //sur fond noir ;40
         <<endl;
};
void personnage::utiliserObjet(const string& objet) {
    cout << "Le personnage utilise l'objet : " << objet << endl;
}
void personnage::attaqueEnnemi(ennemi& e) {
    int degatsBouclier = attaque;
    if (degatsBouclier > e.getBouclier()) {
        degatsBouclier = e.getBouclier();
    }
    e.reduireBouclier(degatsBouclier);

    int degatsRestants = attaque - degatsBouclier;


    e.reduirePV(degatsRestants);
}
void personnage::reduirePV(int degats) {
    pv -= degats;
    if (pv < 0) {
        pv = 0;
    }
}

void personnage::reduireBouclier(int degats) {
    bouclier -= degats;
    if (bouclier < 0) {
        bouclier = 0;
    }
}
//////////////CHEVALIER////////////////

/*chevalier::chevalier(const string& nom_chevalier,int attaque):
            nom{nom_chevalier},
            attaque{attaque}
            {}
*/
chevalier::chevalier(const string& nom, int pv, int attaque, int bouclier, int vitesse_deplacement, int vitesse_attaque):
        personnage(nom, pv, attaque, bouclier, vitesse_deplacement, vitesse_attaque) {}



void chevalier::augmenterAttaque(int bonus) {
    attaque += bonus;
}

void chevalier::affiche_chevalier() {
    cout << "\033[36m";
    cout << nom <<"\033[0m\n";
    personnage::affiche();

}

//////////////MAGE/////////////////


mage::mage(const string& nom, int pv, int attaque, int bouclier, int vitesse_deplacement, int vitesse_attaque):
        personnage(nom, pv, attaque, bouclier, vitesse_deplacement, vitesse_attaque) {}

void mage::utiliserSort(const string& sort) {
    cout << nom << " utilise le sort : " << sort << endl;
}
void mage::invoquerCreature(const string& creature) {
    cout << "Le mage invoque la créature : " << creature << endl;
}

void mage::affiche_mage() {
    cout << "\033[33m"; // Jaune
    cout << nom <<"\033[0m\n" ;
    personnage::affiche();

}

