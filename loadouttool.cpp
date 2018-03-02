#include "loadouttool.h"
#include "ui_loadouttool.h"

#include <fstream>
#include <string>
#include "variables.h"
#include "functions.h"
#include "weaponslot.h"

#include <QTextStream>
#include <QMessageBox>

const std::string sasGame("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASGame.u");
const std::string sasChars("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASChars.u");
WeaponSlot defaultMP5(sasGame, 0x030E95, 21);

// SASGame.u
//WeaponSlot defaultMP5("SASGame.u", 0x030E95, 21);
//WeaponSlot defaultMP5("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASGame.u", 0x030E95, 21);

LoadoutTool::LoadoutTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadoutTool)
{
    ui->setupUi(this);

    // for testing
    //QMessageBox msgBox(QMessageBox::Information, "loadouttool", "LoadoutTool()");
    //msgBox.exec();

    //ui->comboBox->clear();
    defaultMP5.getGun();
}

LoadoutTool::~LoadoutTool()
{
    delete ui;

    // for testing
    //QMessageBox msgBox(QMessageBox::Information, "loadouttool", "~LoadoutTool()");
    //msgBox.exec();

}

void LoadoutTool::on_comboBox_activated(int index)
{
    //QTextStream(stdout) << "index " << index << " selected" << endl;
    //QMessageBox msgBox(QMessageBox::Information, "Clicked", "on_comboBox_currentIndexChanged");
    //msgBox.exec();

    /*
    switch (index)
    {
    case 0:
        defaultMP5.assignGun(mp5);
        break;
    case 1:
        defaultMP5.assignGun(m4a1);
        break;
    case 2:
        defaultMP5.assignGun(mac11);
        break;
    case 3:
        defaultMP5.assignGun(m60);
        break;
    }
    */

    defaultMP5.assignGun(weapons.at(index));

    for (const auto &element : weapons)
    {

    }
}


void LoadoutTool::on_pushButton_clicked()
{
    ui->comboBox->clear();
}
