//
// Created by Coko on 08/08/2023.
//

#ifndef CPLUSPLUS_COMMANDE_H
#define CPLUSPLUS_COMMANDE_H
#include "personnage.h"
#include <string>
int commande(char, personnage*);
void sauvegarde(personnage* hero);

void open_sauvegarde(std::ifstream,personnage*);
#endif //CPLUSPLUS_COMMANDE_H
