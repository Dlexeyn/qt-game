#include "graphics/DialogSize.h"
#include "ui_DialogSize.h"

DialogSize::DialogSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSize)
{
    ui->setupUi(this);
    this->setWindowTitle("Размер игрового поля");
    connect(this, &QDialog::rejected, this, &DialogSize::on_pushButtonCancel_clicked);

}

DialogSize::~DialogSize()
{
    delete ui;
}

int DialogSize::getWidth() const
{
    return width;
}

int DialogSize::getHeight() const
{
    return height;
}

bool DialogSize::getCancel() const
{
    return cancel;
}


void DialogSize::on_pushButtonOk_clicked()
{
    width = ui->lineWidth->text().toInt();
    height = ui->lineHeight->text().toInt();
    if(width >= 10 and width <= 37 and height >= 10 and height <= 18)
    {
        disconnect(this, &QDialog::rejected, this, &DialogSize::on_pushButtonCancel_clicked);
        this->close();
    }

}


void DialogSize::on_pushButtonCancel_clicked()
{
    cancel = true;
    this->close();
}

