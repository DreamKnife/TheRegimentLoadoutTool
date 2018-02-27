#ifndef QCOMBOBOXTEST_H
#define QCOMBOBOXTEST_H

#include <QComboBox>
#include <QMessageBox>

class QcomboBoxTest : public QComboBox
{
public:

    QcomboBoxTest(QWidget *parent = Q_NULLPTR)
        : QComboBox(parent)
    {
        QMessageBox msgBox(QMessageBox::Critical, "Error", "Error opening SASChars.u  Please confirm this executable is in the same directory as the file SASChars.u.");
        msgBox.exec();
    }

};

#endif // QCOMBOBOXTEST_H
