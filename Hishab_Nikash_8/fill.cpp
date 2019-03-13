#include "fill.h"
#include "ui_fill.h"

Fill::Fill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fill)
{
    ui->setupUi(this);
}

Fill::~Fill()
{
    delete ui;
}

void Fill::on_pushButton_clicked()
{
    hide();
}
