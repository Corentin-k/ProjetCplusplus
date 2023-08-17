//
// Created by koco on 14/06/2023.
//

#include "ennemis.h"

int Squelette::dernierIDSquelette = 0;//
int Sorcier::dernierIDSorcier = 0;

void ennemi::affiche(){
    cout<<nom<<'\n';
    cout<<"\033[31;40mPV : \033[0m\033[31m" << pv <<"\033[0m\n"
        << "\033[32;40mATTAQUE : \033[0m\033[32m" << attaque << "\033[0m\n" //sur fond noir ;40
        << "\033[34;40mBOUCLIER :\033[0m\033[34m " << bouclier << "\033[0m\n"
        <<endl;
}

void ennemi::attaquePersonnage(personnage& p) {
    int degatsBouclier = attaque;
    if (degatsBouclier > bouclier) {
        degatsBouclier = bouclier;
    }
    p.reduireBouclier(degatsBouclier);

    int degatsRestants = attaque - degatsBouclier;


    p.reduirePV(degatsRestants);
}
void ennemi::reduirePV(int degats) {
    pv -= degats;
    if (pv < 0) {
        pv = 0;
    }
}

void ennemi::reduireBouclier(int degats) {
    bouclier -= degats;
    if (bouclier < 0) {
        bouclier = 0;
    }
}
/////////SQUELETTE///////////
/////////SORCIER/////////////