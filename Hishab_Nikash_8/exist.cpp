#include "exist.h"
#include "ui_exist.h"

Exist::Exist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exist)
{
    ui->setupUi(this);
}

Exist::~Exist()
{
    delete ui;
}

void Exist::on_pushButton_clicked()
{
    hide();
}
