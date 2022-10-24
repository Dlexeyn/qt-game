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
        config->update(Config::ConfigTypes::FILE_LOG, true);
        break;
    case 1:
        config->update(Config::ConfigTypes::CONSOLE_LOG, true);
        break;
    case 2:
        config->update(Config::ConfigTypes::LOG, true);
        break;
    case 3:
        config->update(Config::ConfigTypes::LOG, false);
        break;
    default:
        break;
    }
    this->setWindowTitle("Выбор уровня");
    ui->stackedWidget->setCurrentIndex(0);
}

