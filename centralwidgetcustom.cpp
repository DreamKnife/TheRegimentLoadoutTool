#include "centralwidgetcustom.h"
#include <QMessageBox>

centralWidgetCustom::centralWidgetCustom(QWidget *parent) : QWidget(parent)
{
    QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASChars.u  Please confirm this executable is in the same directory as the file SASChars.u.");
    msgBox.exec();
}

centralWidgetCustom::~centralWidgetCustom()
{
    QMessageBox msgBox(QMessageBox::Information, "Close", "~centralWidgetCustom()");
    msgBox.exec();
}
