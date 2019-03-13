#ifndef ALL_H
#define ALL_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "hishab_nikash.h"

namespace Ui {
class All;
}

class All : public QDialog
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
    explicit All(QWidget *parent = nullptr);
    ~All();

private slots:
    void on_out_clicked();

    void on_add_clicked();

    void on_view_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_remove_clicked();

    void time();

    void on_search_clicked();

    void on_total_clicked();

    void on_pushButton_clicked();

    void on_refresh_clicked();

    void on_historyButton_clicked();

private:
    Ui::All *ui;

};

#endif // ALL_H
