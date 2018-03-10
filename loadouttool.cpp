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

// *** Shared Equipment ***

WeaponSlot defaultMP5(sasGame, 0x030E95, 21);
WeaponSlot defaultKnife(sasGame, 0x030ED3, 26);

WeaponSlot defaultP226(sasChars, 0x731F, 22);
WeaponSlot defaultM1100(sasChars, 0x733B, 20);
WeaponSlot defaultFlash(sasChars, 0x7355, 26);
WeaponSlot defaultFrag(sasChars, 0x7371, 27);
WeaponSlot defaultGas(sasChars, 0x738E, 32);

// *** SAS Trooper A ***

WeaponSlot aMp5k(sasChars, 0xE5D7, 22);
WeaponSlot aMp5klss(sasChars, 0xE736, 27);
WeaponSlot aMp5sd(sasChars, 0xE89F, 24);
    WeaponSlot aMp5sdSocom(sasChars, 0xE8BD, 20);
WeaponSlot aMp5sdlss(sasChars, 0xEA1B, 28);
    WeaponSlot aMp5sdlssSocom(sasChars, 0xEA3D, 20);
WeaponSlot aMp5lss(sasChars, 0xED0B, 26);
WeaponSlot aMp5s(sasChars, 0xEE72, 26);

// *** SAS Trooper B ***

WeaponSlot bMp5k(sasChars, 0xFCDC, 22);
WeaponSlot bMp5klss(sasChars, 0xFD95, 27);
WeaponSlot bMp5sd(sasChars, 0xFF04, 24);
    WeaponSlot bMp5sdSocom(sasChars, 0xFF22, 20);
WeaponSlot bMp5sdlss(sasChars, 0x010083, 28);
    WeaponSlot bMp5sdlssSocom(sasChars, 0x0100A5, 20);
WeaponSlot bMp5lss(sasChars, 0x010373, 26);
WeaponSlot bMp5s(sasChars, 0x0104E0, 26);

// *** SAS Trooper C ***

WeaponSlot cMp5k(sasChars, 0x010B95, 22);
WeaponSlot cMp5klss(sasChars, 0x010CFA, 27);
WeaponSlot cMp5sd(sasChars, 0x010E69, 24);
    WeaponSlot cMp5sdSocom(sasChars, 0x010E87, 20);
WeaponSlot cMp5sdlss(sasChars, 0x010FEB, 28);
    WeaponSlot cMp5sdlssSocom(sasChars, 0x01100D, 20);
WeaponSlot cMp5lss(sasChars, 0x0112DB, 26);
WeaponSlot cMp5s(sasChars, 0x011448, 26);

// *** SAS Trooper D ***

WeaponSlot dMp5k(sasChars, 0x011C37, 22);
WeaponSlot dMp5klss(sasChars, 0x011D98, 27);
WeaponSlot dMp5sd(sasChars, 0x011F03, 24);
    WeaponSlot dMp5sdSocom(sasChars, 0x011F21, 20);
WeaponSlot dMp5sdlss(sasChars, 0x012084, 28);
    WeaponSlot dMp5sdlssSocom(sasChars, 0x0120A6, 20);
