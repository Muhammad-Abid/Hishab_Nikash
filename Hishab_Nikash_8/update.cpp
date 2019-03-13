#include "update.h"
#include "ui_update.h"

UpDate::UpDate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpDate)
{
    ui->setupUi(this);
}

UpDate::~UpDate()
{
    delete ui;
}
