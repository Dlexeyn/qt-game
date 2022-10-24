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
    //DialogLevel()
    ~DialogLevel();

    bool getIsExit() const;

    int getLevel() const;

private slots:
    void on_lvl1Button_clicked();

    void on_exitButton_clicked();

    void on_lvl2Button_clicked();

    void on_settingsButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::DialogLevel *ui;
    Config::Configurator *config = nullptr;
    bool isExit = false;
    int level = 0;
};

#endif // DIALOGLEVEL_H
