#include "qcomboboxcustom.h"
#include <QCoreApplication>

#include "variables.h"

QComboBoxCustom::QComboBoxCustom(QWidget *parent) : QComboBox(parent)
{
}

QComboBoxCustom::~QComboBoxCustom()
{
}

void QComboBoxCustom::setCurrentIndexFromWeapon(WeaponSlot &slot)
{
    for (int i{0}; i < weapons.size(); ++i)
    {
        if (slot.getWeapon() == weapons[i])
            this->setCurrentIndex(i);
        if (slot.getWeapon() == "Error")
            break;
    }
}

