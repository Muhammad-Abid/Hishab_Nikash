#ifndef DONE_H
#define DONE_H

#include <QDialog>

namespace Ui {
class Done;
}

class Done : public QDialog
{
    Q_OBJECT

public:
    explicit Done(QWidget *parent = nullptr);
    ~Done();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Done *ui;
};

#endif // DONE_H
