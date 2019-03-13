#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>

namespace Ui {
class UpDate;
}

class UpDate : public QDialog
{
    Q_OBJECT

public:
    explicit UpDate(QWidget *parent = nullptr);
    ~UpDate();

private:
    Ui::UpDate *ui;
};

#endif // UPDATE_H
