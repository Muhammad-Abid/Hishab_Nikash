#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class Sign_Up;
}

class Sign_Up : public QDialog
{
    Q_OBJECT
public:
    void Close()
    {
        hndb.close();
        hndb.removeDatabase( QSqlDatabase :: defaultConnection );
    }
    QSqlDatabase hndb;
    bool Open()
    {
        hndb = QSqlDatabase :: addDatabase("QSQLITE");
        hndb.setDatabaseName("C:/Users/ASUS/Desktop/user.db");

        if( !hndb.open())
            return false;
        else {
            return true;
        }
    }

public:
    explicit Sign_Up(QWidget *parent = nullptr);
    ~Sign_Up();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Sign_Up *ui;
};

#endif // SIGN_UP_H
