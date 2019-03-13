#include "invalid.h"
#include "ui_invalid.h"

Invalid::Invalid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Invalid)
{
    ui->setupUi(this);
}

Invalid::~Invalid()
{
    delete ui;
}

void Invalid::on_pushButton_clicked()
{
    hide();
}
