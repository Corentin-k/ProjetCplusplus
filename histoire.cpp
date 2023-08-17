//
// Created by Coko on 08/08/2023.
//

#include "histoire.h"



using namespace std;
void lecture(const string& paragraphe,string name) {

    std::string histoire = "[introduction]\n"

                           "Bienvenue, Sir "+name+", dans notre royaume. Si vous acceptez cette mission,\n"
                           "votre objectif sera de vous aventurer dans la tour de l'Est pour ramener la precieuse potion qu'elle renferme.\n"
                           "Cette potion est vitale pour guerir notre princesse bien-aimee. Cependant, soyez vigilant,\n"
                           "car de redoutables monstres errent dans les parages.\n"
                           "Prendrez-vous le courageux choix d'accepter cette perilleuse mission,\n"
                           "ou prefererez-vous attendre et explorer les magnifiques couloirs de notre chateau ?\n"
                           "Votre destin vous appartient...\n\n"
                           ">> Allez-vous choisir de rester au Chateau (C) ou aller vous commencer l'aventure (A) ?"

                           "[/introduction]"

                           "[Chateau]\n"

                           "Le prince affiche son mecontentement, esperant voir en vous un vrai chevalier,\n"
                           "pret a agir pour sauver la princesse.\n"
                           "Cependant, votre decision de retarder votre depart le decoit grandement.\n"
                           "Il vous ordonne d'y aller tout de suite et refuse de vous passer le sac qu'il avait entre les mains.\n"
                           "La prochaine fois réfléchisser a deux fois lorsque vous vous addresser au prince.\n"
                           "L'aventure debute donc pour vous, depourvu d'armure et de richesse."

                           "[/Chateau]\n"

                           "[Aventure]\n"

                           "Le roi avant de partir, vous offre une magnifique armure qui vous protegera lors de votre aventure\n"
                           "et vous paye d'avance pour le risque a en courir.\n"
                           "Vous vous mettez en chemin."

                           "[/Aventure]\n"

                          "[Chemin]\n"

                          "Une horde de squelettes se dresse devant vous. Leurs os craquent sinistrement tandis qu'ils s'avancent,"
                          "\nnombres cachés dans l'ombre. Il  y en  au moins trois... peut-être plus."
                          "\nL'heure du combat est-elle venue (a) ou préférez-vous prendre la fuite (f) ?"

                          "[/Chemin]\n"
                          "[fuir]\n"

                          "En fuyant, vous ne faites pas attention et Deux autres squelettes surgissent de l'obscurité, vous contraignant à affronter le danger !"


                          "[/fuir]\n"
                           "";

    size_t debut = histoire.find("[" + paragraphe + "]");
    if (debut != string::npos) {
        debut = histoire.find("\n", debut) + 1;
        size_t fin = histoire.find("[/" + paragraphe + "]", debut);
        if (fin != string::npos) {
            string texte = histoire.substr(debut, fin - debut);
           cout << texte << endl;
        }
    }
}