#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include "graphics/game_dialogs/gameDialog.h"
#include <QDialog>
#include <game/Command.h>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog, public GameDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(const std::map<Commands, int> &KeyCommands, QWidget *parent = nullptr);
    ~HelpDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HelpDialog *ui;
    void keyPressEvent(QKeyEvent *event);
    void setLabel(Commands command, int key);
};

#endif // HELPDIALOG_H
