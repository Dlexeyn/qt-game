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
    case 0:
        config->update("file", true);
        config->update("console", false);
        break;
    case 1:
        config->update("file", false);
        config->update("console", true);
        break;
    case 2:
        config->update("file", true);
        config->update("console", true);
        break;
    case 3:
        config->update("file", false);
        config->update("console", false);
        break;
    }
    config->update("object", ui->checkBoxObj->isChecked());
    config->update("game", ui->checkBoxGame->isChecked());
    config->update("critical", ui->checkBoxCrit->isChecked());
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

