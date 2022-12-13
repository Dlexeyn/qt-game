#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>
#include <game/Command.h>

namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDialog(const std::map <Commands, int> &KeyCommands, QWidget *parent = nullptr);
    ~MenuDialog();
signals:
    bool loadGame();
    void continueSignal();
    void saveGameSignal();
    bool restartGameSignal();
    void helpSignal();
    bool exitSignal();
public slots:
    void unlockButton();

private slots:
    void on_continueButton_clicked();

    void on_saveButton_clicked();

    void on_restartButton_clicked();

    void on_helpButton_clicked();

    void on_exitButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::MenuDialog *ui;
    std::map <int, QPushButton*> keys;
    void initButton(QPushButton *button, QString text, int key);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MENUDIALOG_H
