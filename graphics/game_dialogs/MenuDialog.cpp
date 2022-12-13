#include "MenuDialog.h"
#include <QKeyEvent>
#include "ui_MenuDialog.h"

MenuDialog::MenuDialog(const std::map<Commands, int> &KeyCommands, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Меню");

    initButton(ui->continueButton, "Продолжить", KeyCommands.at(Commands::MENU));

    initButton(ui->saveButton, "Сохранить", KeyCommands.at(Commands::SAVE));

    initButton(ui->restartButton, "Заново", KeyCommands.at(Commands::NEW_GAME));

    initButton(ui->helpButton, "Помощь", KeyCommands.at(Commands::PAUSE));

    initButton(ui->exitButton, "Завершить", KeyCommands.at(Commands::EXIT_GAME));

    initButton(ui->loadButton, "Загрузить", KeyCommands.at(Commands::LOAD));

}

MenuDialog::~MenuDialog()
{
    delete ui;
}

void MenuDialog::unlockButton()
{
    ui->loadButton->show();
}

void MenuDialog::initButton(QPushButton *button, QString text, int key)
{
    keys[key] = button;
    button->setText(text + " (" + QKeySequence(key).toString() + ")");
}

void MenuDialog::keyPressEvent(QKeyEvent *event)
{
    std::map<int, QPushButton*>::iterator it = keys.find(event->key());
    if(it != keys.end())
        emit keys.at(event->key())->clicked();
    //
}

void MenuDialog::on_continueButton_clicked()
{
    this->hide();
}


void MenuDialog::on_saveButton_clicked()
{
    emit saveGameSignal();
}


void MenuDialog::on_restartButton_clicked()
{
   if(emit restartGameSignal())
       this->hide();
}


void MenuDialog::on_helpButton_clicked()
{
    emit helpSignal();
}


void MenuDialog::on_exitButton_clicked()
{
    if(emit exitSignal())
        this->hide();
}


void MenuDialog::on_loadButton_clicked()
{
    if(emit loadGame())
        this->hide();
}

