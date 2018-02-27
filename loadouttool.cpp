#include "loadouttool.h"
#include "ui_loadouttool.h"

#include <fstream>
#include "variables.h"
#include "functions.h"
#include "weaponslot.h"

#include <QTextStream>
#include <QMessageBox>

//std::fstream sasGame("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASGame.u");
//std::fstream sasChars("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASChars.u");

// SASGame.u
//WeaponSlot defaultMP5("SASGame.u", 0x030E95, 21);
WeaponSlot defaultMP5("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASGame.u", 0x030E95, 21);

LoadoutTool::LoadoutTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadoutTool)
{
    ui->setupUi(this);
}

LoadoutTool::~LoadoutTool()
{
    delete ui;
}

void LoadoutTool::on_comboBox_activated(int index)
{
    QTextStream(stdout) << "index " << index << " selected" << endl;
    //QMessageBox msgBox(QMessageBox::Information, "Clicked", "on_comboBox_currentIndexChanged");
    //msgBox.exec();
    std::string chosenWeapon;
    switch (index)
    {
    case 0:
        defaultMP5.assignGun(mp5);
        //chosenWeapon = mp5;
        break;
    case 1:
        defaultMP5.assignGun(m4a1);
        //chosenWeapon = m4a1;
        break;
    case 2:
        defaultMP5.assignGun(mac11);
        break;
    case 3:
        defaultMP5.assignGun(m60);
        break;
    }

    //assignGun(sasGame, defaultMP5.filePosition, defaultMP5.length, chosenWeapon);
}

