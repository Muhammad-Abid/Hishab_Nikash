#include "history.h"
#include "ui_history.h"
#include "QMessageBox"
#include "hishab_nikash.h"

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_goButton_clicked()
{
    QString first = ui -> first -> text();
    QString last  = ui -> last	-> text();

    if( first == "\0" || last == "\0" )
        QMessageBox :: warning( this, "Error", "Fill both field");
    else {
        dOpen();

        QSqlQueryModel *modal = new QSqlQueryModel();

        QSqlQuery *qry = new QSqlQuery( data );

        qry -> prepare("SELECT * FROM data WHERE Email = '"+hishab_nikash::Email+"' and Date BETWEEN '"+first+"' AND '"+last+"'");

        qry -> exec();
        modal -> setQuery( *qry );
        ui -> tableView -> setModel( modal );
        ui->tableView->hideColumn(0);
        ui->tableView->hideColumn(1);

        qDebug() << ( modal -> rowCount());

        QSqlQuery earn;
        int totalEarn = earn.value(0).toInt();
        earn.exec("SELECT SUM(Amount) FROM data where Email = '"+hishab_nikash::Email+"' and Type = 'Earn' and Date between '"+first+"' and '"+last+"' ");
            if (earn.next())
            {
                totalEarn = earn.value(0).toInt();
                qDebug() << totalEarn;
                ui-> totalEarn -> setNum(totalEarn);
            }

        QSqlQuery expense;
        int totalExpense = expense.value(0).toInt();
        expense.exec("SELECT SUM(Amount) FROM data where Email = '"+hishab_nikash::Email+"' and Type = 'Expense' and Date between '"+first+"' and '"+last+"'");
            if (expense.next())
            {
                totalExpense = expense.value(0).toInt();
                qDebug() << totalExpense;
                ui-> totalExpense -> setNum(totalExpense);
            }
        QSqlQuery savings;
        int totalSavings = savings.value(0).toInt();
        totalSavings = totalEarn - totalExpense;
        qDebug() << totalSavings;
        ui -> totalSavings -> setNum( totalSavings );


    }
}
