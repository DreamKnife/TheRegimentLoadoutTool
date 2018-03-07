#include "qcomboboxcustom.h"

QComboBoxCustom::QComboBoxCustom(QWidget *parent) : QComboBox(parent)
{
    //QMessageBox msgBox(QMessageBox::Information, "Open", "QComboBoxCustom()");
    //msgBox.exec();

}

QComboBoxCustom::~QComboBoxCustom()
{
    //QMessageBox msgBox(QMessageBox::Information, "Close", "~QComboBoxCustom()");
    //msgBox.exec();
}

void QComboBoxCustom::setCurrentIndexFromWeapon(WeaponSlot &slot)
{
    for (int i{0}; i < weapons.size(); ++i)
    {
        if (slot.getGun() == weapons[i])
            this->setCurrentIndex(i);
    }
}

