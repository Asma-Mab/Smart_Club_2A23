#include "employe.h"
#include <QDebug>


employe::employe()
{
    CIN=0;
    nom="";
    prenom="";
    mail="";
    role="";
}


employe::employe(int CIN,QString nom,QString prenom,QString mail, QString role)
{
  this->CIN=CIN;
  this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->role=role;
}
    QString employe::get_nom(){return  nom;}
    QString employe::get_prenom(){return prenom;}
    QString employe::get_mail(){return mail;}
    QString employe::get_role() {return role;}
    int employe ::get_CIN(){return  CIN;}


bool employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("INSERT INTO employe (CIN, NOM, PRENOM, MAIL, ROLE) "
                    "VALUES (:CIN, :nom, :prenom, :mail, :role)");
query.bindValue(":CIN", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":mail", mail);
query.bindValue(":role", role);

return    query.exec();
}

QSqlQueryModel * employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Role"));
    return model;

}

bool employe::supprimer(int CIN)
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from employe where CIN= :CIN");
query.bindValue(":CIN", res);
return    query.exec();
}

bool employe::modifier(int CIN,QString nom, QString prenom,QString role,QString mail)
{


     QSqlQuery query;
    QString res= QString::number(CIN);
    query.prepare("UPDATE employe SET NOM=:nom ,PRENOM=:prenom,MAIL=:mail,ROLE=:role where CIN=:CIN");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":role", role);
     return    query.exec();



}

bool employe::rechercher(QString CIN)
{
    QSqlQuery query;
     //QString res= QString::number(CIN);
    query.prepare("select nom , prenom , mail ,role from employe where CIN='"+CIN+"'");

    /*query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":role", role);*/

    return query.exec();

}

QSqlQueryModel * employe::recherche(QString idd)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select nom , prenom ,mail ,role from employe where CIN = '"+idd+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROLE"));
    return model;

}
QChartView * employe ::statistique(){
    employe a1(125,"nom1","prenom1","role1","mail1");
    employe a2(545,"nom","prenom","role","mail");
    employe a3(25,"nom","prenom","role","mail");
    employe a4(998,"nom","prenom","role","mail");
    employe a5(78,"nom","prenom","role","mail");
    employe a6(369,"nom","prenom","role","mail");
    //![1]
        QBarSet *set0 = new QBarSet(a1.get_nom() +" "+ a1.get_prenom());
        QBarSet *set1 = new QBarSet(a2.get_nom() +" "+ a2.get_prenom());
        QBarSet *set2 = new QBarSet(a3.get_nom() +" "+ a3.get_prenom());
        QBarSet *set3 = new QBarSet(a4.get_nom() +" "+ a4.get_prenom());
        QBarSet *set4 = new QBarSet(a5.get_nom() +" "+ a5.get_prenom());

        *set0 << 1 << 2 << 3 << 4 << 5 << 6 << 3 << 4 << 5 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7 << 5 << 0 << 0 << 4 << 0 << 7 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5 << 3 << 5 << 8 << 13 << 8 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2  << 5 << 6 << 7 << 3 << 4 << 5 ;
    //![1]

    //![2]
        QStackedBarSeries *series = new QStackedBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistique");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep"
                   << "Oct" << "Nov" << "Dec";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]
        return chartView;
}
