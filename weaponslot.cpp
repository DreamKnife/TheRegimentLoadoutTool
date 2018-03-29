#include "weaponslot.h"
#include <QMessageBox>

// constructor definition
WeaponSlot::WeaponSlot(const std::string &fileName, int filePosition, int length)
    : m_fileName(fileName), m_filePosition(filePosition), m_length(length)
{
}

// takes a weapon slot and fills it with a specific weapon
void WeaponSlot::assignWeapon (const std::string &weapon)
{

    m_file.open(m_fileName);

    //only operate if the file stream is working
    while (m_file.good())
    {

        // if slot address is less than or equal to 0 it's definitely invalid, report an error and back out
        if (m_filePosition <= 0)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error: Invalid file address passed to WeaponSlot::assignWeapon().");
            msgBox.exec();
            m_file.close();
            return;
        }

        // if the weapon passed in is too big for the slot print error and return
        if (weapon.length() > m_length)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error: Weapon passed to WeaponSlot::assignWeapon() is too large.");
            msgBox.exec();
            m_file.close();
            return;
        }

        m_file.seekg(m_filePosition, std::ios::beg);
        std::string tempWeapon{weapon};

        int lengthDifference{m_length - tempWeapon.length()}; // calculate length difference

        // add empty spaces to the weapon as many times as needed to match the length
        // of the slot it's going to fill
        for (int i{0}; i < lengthDifference; ++i)
        {
            tempWeapon.push_back(0x00);
        }

        m_file << tempWeapon; // write the prepared weapon string to the file
        m_file.close();
        return;
    }

    // something went wrong with the file stream
    QMessageBox msgBox(QMessageBox::Critical, "Error", "File stream failure in WeaponSlot::assignWeapon().");
    msgBox.exec();
}

// reads and returns the current weapon in the slot
std::string WeaponSlot::getWeapon()
{
    m_file.open(m_fileName);

    //only operate if the file stream is working
    while (m_file.good())
    {

        // if slot address is less than or equal to 0 it's definitely invalid, report an error and back out
        if (m_filePosition <= 0)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error: Invalid file address passed to WeaponSlot::getWeapon().");
            msgBox.exec();
            m_file.close();
            return "Error";
        }

        m_file.seekg(m_filePosition, std::ios::beg);
        std::string tempWeapon;

        // build a string one character at a time
        // there will be a valid iteration where the current character is
        // 'n' and the character before that is 'p'.  This is because all
        // the weapons that can be in these slots end in "_wpn".
        // "pn" serves as a terminator.
        // the loop can technically run until the string is as long as the
        // slot itself + 1.
        char currentChar, previousChar;
        for (int i{1}; i < m_length + 1; ++i, previousChar = currentChar)
        {
            currentChar = m_file.get();
            tempWeapon.push_back(currentChar);

            if (currentChar == 'n')
            {
                if (previousChar == 'p')
                {
                    break; // exit loop, that's the end of the weapon value
                }
            }
            m_file.seekg(m_filePosition +i, std::ios::beg);
        }

        m_file.close();
        return tempWeapon;
    }

    // something went wrong with the file stream
    QMessageBox msgBox(QMessageBox::Critical, "Error", "File stream failure in WeaponSlot::getWeapon().");
    msgBox.exec();
    return "Error";
}
