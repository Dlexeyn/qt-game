#include "HelpDialog.h"
#include "ui_HelpDialog.h"

HelpDialog::HelpDialog(const std::map<Commands, int> &KeyCommands, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

    for (auto& [key, value]: KeyCommands) {
        setLabel(key, value);
    }
    key = KeyCommands.at(Commands::PAUSE);
    ui->pushButton->setText("Ок ("+ QKeySequence(key).toString() + ")");
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::setLabel(Commands command, int key)
{
    switch (command) {
    case Commands::DOWN:
        ui->keyLabelBack->setText(QKeySequence(key).toString());
        break;
    case Commands::UP:
        ui->keyLabelForward->setText(QKeySequence(key).toString());
        break;
    case Commands::LEFT:
        ui->keyLabelLeft->setText(QKeySequence(key).toString());
        break;
    case Commands::RIGHT:
        ui->keyLabelRight->setText(QKeySequence(key).toString());
        break;
    case Commands::PAUSE:
        ui->keyLabelPause->setText(QKeySequence(key).toString());
        break;
    case Commands::SAVE:
        ui->keyLabelSave->setText(QKeySequence(key).toString());
        break;
    case Commands::NEW_GAME:
        ui->keyLabelRestart->setText(QKeySequence(key).toString());
        break;
    case Commands::EXIT_GAME:
        ui->keyLabelExit->setText(QKeySequence(key).toString());
        break;
    case Commands::MENU:
        ui->keyLabelMenu->setText(QKeySequence(key).toString());
        break;
    default:
        break;
    }
}

void HelpDialog::on_pushButton_clicked()
{
    this->hide();
}

void HelpDialog::keyPressEvent(QKeyEvent *event)
{
    if(key == event->key())
        on_pushButton_clicked();
}

