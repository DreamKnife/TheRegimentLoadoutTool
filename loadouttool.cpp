#include "loadouttool.h"
#include "ui_loadouttool.h"

#include <fstream>
#include <string>
#include "variables.h"
#include "functions.h"
#include "weaponslot.h"
#include <QMessageBox>

// *** Shared Equipment ***

WeaponSlot defaultMp5(sasGame, 0x030E95, 21);
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

// *** Terrorists Shared Equipment ***

WeaponSlot tFragT(sasChars, 0x7103, 31);
WeaponSlot tMolotov(sasChars, 0x7124, 31);

// *** Training ***

WeaponSlot trainingMp5(sasChars, 0xEFD6, 24);
WeaponSlot trainingMp52(sasChars, 0xF3CD, 24);
WeaponSlot trainingMp5Empty(sasChars, 0xF7DE, 33);
WeaponSlot trainingMp5Wingman(sasChars, 0x0107FD, 24);

LoadoutTool::LoadoutTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadoutTool)
{
    ui->setupUi(this);

    // *** Shared Equipment ***

    ui->cbDefaultMp5->setCurrentIndexFromWeapon(defaultMp5);
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

    // *** Terrorists Shared Equipment ***

    if (tFragT.getWeapon() == fragt)
    {
        ui->cbTFrag->setCurrentIndex(25);
    }
    else if (tFragT.getWeapon() == molotov)
    {
        ui->cbTFrag->setCurrentIndex(26);
    }
    else
    {
        ui->cbTFrag->setCurrentIndexFromWeapon(tFragT);
    }

    if (tMolotov.getWeapon() == fragt)
    {
        ui->cbTMolotov->setCurrentIndex(25);
    }
    else if (tMolotov.getWeapon() == molotov)
    {
        ui->cbTMolotov->setCurrentIndex(26);
    }
    else
    {
        ui->cbTMolotov->setCurrentIndexFromWeapon(tMolotov);
    }

    // *** Training ***

    if (trainingMp5Empty.getWeapon() == mp5empty)
    {
        ui->cbMp5Empty->setCurrentIndex(26);
    }
    else
    {
        ui->cbMp5Empty->setCurrentIndexFromWeapon(trainingMp5Empty);
    }

    if (trainingMp5.getWeapon() == mp5training)
    {
        ui->cbMp5Training->setCurrentIndex(17);
    }
    else
    {
        ui->cbMp5Training->setCurrentIndexFromWeapon(trainingMp5);
    }

    if (trainingMp52.getWeapon() == mp5training)
    {
        ui->cbMp5Training2->setCurrentIndex(17);
    }
    else
    {
        ui->cbMp5Training2->setCurrentIndexFromWeapon(trainingMp52);
    }

    if (trainingMp5Wingman.getWeapon() == mp5training)
    {
        ui->cbMp5Training3->setCurrentIndex(17);
    }
    else
    {
        ui->cbMp5Training3->setCurrentIndexFromWeapon(trainingMp5Wingman);
    }

    // hide the unused boxes
    ui->label_17->hide();
    ui->cbBMp5sd->hide();
    ui->label_18->hide();
    ui->cbBMp5sdSocom->hide();
    ui->label_23->hide();
    ui->cbCMp5klss->hide();
    ui->label_24->hide();
    ui->cbCMp5sd->hide();
    ui->label_25->hide();
    ui->cbCMp5sdSocom->hide();
    ui->label_31->hide();
    ui->cbDMp5sd->hide();
    ui->label_32->hide();
    ui->cbDMp5sdSocom->hide();

}

LoadoutTool::~LoadoutTool()
{
    delete ui;
}

// *** Shared Equipment ***

