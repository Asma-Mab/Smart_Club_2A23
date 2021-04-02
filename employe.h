#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRadioButton>

#include <QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE
class employe
{
public:
    employe();
    employe(int,QString,QString,QString,QString);
    QString get_nom();
    QString get_mail();
    QString get_role();
    QString get_prenom();
    void set_nom(QString nom);
    void set_mail(QString mail);
    void set_role(QString role);
    void set_prenom(QString prenom);
    void set_CIN(int cin);
     bool rechercher(QString);
    int get_CIN();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString);
    QChartView * statistique();
    
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString);
private:
    QString nom,prenom, role , mail;
    int CIN;


};

#endif // EMPLOYE_H


