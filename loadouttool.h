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

    void on_pushButton_clicked();

private:
    Ui::LoadoutTool *ui;
};

#endif // LOADOUTTOOL_H
