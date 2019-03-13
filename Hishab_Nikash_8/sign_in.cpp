#include "sign_in.h"
#include "ui_sign_in.h"
#include "QMessageBox"
#include "all.h"

Sign_In::Sign_In(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_In)
{
    ui->setupUi(this);
}

Sign_In::~Sign_In()
{
    delete ui;
}

void Sign_In::on_in_clicked()
{
    QString email = ui -> email -> text();
    QString pass  = ui -> pass  -> text();

    if( email == "\0" || pass == "\0" )
        QMessageBox :: warning( this, "Error", "invalid email or password" );
    else {

            Open();
            QSqlQuery qry;
            qry.prepare("select * from user where email = '"+email+"' and password = '"+pass+"'");
            if( qry.exec())
            {
                int count = 0;
                while( qry.next())
                {
                    count++;
                }
                if( count == 1 )
                {
                Close();
                hide();
                All a;
                a.setModal(true);
                a.exec();


                }
                if( count <1 )
                    QMessageBox :: warning(this,"Error","invalid email or password");
                if( count > 1 )
                    QMessageBox :: warning(this,"Error","invalid email or password");
         }


    }

}
