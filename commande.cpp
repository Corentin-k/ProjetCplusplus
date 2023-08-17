//
// Created by Coko on 08/08/2023.
//

#include "commande.h"
#include <fstream>
#include <filesystem>
#include <cstdlib>
namespace fs = std::filesystem;
void sauvegarde(personnage* hero){
    cout<<"\nRecherche du repertoire de sauvegarede... "<<endl;
    const char* homeDir = getenv("USERPROFILE");
    std::string documentsDir = std::string(homeDir) + "\\Documents";

    string cheminFichier = documentsDir + "\\COCO GAME (sauvegarde)";

    if (!fs::exists(cheminFichier)) {
        cheminFichier = "\\Sauvegarde";

        if (fs::create_directory(cheminFichier)) {
            cout << "Repertoire '" << cheminFichier << "' cree avec succes." << endl;
        } else {
            cout << "Erreur : Impossible de créer le répertoire '" << cheminFichier << "'." << endl;
            return; // Arrêter la sauvegarde en cas d'erreur
        }
    }
    cout<<"Repertoire trouve avec succes "<<cheminFichier<<endl;
    std::ofstream fichier(cheminFichier+"/"+"save.txt");
    fichier << "[info hero]"<< std::endl;
    fichier <<"TYPE: "<< std::endl;
    fichier << hero->type << std::endl;
    fichier <<"NOM: "<< std::endl;
    fichier << hero->nom << std::endl;
    fichier <<"PV: " << std::endl;
    fichier << hero->pv << std::endl;
    fichier <<"ATTAQUE: " << std::endl;
    fichier << hero->attaque << std::endl;
    fichier <<"BOUCLIER: " << std::endl;
    fichier <<hero->bouclier << std::endl;
    fichier << "[/info hero]"<< std::endl;
    fichier <<"[niveau]"<< std::endl;
    fichier<< hero->paragraphe << std::endl;
    fichier <<"[/niveau]"<< std::endl;

    cout<<"La partie sauvegardee avec succes\n";
    fichier.close();
}
int commande(char commande, personnage* hero){
    if (commande=='i'){
        hero->affiche(hero);
        return 1;
    }
    if (commande=='s'){
        sauvegarde(hero);
        return 1;
    }
    if (commande=='q'){
        cout<<"Vous les vous vraiment arrete de jouer (o/n) :";
        char choix;
        cin>>choix;
        if (choix=='o'){
            cout<<"Voulez vous enregistrez votre partie avant de quitter ? (o/n)";
            char save;
            cin>>save;
            if (choix=='n') sauvegarde(hero);
            exit(0);
        }
        else{
            return 1;
        }
    }
    if (commande=='h'){
        cout<< "Voici les touches supplementaire : \n"<< endl;
        cout<<"A tout moment :  "<< endl;
        cout<<" - Taper 's' pour sauvegarde la partie en cours"<< endl;
        cout<<" - Taper 'q' pour quitter la partie en cours"<< endl;
        cout<<" - Taper 'h' pour afficher toutes les commandes"<< endl;
        cout<<" - Taper 'i' pour afficher vos informations de personnage"<< endl;
        return 1;
    }
    return 0;

};

void open_sauvegarde(std::ifstream sauvegarde, personnage* heros){

        cout<<"n";

}