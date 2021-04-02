#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QSound>
QT_CHARTS_USE_NAMESPACE



#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabetudiant->setModel(tmpetudiant.afficher());
QPixmap pixx(":/img/img/BackGround.jpg");
ui->label->setPixmap(pixx);
ui->label_2->setPixmap(pixx);
ui->label_3->setPixmap(pixx);
ui->label_5->setPixmap(pixx);
ui->label_6->setPixmap(pixx);



}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    QSound *sound= new QSound(":/img/click.wav");
        sound->play();
    int CIN = ui->lineEdit_cin->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString mail=ui->lineEdit_mail->text();
    QString role=ui->role->currentText();
 employe e(CIN,nom,prenom,mail,role);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    QSound *sound= new QSound(":/img/click.wav");
        sound->play();
    int CIN=ui->lineEdit_id_2->text().toInt();
    bool test=tmpetudiant.supprimer(CIN);
    if(test)
    {ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un EMPLOYE"),
                    QObject::tr("EMPLOYE supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un EMPLOYE"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    QSound *sound= new QSound(":/img/click.wav");
        sound->play();
       int CIN=ui->lineEdit_CIN->text().toInt();
       QString nom=ui->lineEdit_NOM->text();
       QString prenom=ui->lineEdit_PRENOM->text();
       QString role=ui->role_2->currentText();
       QString mail=ui->lineEdit_MAIL->text();
       bool test= tmpetudiant.modifier(CIN, nom, prenom , role , mail);
       if (test)
       {
           ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier un EMPLOYE"),
                               QObject::tr("EMPLOYE modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Modifier un EMPLOYE"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButton_4_clicked()
{
    QSound *sound= new QSound(":/img/click.wav");
        sound->play();

    QString CIN= ui->lineEdit_cin_2->text();
    bool test=tmpetudiant.rechercher(CIN);

    if(test)
    { ui->tabetudiant_2->setModel(tmpetudiant.recherche(CIN));//refresh
        QMessageBox::information(nullptr, QObject::tr("Recherche terminée"),
                    QObject::tr("Succès\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche non terminée"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_5_clicked()
{
    QSound *sound= new QSound(":/img/click.wav");
        sound->play();
    ui->tabWidget->insertTab(1,tmpetudiant.statistique(),"");
}

void MainWindow::on_widget_destroyed()
{
    QSound *sound= new QSound(":/img/click.wav");
        sound->play();
    ui->tabWidget->insertTab(1,tmpetudiant.statistique(),"");

}

void MainWindow::on_pushButton_6_clicked()
{
    QSound *sound= new QSound(":/img/click.wav");
        sound->play();
    ui->tabWidget->addTab(tmpetudiant.statistique(),"Statistique");
}
