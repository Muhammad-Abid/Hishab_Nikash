#include "sign_up.h"
#include "ui_sign_up.h"
#include "QMessageBox"

Sign_Up::Sign_Up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sign_Up)
{
    ui->setupUi(this);
}

Sign_Up::~Sign_Up()
{
    delete ui;
}

void Sign_Up::on_pushButton_clicked()
{
    QString name 	= ui -> name 	-> text();
    QString email 	= ui -> email 	-> text();
    QString pass 	= ui -> pass 	-> text();
    QString repass	= ui -> re_pass -> text();

    if( name == "\0" || email == "\0" || pass == "\0" || repass == "\0" )
        QMessageBox :: warning( this,"Error","All field must be fillup" );
    else if( pass != repass )
        QMessageBox :: warning( this, "Error", "password mismatched" );
    else {
        if( !Open() )
            return;

        else {
            Open();
            QSqlQuery qry;
            qry.prepare("insert into user ( name, email, password) values ('"+name+"' , '"+email+"' , '"+repass+"') ");

            if( qry.exec() )
            {
                hide();
                QMessageBox :: about(this,"succesful","Assalamu Alaikum Warah'matullah\n  Your accout is succesfully created\n        Please, Sign In to join as\n                    Thank you.");
                Close();
            }
            else {
                QMessageBox :: critical(this,"Error", qry.lastError().text());
            }

        }
    }
}
