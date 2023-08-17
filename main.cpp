#include <iostream>
#include <fstream>
#include "commande.h"
#include "personnage.h"
#include "ennemis.h"
#include <cstdlib>
#include "histoire.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
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

    personnage* heros = nullptr;
    string niveaux;

    /*------------------------------------------------Sauvegarde------------------------------------------------------*/

                    const char* homeDir = getenv("USERPROFILE");
                    std::string documentsDir = std::string(homeDir) + "\\Documents";

                    string cheminFichier = documentsDir + "\\COCO GAME (sauvegarde)\\";

                    if (!fs::exists(documentsDir)) {
                        cheminFichier = "/Sauvegarde/";cout<<"ici";
                    }

                    ifstream sauvegarde(cheminFichier+"save.txt");

                    if (sauvegarde.is_open()) {
                        string ligne;
                        bool lectureNiveau = false;
                        while (std::getline(sauvegarde, ligne)) {
                            if (ligne == "[niveau]") {
                                lectureNiveau = true;
                                continue;
                            }

                            if (lectureNiveau) {
                                if (ligne == "[/niveau]") {
                                    break;
                                }
                                niveaux += ligne + "\n";
                            }

                        }
                        sauvegarde.close();
                        std::ifstream sauvegarde2(cheminFichier+"save.txt");
                        niveaux = niveaux.substr(0, niveaux.size() - 1);
                        if (niveaux!="Création_joueur"){
                            cout<<"Une sauvegarde a ete trouvee, voulez vous reprendre la ou vous vous etes arrete? (o/n)";
                            char choix;
                            cin>>choix;
                            if (choix=='o'){
                                string name;
                                string type;
                                int pv;
                                int attaque;
                                int bouclier;

                                std::string line;
                                while (std::getline(sauvegarde2, line)) {

                                    std::getline(sauvegarde2, line); // Lire la ligne vide

                                    std::getline(sauvegarde2, type); // Lire le type du héros

                                    std::getline(sauvegarde2, line);
                                    std::getline(sauvegarde2, name); // Lire le nom du héros

                                    std::getline(sauvegarde2, line);
                                    std::getline(sauvegarde2, line);
                                    pv = std::stoi(line); // Convertir la ligne en entier pour les PV du héros
                                    std::getline(sauvegarde2, line);
                                    std::getline(sauvegarde2, line);
                                    attaque = std::stoi(line); // Convertir la ligne en entier pour l'attaque du héros
                                    std::getline(sauvegarde2, line);
                                    std::getline(sauvegarde2, line);
                                    bouclier = std::stoi(line); // Convertir la ligne en entier pour le bouclier du héros

                                    break;

                                }
                                sauvegarde.close();

                                if (type=="chevalier"){
                                    heros = new chevalier(name,pv,attaque,bouclier,10,10);
                                } else if (type=="mage"){
                                    heros = new mage(name,pv,attaque,bouclier,10,10);
                                }else heros = new personnage(name,pv,attaque,bouclier,10,10);
                                heros->affiche(heros);
                                cout<<"\nNiveau atteint : "<<niveaux<<"\n"<<endl;

                            }
                            else niveaux="Création_joueur";
                            system("cls");

                        }

                    } else {
                        niveaux = "Création_joueur"; // Par défaut, commencer depuis le début
                    }
    /*----------------------------------------------------------------------------------------------------------------*/


    if(niveaux== "Création_joueur"){
        int choix;
        cout << "Bienvenue dans ce monde. Vous allez incarner un heros et devoir battre tous les ennemis.\n";
        cout << "Choisissiez votre heros : \n";
        cout << "   1- Un chevalier : le chevalier a une attaque redoutable mais est tres lent\n";
        cout << "   2- Un mage, le magicien attaque rapidement mais n'as pas de bouclier \n";
        cout << ">> Votre choix : ";
        cin >> choix;

        while (choix != 1 && choix != 2 && choix != 3) {
            cout << ">> Choix invalide. Veuillez entrer 1 ou 2 :";
            cin.clear();
            rewind(stdin);
            cin >> choix;
        }

        string name;

        if (choix == 1) {
            cout<<"\nBienvenue Cher Chevalier quel est votre nom ?"<< endl;

            cout<<">> ";
            cin>>name;
            heros = new chevalier(name, 70);
            heros->type="chevalier";
        } else if (choix == 2) {
            cout<<"\nBienvenue cher mage, quel est votre nom ?"<< endl;

            cout<<">> ";
            cin>>name;
            heros = new mage(name);
            cout<<"\nQuel est votre couleur de cheveux"<< endl;

            cout<<">> ";
            cin>>name;
            cout<<"Oh tres joli, mais cela ne vous sera d'aucune utilite !!! !!!"<< endl;
            heros->type="mage";
        } else {
            cout<<"\nBienvenue cher personnage, quel est votre nom ?"<< endl;

            cout<<">> ";
            cin>>name;
            heros = new personnage(name, 0, 0, 0, 0, 0);
            heros->type="personnage";
        }

        cout << "\n>>\033[5m Voici vos informations : \033[0m\n" << endl;
        if (heros != nullptr) {
            heros->affiche(heros);
        }

        cout<<"Commencez l'aventure ...";
        cin.clear();
        cin.ignore();
        cin.get() ;
        niveaux="introduction";
        system("cls");

        cout<< "Informations importantes avant de commancer : \n"<< endl;
        cout<<"A tout moment :  "<< endl;
        cout<<" - Taper 's' pour sauvegarde la partie en cours"<< endl;
        cout<<" - Taper 'q' pour quitter la partie en cours"<< endl;
        cout<<" - Taper 'h' pour afficher toutes les commandes"<< endl;
        cout<<" - Taper 'i' pour afficher vos informations de personnage"<< endl;

        cout<<"\nPret a demarrer l'aventure ...";
        heros->paragraphe="introduction";
        char reponse;
        cin.clear();
        rewind(stdin);
        reponse=cin.get();
        while (reponse!='\n') {

            int val= commande(reponse,heros);

            cin.clear();
            rewind(stdin);

            cout<<"\nPret a demarrer l'aventure ...";

            reponse=cin.get();
        }
        system("cls");
    }

    if (niveaux=="introduction"){

        heros->paragraphe="introduction";
        lecture("introduction",heros->nom);
        cout<<">> ";

        char reponse;
        cin>>reponse;
        while (reponse!='a' && reponse!='c') {
            int val= commande(reponse,heros);
            reponse='\0';
            cin.clear();
            rewind(stdin);
            if (not(val)){
                cout<<heros->type<<" cette action n'est pas disponible : ";

            }
            else{
                cout<<"Faites votre choix "<<heros->type<<" : ";
            }cin>>reponse;
           }
        cout<<"\n";
        if (reponse=='a') {heros->paragraphe="Aventure";heros->setBouclier(20);niveaux="Aventure";}
        if (reponse=='c') {heros->paragraphe="Chateau";heros->setBouclier(0);niveaux="Chateau";}
        system("cls");
    }

    if (niveaux == "Aventure") {
        lecture("Aventure",heros->nom);
        heros->bouclier=100;
        niveaux="Chemin";
        char reponse;
        cout<<"Continuez le chemin ...";


        cin.clear();
        rewind(stdin);
        reponse=cin.get();
        while (reponse!='\n') {
            int val= commande(reponse,heros);

            cin.clear();
            rewind(stdin);

            cout<<"\nContinuez le chemin ...";

            reponse=cin.get();
        }
        system("cls");

    }

    if (niveaux == "Chateau") {
        lecture("Chateau",heros->nom);
        niveaux="Chemin";
        char reponse;
        cout<<"Continuez le chemin ...";


        cin.clear();
        rewind(stdin);
        reponse=cin.get();
        while (reponse!='\n') {
            int val= commande(reponse,heros);

            cin.clear();
            rewind(stdin);

            cout<<"\nContinuez le chemin ...";

            reponse=cin.get();
        }
        system("cls");
    }

    if (niveaux == "Chemin"){



        lecture("Chemin",heros->nom);


        char reponse;
        cin>>reponse;
        while (reponse!='a' && reponse!='f') {
            int val= commande(reponse,heros);
            reponse='\0';
            cin.clear();
            rewind(stdin);
            if (not(val)){
                cout<<heros->type<<" cette action n'est pas disponible : ";

            }
            else{
                cout<<"Faites votre choix "<<heros->type<<" : ";
            }
            cin>>reponse;
        }

        if (reponse=='a') {heros->paragraphe="combattre";heros->setBouclier(20);niveaux="combattre";}
        if (reponse=='f') {heros->paragraphe="fuir";heros->setBouclier(0);niveaux="fuir";lecture("fuir",heros->nom);niveaux="combattre";
            while (reponse!='\n') {
                int val= commande(reponse,heros);

                cin.clear();
                rewind(stdin);

                cout<<"\nPassez a l'attaque ...";

                reponse=cin.get();
            }
           }

        system("cls");

    }
    if  (niveaux == "combattre"){
        const int tailleTableau = 5;
        // Création d'un tableau de Squelettes
        Squelette* tableauSquelettes = creerTableauEnnemis<Squelette>(tailleTableau,"Squelette ");
        for (int i = 0; i < tailleTableau; ++i) {
            tableauSquelettes[i].affiche();
        }
        cout<<"Voici venue le moment de combattre"<<endl;
        heros->attaqueEnnemi(tableauSquelettes[0]);
        for (int i = 0; i < tailleTableau; ++i) {
            tableauSquelettes[i].affiche();

        }
    }






        delete heros;
   
     return 0;
}






