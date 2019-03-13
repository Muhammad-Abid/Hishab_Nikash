#ifndef HISHAB_NIKASH_H
#define HISHAB_NIKASH_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class hishab_nikash;
}


class hishab_nikash : public QMainWindow
{
    Q_OBJECT
public:
    static QString Email;

    void Close()
    {
        hndb.close();
        hndb.removeDatabase( QSqlDatabase :: defaultConnection );
    }
    QSqlDatabase hndb;
    bool Open()
    {
        hndb = QSqlDatabase :: addDatabase("QSQLITE");
        hndb.setDatabaseName("C:/Users/ASUS/Desktop/final.db");

        if( !hndb.open())
            return false;
        else {
            return true;
        }

    }

public:
    explicit hishab_nikash(QWidget *parent = nullptr);
    ~hishab_nikash();

private slots:
    void on_Up_clicked();

    void on_In_clicked();

private:
    Ui::hishab_nikash *ui;
};

#endif // HISHAB_NIKASH_H
