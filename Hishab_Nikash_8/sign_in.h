#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class Sign_In;
}

class Sign_In : public QDialog
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
    explicit Sign_In(QWidget *parent = nullptr);
    ~Sign_In();

private slots:
    void on_in_clicked();

private:
    Ui::Sign_In *ui;
};

#endif // SIGN_IN_H
