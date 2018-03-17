#include "functions.h"
#include <string>
#include <cstdlib> // for rand() and srand() and exit()
#include <ctime> // for time()
//#include <cstdlib>
#include <iostream>
#include <fstream>
#include <QMessageBox>

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
// Assumes max - min <= RAND_MAX
// from http://www.learncpp.com/cpp-tutorial/59-random-number-generation/
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// takes a weapon slot and fills it with a specific weapon
AssignmentResult assignWeapon(std::fstream &file, int slotAddress, int slotLength, const std::string &weapon)
{
    //only operate if the file stream is working
    while (file.good())
    {

        // if slot address is less than or equal to 0 it's definitely invalid, report an error and back out
        if (slotAddress <= 0)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error: Invalid file address passed to assignWeapon().");
            msgBox.exec();
            return AssignmentResult::INVALIDADDRESS;
        }

        // if the weapon passed in is too big for the slot return error code
        if (weapon.length() > slotLength)
        {
            return AssignmentResult::VALUETOOLARGE;
        }

        file.seekg(slotAddress, std::ios::beg);
        std::string tempWeapon{weapon};

        int lengthDifference{slotLength - tempWeapon.length()}; // calculate length difference

        // add empty spaces to the weapon as many times as needed to match the length
        // of the slot it's going to fill
        for (int i{0}; i < lengthDifference; ++i)
        {
            tempWeapon.push_back(0x00);
        }

        file << tempWeapon; // write the prepared weapon string to the file
        return AssignmentResult::SUCCESS;

    }

    // something went wrong with the file stream
    // PROBABLY NEED BETTER ERROR MESSAGE HERE, MORE SPECIFIC
    QMessageBox msgBox(QMessageBox::Critical, "Error", "Error while assigning weapon.");
    msgBox.exec();
    return AssignmentResult::FILESTREAMERROR;
}

//void randomizeWeaponArray(const std::fstream &file, const )

/*

// takes a gun slot and fills it with a specific gun
void assignGun (std::fstream &file, long slotAddress, short slotLength, const std::string &weapon)
{
    // if slot address is less than or equal to 0 it's definitely invalid, report an error and back out
    if (slotAddress <= 0)
    {
        //std::cerr << "Error: invalid slot address passed to assignGun()" << file << '\n';
        return;
    }

    // if the weapon passed in is too big for the slot print error and return
    if (weapon.length() > slotLength)
    {
        // NEED ERROR MESSAGE HERE
        return;
    }

    file.seekg(slotAddress, std::ios::beg);
    std::string tempWeapon{weapon};

    short lengthDifference{slotLength - tempWeapon.length()}; // calculate length difference

    // add empty spaces to the weapon as many times as needed to match the length
    // of the slot it's going to fill
    for (short i{0}; i < lengthDifference; ++i)
        {
            tempWeapon.push_back(0x00);
        }

    file << tempWeapon; // write the prepared weapon string to the file

    if (!file.good())
        {
            //std::cerr << "Error processing" << file << '\n';
        }
}

*/
