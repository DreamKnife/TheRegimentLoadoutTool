#ifndef QCOMBOBOXCUSTOM_H
#define QCOMBOBOXCUSTOM_H

#include <QComboBox>

#include "weaponslot.h"

class QComboBoxCustom : public QComboBox
{
    Q_OBJECT
public:

    explicit QComboBoxCustom(QWidget *parent = nullptr);

    ~QComboBoxCustom();

    void setCurrentIndexFromWeapon(WeaponSlot &slot);

};

#endif // QCOMBOBOXCUSTOM_H
