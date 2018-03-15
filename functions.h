#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "variables.h"


int getRandomNumber(int min, int max);

//std::string getRandomWeapon();

AssignmentResult assignWeapon (std::fstream &file, int slotAddress, int slotLength, const std::string &weapon);

//void assignGun (std::fstream &file, long slotAddress, short slotLength, const std::string &weapon);

//void assignRandomGun(std::fstream &file, long slotAddress, short slotLength);

#endif // FUNCTIONS_H
