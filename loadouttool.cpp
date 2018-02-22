#include "loadouttool.h"
#include "ui_loadouttool.h"

#include <fstream>
#include "variables.h"
#include "functions.h"

#include <QTextStream>
#include <QMessageBox>

std::fstream sasGame("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASGame.u");
std::fstream sasChars("C:\\Program Files (x86)\\Konami\\The Regiment\\system\\SASChars.u");

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
    //QTextStream(stdout) << "index " << index << " selected" << endl;
    //QMessageBox msgBox;
    //msgBox.setText("The document has been modified.");
    //msgBox.exec();
    std::string chosenWeapon;
    switch (index)
    {
    case 0:
        chosenWeapon = mp5;
        break;
    case 1:
        chosenWeapon = m4a1;
        break;
    }

    assignGun(sasGame, defaultMP5.filePosition, defaultMP5.length, chosenWeapon);
}
