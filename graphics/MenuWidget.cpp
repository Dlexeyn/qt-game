#include "MenuWidget.h"
#include "ui_MenuWidget.h"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Меню");
    this->resize(200, 350);
    this->setFixedSize(200, 350);
}

MenuWidget::~MenuWidget()
{
    delete ui;
}
