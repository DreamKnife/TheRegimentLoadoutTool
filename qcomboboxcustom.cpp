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

void QComboBoxCustom::slot1()
{
    QMessageBox msgBox(QMessageBox::Information, "slot1()", "QComboBoxCustom::slot1()");
    msgBox.exec();
}
