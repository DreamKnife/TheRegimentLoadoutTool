#ifndef LOADOUTTOOL_H
#define LOADOUTTOOL_H

#include <QMainWindow>

namespace Ui {
class LoadoutTool;
}

class LoadoutTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadoutTool(QWidget *parent = 0);
    ~LoadoutTool();

private slots:
    void on_comboBox_activated(int index);

    void on_cbKnife_activated(int index);

    void on_cbP226_activated(int index);

    void on_cbM1100_activated(int index);

    void on_cbFlash_activated(int index);

    void on_cbFrag_activated(int index);

    void on_cbGas_activated(int index);

    void on_cbAMp5k_activated(int index);

    void on_cbAMp5klss_activated(int index);

    void on_cbAMp5sd_activated(int index);

    void on_cbAMp5sdSocom_activated(int index);

    void on_cbAMp5sdlss_activated(int index);

    void on_cbAMp5sdlssSocom_activated(int index);

    void on_cbAMp5lss_activated(int index);

private:
    Ui::LoadoutTool *ui;
};

#endif // LOADOUTTOOL_H
