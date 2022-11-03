#ifndef DIALOGLEVEL_H
#define DIALOGLEVEL_H

#include <QDialog>
#include <QPixmap>
#include "config/Configurator.h"

namespace Ui {
class DialogLevel;
}

class DialogLevel : public QDialog
{
    Q_OBJECT

public:
    DialogLevel(Config::Configurator *config, QWidget *parent = nullptr);
    ~DialogLevel();

    bool getIsExit() const;
signals:
    void changeLevel(int level);

    void changeSettings();

    void endApp();

public slots:
    void on_exitButton_clicked();

private slots:
    void on_lvl1Button_clicked();

    void on_lvl2Button_clicked();

    void on_settingsButton_clicked();

    void on_saveButton_clicked();

    void on_logComboBox_currentIndexChanged(int index);

private:
    Ui::DialogLevel *ui;
    Config::Configurator *config = nullptr;
    bool isExit = false;
};

#endif // DIALOGLEVEL_H
