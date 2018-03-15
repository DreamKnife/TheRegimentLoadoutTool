#ifndef WEAPONSLOT_H
#define WEAPONSLOT_H

#include <string>
#include <fstream>

class WeaponSlot
{
private:
    std::fstream m_file;
    std::string m_fileName;
    int m_filePosition{0};
    int m_length{0};

public:
    WeaponSlot(const std::string &fileName, int filePosition, int length);

    ~WeaponSlot()
    {
        m_file.close();
    }

    void assignWeapon (const std::string &weapon);

    std::string getWeapon();
};

#endif // WEAPONSLOT_H
