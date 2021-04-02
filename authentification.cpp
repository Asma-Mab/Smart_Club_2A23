#include "authentification.h"
#include "ui_authentification.h"
#include "mainwindow.h"
#include <QMessageBox>

authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)

{
    ui->setupUi(this);
    QPixmap pic(":/img/img/loginImg1.png");
    ui->label_2->setPixmap(pic);
    QPixmap pix(":/img/img/Books.jpg");
    ui->label->setPixmap(pix);
}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_pushButton_clicked()
{
    QString id;
    QString mdp;
    id=ui->lineEdit->text();
    mdp=ui->lineEdit_2->text();
    if(id=="admin"&& mdp=="admin")
    {
        QMessageBox::information(this,id,"Accès autorisé ");
        hide();
        mainwindow = new MainWindow();
        mainwindow->show();

    }
    else
     {
         QMessageBox::warning(this,id,"Accès interdit \n", "L'identifant et le mot de passe ne sont pas corrects. RESSAYEZ !");
     }




}