WeaponSlot dMp5lss(sasChars, 0x012378, 26);
WeaponSlot dMp5s(sasChars, 0x0124E1, 26);

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

    // *** Shared Equipment ***

    ui->comboBox->setCurrentIndexFromWeapon(defaultMP5);
    ui->cbKnife->setCurrentIndexFromWeapon(defaultKnife);

    ui->cbP226->setCurrentIndexFromWeapon(defaultP226);
    ui->cbM1100->setCurrentIndexFromWeapon(defaultM1100);
    ui->cbFlash->setCurrentIndexFromWeapon(defaultFlash);
    ui->cbFrag->setCurrentIndexFromWeapon(defaultFrag);
    ui->cbGas->setCurrentIndexFromWeapon(defaultGas);

    // *** SAS Trooper A ***

    ui->cbAMp5k->setCurrentIndexFromWeapon(aMp5k);
    ui->cbAMp5klss->setCurrentIndexFromWeapon(aMp5klss);
    ui->cbAMp5sd->setCurrentIndexFromWeapon(aMp5sd);
        ui->cbAMp5sdSocom->setCurrentIndexFromWeapon(aMp5sdSocom);
    ui->cbAMp5sdlss->setCurrentIndexFromWeapon(aMp5sdlss);
        ui->cbAMp5sdlssSocom->setCurrentIndexFromWeapon(aMp5sdlssSocom);
    ui->cbAMp5lss->setCurrentIndexFromWeapon(aMp5lss);
    ui->cbAMp5s->setCurrentIndexFromWeapon(aMp5s);

    // *** SAS Trooper B ***

    ui->cbBMp5k->setCurrentIndexFromWeapon(bMp5k);
    ui->cbBMp5klss->setCurrentIndexFromWeapon(bMp5klss);
    ui->cbBMp5sd->setCurrentIndexFromWeapon(bMp5sd);
        ui->cbBMp5sdSocom->setCurrentIndexFromWeapon(bMp5sdSocom);
    ui->cbBMp5sdlss->setCurrentIndexFromWeapon(bMp5sdlss);
        ui->cbBMp5sdlssSocom->setCurrentIndexFromWeapon(bMp5sdlssSocom);
    ui->cbBMp5lss->setCurrentIndexFromWeapon(bMp5lss);
    ui->cbBMp5s->setCurrentIndexFromWeapon(bMp5s);

    // *** SAS Trooper C ***

    ui->cbCMp5k->setCurrentIndexFromWeapon(cMp5k);
    ui->cbCMp5klss->setCurrentIndexFromWeapon(cMp5klss);
    ui->cbCMp5sd->setCurrentIndexFromWeapon(cMp5sd);
        ui->cbCMp5sdSocom->setCurrentIndexFromWeapon(cMp5sdSocom);
    ui->cbCMp5sdlss->setCurrentIndexFromWeapon(cMp5sdlss);
        ui->cbCMp5sdlssSocom->setCurrentIndexFromWeapon(cMp5sdlssSocom);
    ui->cbCMp5lss->setCurrentIndexFromWeapon(cMp5lss);
    ui->cbCMp5s->setCurrentIndexFromWeapon(cMp5s);

    // *** SAS Trooper D ***

    ui->cbDMp5k->setCurrentIndexFromWeapon(dMp5k);
    ui->cbDMp5klss->setCurrentIndexFromWeapon(dMp5klss);
    ui->cbDMp5sd->setCurrentIndexFromWeapon(dMp5sd);
        ui->cbDMp5sdSocom->setCurrentIndexFromWeapon(dMp5sdSocom);
    ui->cbDMp5sdlss->setCurrentIndexFromWeapon(dMp5sdlss);
        ui->cbDMp5sdlssSocom->setCurrentIndexFromWeapon(dMp5sdlssSocom);
    ui->cbDMp5lss->setCurrentIndexFromWeapon(dMp5lss);
    ui->cbDMp5s->setCurrentIndexFromWeapon(dMp5s);

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

// *** Shared Equipment ***

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

// *** SAS Trooper A ***

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

void LoadoutTool::on_cbAMp5s_activated(int index)
{
    aMp5s.assignGun(weapons[index]);
}

// *** SAS Trooper B ***

void LoadoutTool::on_cbBMp5k_activated(int index)
{
    bMp5k.assignGun(weapons[index]);
}

void LoadoutTool::on_cbBMp5klss_activated(int index)
{
    bMp5klss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbBMp5sd_activated(int index)
{
    bMp5sd.assignGun(weapons[index]);
}

void LoadoutTool::on_cbBMp5sdSocom_activated(int index)
{
    bMp5sdSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbBMp5sdlss_activated(int index)
{
    bMp5sdlss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbBMp5sdlssSocom_activated(int index)
{
    bMp5sdlssSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbBMp5lss_activated(int index)
{
    bMp5lss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbBMp5s_activated(int index)
{
    bMp5s.assignGun(weapons[index]);
}

// *** SAS Trooper C ***

void LoadoutTool::on_cbCMp5k_activated(int index)
{
    cMp5k.assignGun(weapons[index]);
}

void LoadoutTool::on_cbCMp5klss_activated(int index)
{
    cMp5klss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbCMp5sd_activated(int index)
{
    cMp5sd.assignGun(weapons[index]);
}

void LoadoutTool::on_cbCMp5sdSocom_activated(int index)
{
    cMp5sdSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbCMp5sdlss_activated(int index)
{
    cMp5sdlss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbCMp5sdlssSocom_activated(int index)
{
    cMp5sdlssSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbCMp5lss_activated(int index)
{
    cMp5lss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbCMp5s_activated(int index)
{
    cMp5s.assignGun(weapons[index]);
}

// *** SAS Trooper D ***

void LoadoutTool::on_cbDMp5k_activated(int index)
{
    dMp5k.assignGun(weapons[index]);
}

void LoadoutTool::on_cbDMp5klss_activated(int index)
{
    dMp5klss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbDMp5sd_activated(int index)
{
    dMp5sd.assignGun(weapons[index]);
}

void LoadoutTool::on_cbDMp5sdSocom_activated(int index)
{
    dMp5sdSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbDMp5sdlss_activated(int index)
{
    cMp5sdlss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbDMp5sdlssSocom_activated(int index)
{
    dMp5sdlssSocom.assignGun(weapons[index]);
}

void LoadoutTool::on_cbDMp5lss_activated(int index)
{
    dMp5lss.assignGun(weapons[index]);
}

void LoadoutTool::on_cbDMp5s_activated(int index)
{
    dMp5s.assignGun(weapons[index]);
}