void LoadoutTool::on_cbDefaultMp5_activated(int index)
{
    defaultMp5.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbKnife_activated(int index)
{
    defaultKnife.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbP226_activated(int index)
{
    defaultP226.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbM1100_activated(int index)
{
    defaultM1100.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbFlash_activated(int index)
{
    defaultFlash.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbFrag_activated(int index)
{
    defaultFrag.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbGas_activated(int index)
{
    defaultGas.assignWeapon(weapons[index]);
}

// *** SAS Trooper A ***

void LoadoutTool::on_cbAMp5k_activated(int index)
{
    aMp5k.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbAMp5klss_activated(int index)
{
    aMp5klss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbAMp5sd_activated(int index)
{
    aMp5sd.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbAMp5sdSocom_activated(int index)
{
    aMp5sdSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbAMp5sdlss_activated(int index)
{
    aMp5sdlss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbAMp5sdlssSocom_activated(int index)
{
    aMp5sdlssSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbAMp5lss_activated(int index)
{
    aMp5lss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbAMp5s_activated(int index)
{
    aMp5s.assignWeapon(weapons[index]);
}

// *** SAS Trooper B ***

void LoadoutTool::on_cbBMp5k_activated(int index)
{
    bMp5k.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbBMp5klss_activated(int index)
{
    bMp5klss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbBMp5sd_activated(int index)
{
    bMp5sd.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbBMp5sdSocom_activated(int index)
{
    bMp5sdSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbBMp5sdlss_activated(int index)
{
    bMp5sdlss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbBMp5sdlssSocom_activated(int index)
{
    bMp5sdlssSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbBMp5lss_activated(int index)
{
    bMp5lss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbBMp5s_activated(int index)
{
    bMp5s.assignWeapon(weapons[index]);
}

// *** SAS Trooper C ***

void LoadoutTool::on_cbCMp5k_activated(int index)
{
    cMp5k.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbCMp5klss_activated(int index)
{
    cMp5klss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbCMp5sd_activated(int index)
{
    cMp5sd.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbCMp5sdSocom_activated(int index)
{
    cMp5sdSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbCMp5sdlss_activated(int index)
{
    cMp5sdlss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbCMp5sdlssSocom_activated(int index)
{
    cMp5sdlssSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbCMp5lss_activated(int index)
{
    cMp5lss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbCMp5s_activated(int index)
{
    cMp5s.assignWeapon(weapons[index]);
}

// *** SAS Trooper D ***

void LoadoutTool::on_cbDMp5k_activated(int index)
{
    dMp5k.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbDMp5klss_activated(int index)
{
    dMp5klss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbDMp5sd_activated(int index)
{
    dMp5sd.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbDMp5sdSocom_activated(int index)
{
    dMp5sdSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbDMp5sdlss_activated(int index)
{
    dMp5sdlss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbDMp5sdlssSocom_activated(int index)
{
    dMp5sdlssSocom.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbDMp5lss_activated(int index)
{
    dMp5lss.assignWeapon(weapons[index]);
}

void LoadoutTool::on_cbDMp5s_activated(int index)
{
    dMp5s.assignWeapon(weapons[index]);
}

// *** Terrorists ***

void LoadoutTool::on_pbTApply_clicked()
{
    bool operationComplete{false};
    const terroristWeaponSlot *addressesToReplace{nullptr};
    int addressesToReplaceSize{0};
    const std::string *potentialReplacements{nullptr};
    int potentialReplacementsSize{0};

    switch(ui->cbTReplace->currentIndex())
    {
    case 0:
        addressesToReplace = terrorSlotBoth;
        addressesToReplaceSize = terrorSlotBothSize;
        break;
    case 1:
        addressesToReplace = terrorSlotPrimaries;
        addressesToReplaceSize = terrorSlotPrimariesSize;
        break;
    case 2:
        addressesToReplace = terrorSlotSecondaries;
        addressesToReplaceSize = terrorSlotSecondariesSize;
        break;
    }

    switch(ui->cbTReplaceWith->currentIndex())
    {
    case 0:
        potentialReplacements = terrorBoth;
        potentialReplacementsSize = terrorBothSize;
        break;
    case 1:
        potentialReplacements = terrorPrimaries;
        potentialReplacementsSize = terrorPrimariesSize;
        break;
    case 2:
        potentialReplacements = terrorSecondaries;
        potentialReplacementsSize = terrorSecondariesSize;
        break;
    }

    std::fstream fileGame (sasGame);
    std::fstream fileChars (sasChars);

    while (fileGame.good() && fileChars.good())
    {
        int randomNumber{0};
        AssignmentResult lastResult;
        for (int i{0}; i < addressesToReplaceSize;)
        {
            if (potentialReplacements == terrorSecondaries && addressesToReplace[i].length < 20) // with pistols only as replacements, if the slot is too small for the smallest pistol then set that slot to have no weapon
            {
                lastResult = assignWeapon(fileChars, addressesToReplace[i].filePosition, addressesToReplace[i].length, none);
                if (lastResult == AssignmentResult::SUCCESS)
                {
                    ++i;
                }
            }

            else
            {
                randomNumber = getRandomNumber(0, potentialReplacementsSize - 1);
                lastResult = assignWeapon(fileChars, addressesToReplace[i].filePosition, addressesToReplace[i].length, potentialReplacements[randomNumber]);

                if (lastResult == AssignmentResult::SUCCESS)
                {
                    ++i;
                }
            }
        }

        // handle default ak47 seperately
        // if replacing primary weapon slot
        if (addressesToReplace == terrorSlotBoth || addressesToReplace == terrorSlotPrimaries)
        {
            // and picking from secondaries only
            if (potentialReplacements == terrorSecondaries)
            {
                assignWeapon(fileGame, defaultAK47.filePosition, defaultAK47.length, none); // none of the 4 secondaries will fit in this slot so set it to be empty / no weapon
            }
            // or picking from primaries and secondaries
            else if (potentialReplacements == terrorBoth)
            {
                assignWeapon(fileGame, defaultAK47.filePosition, defaultAK47.length, potentialReplacements[getRandomNumber(0, 3)]); // anything with a length of 19 or less will fit in this slot
            }
            // or picking from primaries only
            else if (potentialReplacements == terrorPrimaries)
            {
                assignWeapon(fileGame, defaultAK47.filePosition, defaultAK47.length, potentialReplacements[getRandomNumber(0, 3)]); // anything with a length of 19 or less will fit in this slot
            }

        }

        // handle default browning bda seperately
        // if replacing secondary weapon slot
        if (addressesToReplace == terrorSlotBoth || addressesToReplace == terrorSlotSecondaries)
        {
            // and picking from secondaries only
            if (potentialReplacements == terrorSecondaries)
            {
                assignWeapon(fileChars, defaultBDA.filePosition, defaultBDA.length, potentialReplacements[getRandomNumber(0, 3)]); // any of the 4 secondaries will fit in this slot
            }
            // or picking from primaries and secondaries
            else if (potentialReplacements == terrorBoth)
            {
                assignWeapon(fileChars, defaultBDA.filePosition, defaultBDA.length, potentialReplacements[getRandomNumber(0, 18)]); // anything with a length of 27 or less will fit in this slot
            }
            // or picking from primaries only
            else if (potentialReplacements == terrorPrimaries)
            {
                assignWeapon(fileChars, defaultBDA.filePosition, defaultBDA.length, potentialReplacements[getRandomNumber(0, 14)]); // anything with a length of 27 or less will fit in this slot
            }

        }
        operationComplete = true;
        break;
    }

    if (operationComplete)
    {
        fileGame.close();
        fileChars.close();

        QMessageBox msgBox(QMessageBox::NoIcon, "Done", "Randomization complete.");
        msgBox.exec();
    }
    else if (!operationComplete)
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "File stream failure in LoadoutTool::on_pbTApply_clicked().");
        msgBox.exec();
    }
}

void LoadoutTool::on_pbTClear_clicked()
{
    bool operationComplete{false};
    std::fstream fileGame (sasGame);
    std::fstream fileChars (sasChars);

    while (fileGame.good() && fileChars.good())
    {
        for (auto &element : terrorSlotBoth)
        {
            assignWeapon(fileChars, element.filePosition, element.length, none);
        }

        assignWeapon(fileGame, defaultAK47.filePosition, defaultAK47.length, none);
        assignWeapon(fileChars, defaultBDA.filePosition, defaultBDA.length, none);
        operationComplete = true;
        break;
    }

    if (operationComplete)
    {
        fileGame.close();
        fileChars.close();

        QMessageBox msgBox(QMessageBox::NoIcon, "Done", "All terrorists primary and secondary weapons set to none.");
        msgBox.exec();
    }
    else if (!operationComplete)
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "File stream failure in LoadoutTool::on_pbTClear_clicked().");
        msgBox.exec();
    }
}

// *** Terrorists Shared Equipment ***

void LoadoutTool::on_cbTFrag_activated(int index)
{
    if (index == 25)
    {
        tFragT.assignWeapon(fragt);
    }
    else if (index == 26)
    {
        tFragT.assignWeapon(molotov);
    }
    else
    {
        tFragT.assignWeapon(weapons[index]);
    }
}

void LoadoutTool::on_cbTMolotov_activated(int index)
{
    if (index == 25)
    {
        tMolotov.assignWeapon(fragt);
    }
    else if (index == 26)
    {
        tMolotov.assignWeapon(molotov);
    }
    else
    {
        tMolotov.assignWeapon(weapons[index]);
    }
}

// *** Training ***

void LoadoutTool::on_cbMp5Empty_activated(int index)
{
    if (index == 26)
    {
        trainingMp5Empty.assignWeapon(mp5empty);
    }
    else
    {
        trainingMp5Empty.assignWeapon(weapons[index]);
    }
}

void LoadoutTool::on_cbMp5Training_activated(int index)
{
    if (index == 17)
    {
        trainingMp5.assignWeapon(mp5training);
    }
    else
    {
        trainingMp5.assignWeapon(weapons[index]);
    }
}

void LoadoutTool::on_cbMp5Training2_activated(int index)
{
    if (index == 17)
    {
        trainingMp52.assignWeapon(mp5training);
    }
    else
    {
        trainingMp52.assignWeapon(weapons[index]);
    }
}

void LoadoutTool::on_cbMp5Training3_activated(int index)
{
    if (index == 17)
    {
        trainingMp5Wingman.assignWeapon(mp5training);
    }
    else
    {
        trainingMp5Wingman.assignWeapon(weapons[index]);
    }
}
