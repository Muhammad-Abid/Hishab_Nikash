#include "hishab_nikash.h"
#include "ui_hishab_nikash.h"
#include "sign_up.h"
#include "sign_in.h"
#include "QMessageBox"
#include "all.h"
#include "fill.h"
#include "invalid.h"
#include "done.h"
#include "mismatch.h"
#include "exist.h"
hishab_nikash::hishab_nikash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hishab_nikash)
{
    ui->setupUi(this);
}

hishab_nikash::~hishab_nikash()
{
    delete ui;
}
QString hishab_nikash::Email;
void hishab_nikash::on_Up_clicked()
{
    QString name 	= ui -> username 			-> text();
    QString email 	= ui -> upEmailEdit 		-> text();
    QString pass 	= ui -> upPasswordEdit 		-> text();
    QString repass	= ui -> uppassConfirmEdit 	-> text();

    if( name == "\0" || email == "\0" || pass == "\0" || repass == "\0" )
    {
        Fill f;
        f.setModal(true);
        f.exec();
    }
    else if( pass != repass )
    {
        MisMatch mm;
        mm.setModal( true );
        mm.exec();
    }
    else {
        if( !Open() )
            return;

        else {
            Open();
            QSqlQuery qry;
            qry.prepare("insert into user ( name, email, password) values ('"+name+"' , '"+email+"' , '"+repass+"') ");

            if( qry.exec() )
            {
                Done d;
                d.setModal( true );
                d.exec();
                Close();
            }
            else {
                Exist e;
                e.setModal( true );
                e.exec();
            }

        }
    }
}

void hishab_nikash::on_In_clicked()
{
    Email = ui -> inEmailEdit -> text();
    QString pass  = ui -> inPasswordEdit  -> text();

    if( Email == "\0" || pass == "\0" )
    {
        Fill f;
        f.setModal(true);
        f.exec();
    }
    else {

            Open();
            QSqlQuery qry;
            qry.prepare("select * from user where Email = '"+Email+"' and Password = '"+pass+"'");
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
                {
                    Invalid i;
                    i.setModal( true );
                    i.exec();
                }
                if( count > 1 )
                {
                    Invalid i;
                    i.setModal( true );
                    i.exec();
                }
         }


    }

}
