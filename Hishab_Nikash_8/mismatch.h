#ifndef MISMATCH_H
#define MISMATCH_H

#include <QDialog>

namespace Ui {
class MisMatch;
}

class MisMatch : public QDialog
{
    Q_OBJECT

public:
    explicit MisMatch(QWidget *parent = nullptr);
    ~MisMatch();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MisMatch *ui;
};

#endif // MISMATCH_H
