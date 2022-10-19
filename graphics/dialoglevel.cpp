#include "dialoglevel.h"
#include "ui_dialoglevel.h"

DialogLevel::DialogLevel(QWidget *parent) :
    QDialog(parent),
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

