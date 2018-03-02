#include "weaponslot.h"
#include <QMessageBox>

// constructor definition
WeaponSlot::WeaponSlot(const std::string &fileName, long filePosition, short length)
    : m_fileName(fileName), m_filePosition(filePosition), m_length(length)
{
}

// takes a gun slot and fills it with a specific gun
void WeaponSlot::assignGun (const std::string &weapon)
{

    //m_file.open("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASChars.u");
    m_file.open(m_fileName);

    // if file fails to open print error - two possibilities depending on which file
    if (!m_file)
    {
        if (m_fileName == "SASGame.u")
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASGame.u.  Please confirm this executable is in the same directory as the file SASGame.u.");
            msgBox.exec();
        }

        else if (m_fileName == "SASChars.u")
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASChars.u.  Please confirm this executable is in the same directory as the file SASChars.u.");
            msgBox.exec();
        }
    }

    /*
    // if file fails to open print error
    if (!m_file && m_fileName == "SASGame.u")
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASGame.u.  Please confirm this executable is in the same directory as the file SASGame.u.");
        msgBox.exec();
    }

    // if file fails to open print error
    if (!m_file && m_fileName == "SASChars.u")
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASChars.u.  Please confirm this executable is in the same directory as the file SASChars.u.");
        msgBox.exec();
    }
    */

    //only operate if the file stream is working
    while (m_file.good())
    {

        // if slot address is less than or equal to 0 it's definitely invalid, report an error and back out
        if (m_filePosition <= 0)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error: Invalid file address passed to assignGun().");
            msgBox.exec();
            m_file.close();
            return;
        }

        // if the weapon passed in is too big for the slot print error and return
        if (weapon.length() > m_length)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error: Weapon passed to assignGun() is too large.");
            msgBox.exec();
            m_file.close();
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
        //m_file << std::flush; // force program to actually write to the file
        m_file.close();
        return;
    }

    // something went wrong with the file stream
    // PROBABLY NEED BETTER ERROR MESSAGE HERE, MORE SPECIFIC
    QMessageBox msgBox(QMessageBox::Critical, "Error", "Error while assigning gun.");
    msgBox.exec();
}

// reads and returns the current gun in the slot
std::string WeaponSlot::getGun()
{
    m_file.open(m_fileName);

    // if file fails to open print error - two possibilities depending on which file
    if (!m_file)
    {
        if (m_fileName == "SASGame.u")
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASGame.u.  Please confirm this executable is in the same directory as the file SASGame.u.");
            msgBox.exec();
        }

        else if (m_fileName == "SASChars.u")
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASChars.u.  Please confirm this executable is in the same directory as the file SASChars.u.");
            msgBox.exec();
        }
    }

    //only operate if the file stream is working
    while (m_file.good())
    {

        // if slot address is less than or equal to 0 it's definitely invalid, report an error and back out
        if (m_filePosition <= 0)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error: Invalid file address passed to assignGun().");
            msgBox.exec();
            m_file.close();
            return "Error";
        }

        m_file.seekg(m_filePosition, std::ios::beg);
        std::string tempWeapon;

        // build a string one character at a time
        // there will be a valid iteration where the current character is
        // 'n' and the character before that is 'p'.  This is because all
        // the weapons that can be in these slots end in "_wpn".  Once
        // "pn" servers as a terminator.
        // the loop can technically run until the string is as long as the
        // slot itself.
        char currentChar, previousChar;
        for (int i{1}; i < m_length; ++i, previousChar = currentChar)
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
    // PROBABLY NEED BETTER ERROR MESSAGE HERE, MORE SPECIFIC
    QMessageBox msgBox(QMessageBox::Critical, "Error", "Error while loading gun.");
    msgBox.exec();
    return "Error";
}
