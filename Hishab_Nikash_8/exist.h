#ifndef EXIST_H
#define EXIST_H

#include <QDialog>

namespace Ui {
class Exist;
}

class Exist : public QDialog
{
    Q_OBJECT

public:
    explicit Exist(QWidget *parent = nullptr);
    ~Exist();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Exist *ui;
};

#endif // EXIST_H
