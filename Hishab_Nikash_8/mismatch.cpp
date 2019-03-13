#include "mismatch.h"
#include "ui_mismatch.h"

MisMatch::MisMatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MisMatch)
{
    ui->setupUi(this);
}

MisMatch::~MisMatch()
{
    delete ui;
}

void MisMatch::on_pushButton_clicked()
{
    hide();
}
