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
WeaponSlot defaultKnife(sasGame, 0x030ED3, 26);

WeaponSlot defaultP226(sasChars, 0x731F, 22);
WeaponSlot defaultM1100(sasChars, 0x733B, 20);
WeaponSlot defaultFlash(sasChars, 0x7355, 26);
WeaponSlot defaultFrag(sasChars, 0x7371, 27);
WeaponSlot defaultGas(sasChars, 0x738E, 32);

WeaponSlot aMp5k(sasChars, 0xE5D7, 22);
WeaponSlot aMp5klss(sasChars, 0xE736, 27);
WeaponSlot aMp5sd(sasChars, 0xE89F, 24);
    WeaponSlot aMp5sdSocom(sasChars, 0xE8BD, 20);
WeaponSlot aMp5sdlss(sasChars, 0xEA1B, 28);
    WeaponSlot aMp5sdlssSocom(sasChars, 0xEA3D, 20);
WeaponSlot aMp5lss(sasChars, 0xED0B, 26);
WeaponSlot aMp5lss2(sasChars, 0xEE72, 26);

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

    ui->comboBox->setCurrentIndexFromWeapon(defaultMP5);
    ui->cbKnife->setCurrentIndexFromWeapon(defaultKnife);

    ui->cbP226->setCurrentIndexFromWeapon(defaultP226);
    ui->cbM1100->setCurrentIndexFromWeapon(defaultM1100);
    ui->cbFlash->setCurrentIndexFromWeapon(defaultFlash);
    ui->cbFrag->setCurrentIndexFromWeapon(defaultFrag);
    ui->cbGas->setCurrentIndexFromWeapon(defaultGas);

    ui->cbAMp5k->setCurrentIndexFromWeapon(aMp5k);
    ui->cbAMp5klss->setCurrentIndexFromWeapon(aMp5klss);
    ui->cbAMp5sd->setCurrentIndexFromWeapon(aMp5sd);
        ui->cbAMp5sdSocom->setCurrentIndexFromWeapon(aMp5sdSocom);
    ui->cbAMp5sdlss->setCurrentIndexFromWeapon(aMp5sdlss);
        ui->cbAMp5sdlssSocom->setCurrentIndexFromWeapon(aMp5sdlssSocom);
    ui->cbAMp5lss->setCurrentIndexFromWeapon(aMp5lss);


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

    defaultMP5.assignGun(weapons[index]);
}

void LoadoutTool::on_cbKnife_activated(int index)
{
    defaultKnife.assignGun(weapons[index]);
}

void LoadoutTool::on_cbP226_activated(int index)
{
    defaultP226.assignGun(weapons[index]);
}

void LoadoutTool::on_cbM1100_activated(int index)
{
    defaultM1100.assignGun(weapons[index]);
}

void LoadoutTool::on_cbFlash_activated(int index)
{
    defaultFlash.assignGun(weapons[index]);
}

void LoadoutTool::on_cbFrag_activated(int index)
{
    defaultFrag.assignGun(weapons[index]);
}

void LoadoutTool::on_cbGas_activated(int index)
{
    defaultGas.assignGun(weapons[index]);
}

void LoadoutTool::on_cbAMp5k_activated(int index)
{
    aMp5k.assignGun(weapons[index]);
}

void LoadoutTool::on_cbAMp5klss_activated(int index)
{
    aMp5klss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbAMp5sd_activated(int index)
{
    aMp5sd.assignGun(weapons[index]);
}

void LoadoutTool::on_cbAMp5sdSocom_activated(int index)
{
    aMp5sdSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbAMp5sdlss_activated(int index)
{
    aMp5sdlss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbAMp5sdlssSocom_activated(int index)
{
    aMp5sdlssSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbAMp5lss_activated(int index)
{
    aMp5lss.assignGun(weapons[index]);
}
