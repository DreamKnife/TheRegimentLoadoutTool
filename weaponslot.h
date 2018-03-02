#ifndef WEAPONSLOT_H
#define WEAPONSLOT_H

#include <string>
#include <fstream>

class WeaponSlot
{
private:
    std::fstream m_file;
    std::string m_fileName;
    long m_filePosition{0};
    short m_length{0};

public:
    WeaponSlot(const std::string &fileName, long filePosition, short length);

    ~WeaponSlot()
    {
        m_file.close();
    }

    void assignGun (const std::string &weapon);

    std::string getGun();
};

#endif // WEAPONSLOT_H
