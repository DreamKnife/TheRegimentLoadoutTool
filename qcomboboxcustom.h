#ifndef QCOMBOBOXCUSTOM_H
#define QCOMBOBOXCUSTOM_H

#include <QComboBox>
#include <QMessageBox>

class QComboBoxCustom : public QComboBox
{
    Q_OBJECT
public:

    explicit QComboBoxCustom(QWidget *parent = nullptr);

    ~QComboBoxCustom();

public slots:
    void slot1();

};

#endif // QCOMBOBOXCUSTOM_H
