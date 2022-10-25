#include "dialoglevel.h"
#include "ui_dialoglevel.h"

DialogLevel::DialogLevel(Config::Configurator *config, QWidget *parent) :
    QDialog(parent),
    config(config),
    ui(new Ui::DialogLevel)
{
    ui->setupUi(this);
    this->setWindowTitle("Выбор уровня");
    QPixmap pix("/home/aleksey/Projects/OOP/Lab1/Lab1/resurces/logo.jpg");
    ui->LogoLabel->setPixmap(pix);
    connect(this, &QDialog::rejected, this, &DialogLevel::on_exitButton_clicked);
}

DialogLevel::~DialogLevel()
{
    delete ui;
}

void DialogLevel::on_lvl1Button_clicked()
{
    level = 1;
    disconnect(this, &QDialog::rejected, this, &DialogLevel::on_exitButton_clicked);
    this->close();
}


void DialogLevel::on_exitButton_clicked()
{
    isExit = true;
    this->close();
}

int DialogLevel::getLevel() const
{
    return level;
}

bool DialogLevel::getIsExit() const
{
    return isExit;
}


void DialogLevel::on_lvl2Button_clicked()
{
    level = 2;
    disconnect(this, &QDialog::rejected, this, &DialogLevel::on_exitButton_clicked);
    this->close();
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
        break;
    case 1:
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
    default:
        break;
    }
    config->update("object", ui->checkBoxObj->isChecked());
    config->update("game", ui->checkBoxGame->isChecked());
    config->update("critical", ui->checkBoxCrit->isChecked());
    this->setWindowTitle("Выбор уровня");
    ui->stackedWidget->setCurrentIndex(0);
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

