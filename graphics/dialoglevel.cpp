#include "dialoglevel.h"
#include "ui_dialoglevel.h"

DialogLevel::DialogLevel(Config::Configurator *config, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLevel),
    config(config)
{
    ui->setupUi(this);
    this->setWindowTitle("Выбор уровня");
    QPixmap pix("/home/aleksey/Projects/OOP/Lab1/Lab1/resurces/logo.jpg");
    ui->LogoLabel->setPixmap(pix);
}

DialogLevel::~DialogLevel()
{
    delete ui;
}

void DialogLevel::on_lvl1Button_clicked()
{
    emit changeLevel(1);
}

void DialogLevel::on_exitButton_clicked()
{
    disconnect(this, &QDialog::rejected, this, &DialogLevel::on_exitButton_clicked);
    emit endApp();
}

void DialogLevel::on_lvl2Button_clicked()
{
    emit changeLevel(2);
}

void DialogLevel::on_settingsButton_clicked()
{
    this->setWindowTitle("Настройки");
    ui->stackedWidget->setCurrentIndex(1);
}

void DialogLevel::on_saveButton_clicked()
{
    switch (ui->logComboBox->currentIndex()) {
    case 0: // both
        config->update(Config::Settings::LOGS, "file", true);
        config->update(Config::Settings::LOGS, "console", true);
        break;
    case 1: // only console
        config->update(Config::Settings::LOGS, "file", false);
        config->update(Config::Settings::LOGS, "console", true);
        break;
    case 2: // only file
        config->update(Config::Settings::LOGS, "file", true);
        config->update(Config::Settings::LOGS, "console", false);
        break;
    case 3: // disable
        config->update(Config::Settings::LOGS, "file", false);
        config->update(Config::Settings::LOGS, "console", false);
        break;
    }

    switch (ui->gameComboBox->currentIndex()) {
    case 0:
        config->update(Config::Settings::GAME, "lose_restart", true);
        break;
    case 1:
        config->update(Config::Settings::GAME, "lose_restart", false);
        break;
    default:
        break;
    }

    config->update(Config::Settings::LOGS, "object", ui->checkBoxObj->isChecked());
    config->update(Config::Settings::LOGS, "game", ui->checkBoxGame->isChecked());
    config->update(Config::Settings::LOGS, "critical", ui->checkBoxCrit->isChecked());
    this->setWindowTitle("Выбор уровня");
    ui->stackedWidget->setCurrentIndex(0);
    emit changeSettings();
}


void DialogLevel::on_logComboBox_currentIndexChanged(int index)
{
    if(index == 3)
    {
        ui->checkBoxObj->setDisabled(true);
        ui->checkBoxGame->setDisabled(true);
        ui->checkBoxCrit->setDisabled(true);
    }
    else
    {
        ui->checkBoxObj->setEnabled(true);
        ui->checkBoxGame->setEnabled(true);
        ui->checkBoxCrit->setEnabled(true);
    }
}

