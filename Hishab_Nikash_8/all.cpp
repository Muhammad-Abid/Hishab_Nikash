#include "all.h"
#include "ui_all.h"
#include "sign_in.h"
#include "hishab_nikash.h"
#include "ui_hishab_nikash.h"
#include "QMessageBox"
#include "QDateTime"
#include "fill.h"
#include "history.h"

All::All(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::All)
{
    ui->setupUi(this);

    ui -> comboBox -> addItem("Earn");
    ui -> comboBox -> addItem("Expense");
    ui -> nameLabel -> setText(hishab_nikash::Email);
    time();

    dOpen();

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *qry = new QSqlQuery( data );

    qry -> prepare("select*from data where Email = '"+hishab_nikash::Email+"' ");

    qry -> exec();
    modal -> setQuery( *qry );
    ui -> tableView -> setModel( modal );
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);

    qDebug() << ( modal -> rowCount());
    on_total_clicked();



}


All::~All()
{
    delete ui;
}

void All::time()
{
    QDate date = QDate :: currentDate();
    QString setDate = date.toString("yyyy/MM/dd");
    ui -> dte -> setText( setDate );

    QTime time = QTime :: currentTime();
    QString setTime = time.toString("hh:mm:ss");
    ui -> tym -> setText( setTime );
}

void All::on_add_clicked()
{
    QString date 	= ui -> dte		-> text();
    QString time 	= ui -> tym		-> text();
    QString type 	= ui -> comboBox-> currentText();
    QString amount 	= ui -> amount 	-> text();
    QString source 	= ui -> source 	-> text();

    if( date == "\0" || type == "\0" || amount == "\0" || source == "\0" )
    {
        Fill f;
        f.setModal( true );
        f.exec();
    }

    else {

        dOpen();
        QSqlQuery qry;
        qry.prepare("insert into data ( Email, Date, Time, Type, Amount, Source) values ( '"+hishab_nikash::Email+"' , '"+date+"', '"+time+"' , '"+type+"','"+amount+"', '"+source+"')");

        if( qry.exec() )
        {
            on_view_clicked();
            on_total_clicked();
            dClose();
        }

        else {
            QMessageBox :: warning( this, "Error" , qry.lastError().text() );
        }
    }
}

void All::on_tableView_activated(const QModelIndex &index)
{
    QModelIndex noIndex = index.sibling(index.row(),0);
    QString dltno = ui -> tableView -> model()->data(noIndex).toString();
    QModelIndex emailIndex = index.sibling(index.row(),1);
    QString dltemail = ui -> tableView -> model()->data(emailIndex).toString();
    QModelIndex dateIndex = index.sibling(index.row(),2);
    QString dltdate = ui -> tableView -> model()->data(dateIndex).toString();
    QModelIndex timeIndex = index.sibling(index.row(),3);
    QString dlttime = ui -> tableView -> model()->data(timeIndex).toString();
    QModelIndex typeIndex = index.sibling(index.row(),4);
    QString dlttype = ui -> tableView -> model()->data(typeIndex).toString();
    QModelIndex amountIndex = index.sibling(index.row(),5);
    QString dltamount = ui -> tableView -> model()->data(amountIndex).toString();
    QModelIndex sourceIndex = index.sibling(index.row(),6);
    QString dltsource = ui -> tableView -> model()->data(sourceIndex).toString();

    qDebug()<< dltdate << dlttime << dlttype << dltamount << dltsource ;
    if( !dOpen())
    {
        QMessageBox :: warning( this , "Error" , "Error" );
    }
    else {
        dOpen();
        QSqlQuery qry;
        QMessageBox :: StandardButtons yn;
        yn = QMessageBox :: question( this , "?" , "Are you sure you want to permanently delete this ?" , QMessageBox :: Yes | QMessageBox :: No );

        if( yn == QMessageBox :: No )
            return;
        else {

        qry.prepare("delete from data where No = '"+dltno+"' and Email = '"+dltemail+"' and Date ='"+dltdate+"' and Time = '"+dlttime+"' and Type = '"+dlttype+"' and amount = '"+dltamount+"' and source = '"+dltsource+"' " );

        if( qry.exec() )
        {
            on_view_clicked();
            on_total_clicked();
            dClose();
         }
        else {
            QMessageBox :: warning( this, "Error" , qry.lastError().text() );
        }
    }
}
}

/*void All::on_remove_clicked()
{

}*/



void All::on_out_clicked()
{
        hide();
        hishab_nikash hk;

}

void All::on_view_clicked()
{
    dOpen();

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *qry = new QSqlQuery( data );

    qry -> prepare("select*from data where Email = '"+hishab_nikash::Email+"' ");

    qry -> exec();
    modal -> setQuery( *qry );
    ui -> tableView -> setModel( modal );

    qDebug() << ( modal -> rowCount());}




void All::on_total_clicked()
{

    dOpen();

    QSqlQuery earn;
    int totalExpense = earn.value(0).toInt();
    earn.exec("SELECT SUM(Amount) FROM data WHERE Email = '"+hishab_nikash::Email+"' and Type = 'Expense'");
        if (earn.next())
        {
            totalExpense = earn.value(0).toInt();
            qDebug() << totalExpense;
            ui-> expense -> setNum(totalExpense);
        }

    QSqlQuery expense;
    int totalEarn = expense.value(0).toInt();
    expense.exec("SELECT SUM(Amount) FROM data WHERE Email = '"+hishab_nikash::Email+"' and Type = 'Earn'");
        if (expense.next())
        {
            totalEarn = expense.value(0).toInt();
            qDebug() << totalEarn;
            ui-> earn -> setNum(totalEarn);
        }
    QSqlQuery saving;
    int totalSaving = saving.value(0).toInt();
        totalSaving = totalEarn - totalExpense;
        qDebug() << totalSaving;
        ui -> savings -> setNum( totalSaving );
}

void All::on_refresh_clicked()
{
    hide();
    All a;
    a.setModal(true);
    a.exec();

    time();

/*    dOpen();


    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *qry = new QSqlQuery( data );

    qry -> prepare("select*from data");

    qry -> exec();
    modal -> setQuery( *qry );
    ui -> tableView -> setModel( modal );
    ui->tableView->hideColumn(0);

    qDebug() << ( modal -> rowCount());
    on_total_clicked();
*/}

void All::on_historyButton_clicked()
{
    History h;
    h.setModal( true );
    h.exec();
}
