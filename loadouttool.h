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
    void on_cbDefaultmp5_activated(int index);

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

    void on_cbAMp5s_activated(int index);

    void on_cbBMp5k_activated(int index);

    void on_cbBMp5klss_activated(int index);

    void on_cbBMp5sd_activated(int index);

    void on_cbBMp5sdSocom_activated(int index);

    void on_cbBMp5sdlss_activated(int index);

    void on_cbBMp5sdlssSocom_activated(int index);

    void on_cbBMp5lss_activated(int index);

    void on_cbBMp5s_activated(int index);

    void on_cbCMp5k_activated(int index);

    void on_cbCMp5klss_activated(int index);

    void on_cbCMp5sd_activated(int index);

    void on_cbCMp5sdSocom_activated(int index);

    void on_cbCMp5sdlss_activated(int index);

    void on_cbCMp5sdlssSocom_activated(int index);

    void on_cbCMp5lss_activated(int index);

    void on_cbCMp5s_activated(int index);

    void on_cbDMp5k_activated(int index);

    void on_cbDMp5klss_activated(int index);

    void on_cbDMp5sd_activated(int index);

    void on_cbDMp5sdSocom_activated(int index);

    void on_cbDMp5sdlss_activated(int index);

    void on_cbDMp5sdlssSocom_activated(int index);

    void on_cbDMp5lss_activated(int index);

    void on_cbDMp5s_activated(int index);

    void on_pbTApply_clicked();

    void on_pbTClear_clicked();

    void on_cbTFrag_activated(int index);

    void on_cbTMolotov_activated(int index);

private:
    Ui::LoadoutTool *ui;
};

#endif // LOADOUTTOOL_H
