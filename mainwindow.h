#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include "error.h"
#include <QDir>
#include <QFileDialog>

typedef struct
{
    QString name;
    QString surname;
    float mate;
    float ita;
    float sistemi;
    float elettronica;
    float media;
} Pagella;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_name_textEdited(const QString &arg1);

    void on_surname_textEdited(const QString &arg1);

    void on_maths_textEdited(const QString &arg1);

    void on_italian_textEdited(const QString &arg1);

    void on_systems_textEdited(const QString &arg1);

    void on_pyduts_textEdited(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Pagella pagelle[5];

    int i = 0;

    void mediaCalculator();

    void printToFile();

    Error Errore;
};
#endif // MAINWINDOW_H
