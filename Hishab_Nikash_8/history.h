#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase data;
    bool dOpen()
    {
        data = QSqlDatabase :: addDatabase("QSQLITE");
        data.setDatabaseName("C:/Users/ASUS/Desktop/final.db");

        if( !data.open())
            return false;
        else {
            return true;
        }
    }
    void dClose()
    {
        data.close();
        data.removeDatabase( QSqlDatabase :: defaultConnection);
    }

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

private slots:
    void on_goButton_clicked();

private:
    Ui::History *ui;
};

#endif // HISTORY_H
