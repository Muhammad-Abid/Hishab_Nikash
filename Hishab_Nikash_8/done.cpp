#include "done.h"
#include "ui_done.h"

Done::Done(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Done)
{
    ui->setupUi(this);
}

Done::~Done()
{
    delete ui;
}

void Done::on_pushButton_clicked()
{
    hide();
}
