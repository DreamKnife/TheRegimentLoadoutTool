#ifndef WEAPONSLOT_H
#define WEAPONSLOT_H

#include <string>
#include <fstream>

#include <QMessageBox>

class WeaponSlot
{
private:
    std::fstream m_file;
    std::string m_fileName{"SASChars.u"};
    long m_filePosition{0};
    short m_length{0};

public:
    WeaponSlot(std::string fileName, long filePosition, short length)
        : m_fileName(fileName), m_filePosition(filePosition), m_length(length)
    {
        //m_file.open("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASChars.u");
        m_file.open(fileName);

        // if file fails to open print error
        if (!m_file)
        {
            QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASChars.u  Please confirm this executable is in the same directory as the file SASChars.u.");
            msgBox.exec();
        }
    }

    ~WeaponSlot()
    {
        m_file.close();
    }

    void assignGun (const std::string &weapon);
};

#endif // WEAPONSLOT_H
