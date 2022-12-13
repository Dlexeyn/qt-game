#include "LoadDialog.h"
#include "ui_LoadDialog.h"

LoadDialog::LoadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Загрузка");
    ui->firstSave->hide();
    ui->secondSave->hide();
    ui->thirdSave->hide();
    ui->fourthSave->hide();
    ui->fifthSave->hide();

    ui->firstSaveDel->hide();
    ui->secondSaveDel->hide();
    ui->thirdSaveDel->hide();
    ui->fourthSaveDel->hide();
    ui->fifthSaveDel->hide();

    buttons.push_back(std::make_pair(ui->firstSave, ui->firstSaveDel));
    buttons.push_back(std::make_pair(ui->secondSave, ui->secondSaveDel));
    buttons.push_back(std::make_pair(ui->thirdSave, ui->thirdSaveDel));
    buttons.push_back(std::make_pair(ui->fourthSave, ui->fourthSaveDel));
    buttons.push_back(std::make_pair(ui->fifthSave, ui->fifthSaveDel));
}

LoadDialog::~LoadDialog()
{
    delete ui;
}

void LoadDialog::setSaves(std::vector<std::string> &saves)
{
    for(auto b : buttons)
    {
        b.first->hide();
        b.second->hide();
    }
    ui->labelNoSaves->show();

    if(saves.size() == 0)
        return;

    ui->labelNoSaves->hide();

    for(size_t i = 0; i < saves.size(); i++)
    {
        buttons[i].first->setText(QString::fromStdString(saves[i]));
        buttons[i].first->show();
        buttons[i].second->show();
    }
}

void LoadDialog::on_firstSave_clicked()
{
    cur = 1;
    this->hide();
}


void LoadDialog::on_secondSave_clicked()
{
    cur = 2;
    this->hide();
}


void LoadDialog::on_thirdSave_clicked()
{
    cur = 3;
    this->hide();
}


void LoadDialog::on_fourthSave_clicked()
{
    cur = 4;
    this->hide();
}


void LoadDialog::on_fifthSave_clicked()
{
    cur = 5;
    this->hide();
}


void LoadDialog::on_cancelButton_clicked()
{
    cur = 0;
    this->hide();
}

int LoadDialog::getCur() const
{
    return cur;
}


void LoadDialog::on_firstSaveDel_clicked()
{
    cur = -1;
    this->hide();
}


void LoadDialog::on_secondSaveDel_clicked()
{
    cur = -2;
    this->hide();
}


void LoadDialog::on_thirdSaveDel_clicked()
{
    cur = -3;
    this->hide();
}


void LoadDialog::on_fourthSaveDel_clicked()
{
    cur = -4;
    this->hide();
}


void LoadDialog::on_fifthSaveDel_clicked()
{
    cur = -4;
    this->hide();
}

