#ifndef INVALID_H
#define INVALID_H

#include <QDialog>

namespace Ui {
class Invalid;
}

class Invalid : public QDialog
{
    Q_OBJECT

public:
    explicit Invalid(QWidget *parent = nullptr);
    ~Invalid();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Invalid *ui;
};

#endif // INVALID_H
