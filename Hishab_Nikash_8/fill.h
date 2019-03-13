#ifndef FILL_H
#define FILL_H

#include <QDialog>

namespace Ui {
class Fill;
}

class Fill : public QDialog
{
    Q_OBJECT

public:
    explicit Fill(QWidget *parent = nullptr);
    ~Fill();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Fill *ui;
};

#endif // FILL_H
