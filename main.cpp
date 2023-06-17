#include <iostream>

#include "personnage.h"
#include "ennemis.h"
using namespace std;

template <typename T>
T* creerTableauEnnemis(int taille,string tpe) {
    T* tableau = new T[taille];
    for (int i = 0; i < taille; ++i) {
        string nom = tpe + to_string(i);
        T ennemi(nom);
        tableau[i] = ennemi;
    }
    return tableau;
}
template Squelette* creerTableauEnnemis<Squelette>(int,string);
template Sorcier* creerTableauEnnemis<Sorcier>(int,string);

int main() {
    int choix;
    cout<<"Bienvenue dans ce monde. Vous allez incarné un héro et devoir battre tous les ennemis.\n";
    cout<<"Choissiez votre héros : \n";
    cout<<"   1-Le roi Arhtur, célèbre chevalier de la table ronde qui a une attaque redoutable mais est tres lent\n";
    cout<<"   2- Gandalf, célébre magicien il attaque rapidement mais n'as pas de bouclier \n";
    cout<<">> Votre choix : ";
    cin >> choix;

    while (choix!=1 && choix!= 2 && choix!=3){
        cout << ">> Choix invalide. Veuillez entrer 1 ou 2 :";
        cin.clear();
        rewind(stdin);
        cin >> choix;
    }

    personnage* heros = nullptr;
    cout <<">> Vous avez choisi\n"<<endl;
    if (choix == 1) {
        heros = new chevalier("ARTHUR", 70);
    } else if (choix == 2) {
        heros = new mage("Gandalf");
    }
    else{
        heros= new personnage("Coco",0,0,0,0,0);
    }
    if (heros != nullptr) {
        heros->affiche(heros);
    }

    delete heros;
    /*
    const int tailleTableau = 5;

    // Création d'un tableau de Squelettes
    Squelette* tableauSquelettes = creerTableauEnnemis<Squelette>(tailleTableau,"Squelette ");
    for (int i = 0; i < tailleTableau; ++i) {
        tableauSquelettes[i].affiche();
        cout << tableauSquelettes[i].getID()<<'\n'<<endl;
    }


    cout << endl;
    // Création d'un tableau de Sorciers
    Sorcier* tableauSorciers = creerTableauEnnemis<Sorcier>(tailleTableau,"Sorciers ");
    for (int i = 0; i < tailleTableau; ++i) {
        tableauSorciers[i].affiche();
        cout << tableauSorciers[i].getID()<<'\n'<<endl;
    }




    chevalier chevalier1("chevalier",70);

    personnage perso("Coco",1,1,1,1,1);
    perso.affiche_perso();


    //chevalier1.pv=30; impossible de modifier car pv est privé
    //cout<<chevalier1.pv<< endl; //de même impossible de lire
    delete[] tableauSorciers;
    delete[] tableauSquelettes;

    chevalier Lancelot("Lancelot",200,40,5,6);
    Lancelot.affiche_chevalier();
    mage Melchior("Melchior",200,30,300,3);Melchior.affiche_mage();*/
     return 0;
}






