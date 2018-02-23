#include "weaponslot.h"
#include <QMessageBox>

// takes a gun slot and fills it with a specific gun
void WeaponSlot::assignGun (const std::string &weapon)
{

    //only operate if the file stream is working
    while (m_file.good())
    {

        // if slot address is less than or equal to 0 it's definitely invalid, report an error and back out
        if (m_filePosition <= 0)
        {
            //QMessageBox::Critical msgBox;
            //msgBox.setText("Error: Invalid file address passed to assignGun().");
            //msgBox.exec();
            return;
        }

        // if the weapon passed in is too big for the slot print error and return
        if (weapon.length() > m_length)
        {
            //QMessageBox::Critical msgBox;
            //msgBox.setText("Error: Weapon passed to assignGun() is too large.");
            //msgBox.exec();
            return;
        }

        m_file.seekg(m_filePosition, std::ios::beg);
        std::string tempWeapon{weapon};

        short lengthDifference{m_length - tempWeapon.length()}; // calculate length difference

        // add empty spaces to the weapon as many times as needed to match the length
        // of the slot it's going to fill
        for (short i{0}; i < lengthDifference; ++i)
        {
            tempWeapon.push_back(0x00);
        }

        m_file << tempWeapon; // write the prepared weapon string to the file
        m_file << std::flush; // force program to actually write to the file
        return;
    }

    //something went wrong with the file stream
    //QMessageBox::Critical msgBox;
    //msgBox.setText("Error: Unable to access file.");
    //msgBox.exec();
}
