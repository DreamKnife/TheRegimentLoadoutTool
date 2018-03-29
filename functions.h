#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "variables.h"


int getRandomNumber(int min, int max);

AssignmentResult assignWeapon (std::fstream &file, int slotAddress, int slotLength, const std::string &weapon);

#endif // FUNCTIONS_H
