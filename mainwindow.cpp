#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bubble.h"

//Costruttore di MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//Distruttore di MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_name_textEdited(const QString &arg1)
{
    pagelle[i].name = arg1;
    mediaCalculator();
}


void MainWindow::on_surname_textEdited(const QString &arg1)
{
    pagelle[i].surname = arg1;
    mediaCalculator();
}


void MainWindow::on_maths_textEdited(const QString &arg1)
{
    pagelle[i].mate = arg1.toFloat();
    mediaCalculator();
}

void MainWindow::on_italian_textEdited(const QString &arg1)
{
    pagelle[i].ita = arg1.toFloat();
    mediaCalculator();
}


void MainWindow::on_systems_textEdited(const QString &arg1)
{
    pagelle[i].sistemi = arg1.toFloat();
    mediaCalculator();
}


void MainWindow::on_pyduts_textEdited(const QString &arg1)
{
    pagelle[i].elettronica = arg1.toFloat();
    mediaCalculator();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->name->text() == "" ||
            ui->surname->text() == "" ||
            ui->maths->text() == "" ||
            ui->italian->text() == "" ||
            ui->systems->text() == "" ||
            ui->pyduts->text() == "" ||
            ui->maths->text().toFloat() > 10 ||
            ui->maths->text().toFloat() < 1 ||
            ui->italian->text().toFloat() > 10 ||
            ui->italian->text().toFloat() < 1 ||
            ui->systems->text().toFloat() > 10 ||
            ui->systems->text().toFloat() < 1 ||
            ui->pyduts->text().toFloat() > 10 ||
            ui->pyduts->text().toFloat() < 1)
    {
        Errore.show();
    }
    else if (i < 4)
    {
        i++;
        ui->name->setText("");
        ui->surname->setText("");
        ui->maths->setText("");
        ui->italian->setText("");
        ui->systems->setText("");
        ui->pyduts->setText("");
        ui->mediaLabel->setText("Media: ");
    }
    else if(i == 4)
    {
        ui->pushButton->setText("Print to file");
        ui->name->close();
        ui->surname->close();
        ui->maths->close();
        ui->italian->close();
        ui->systems->close();
        ui->pyduts->close();
        ui->mediaLabel->close();
        ui->label->close();
        ui->label_2->close();
        ui->label_3->close();
        ui->label_4->close();
        ui->label_5->close();
        ui->label_6->close();
        i++;
    }
    else
        printToFile();
}

void MainWindow::mediaCalculator()
{
    if (ui->maths->text() != "" &&
            ui->italian->text() != "" &&
            ui->systems->text() != "" &&
            ui->pyduts->text() != "")
    {
        pagelle[i].media = (pagelle[i].mate + pagelle[i].ita + pagelle[i].sistemi + pagelle[i].elettronica) / 4.0;
        QString m = QString::number(pagelle[i].media);
        ui->mediaLabel->setText("Media: " + m);
    }
}

void MainWindow::printToFile()
{
    //Creo un oggetto di classe Bubble e chiamo il metodo Sort che riordina
    //l'array di nome pagelle in base alla media.
    Bubble sorter;
    //sorter.Sort(pagelle, 0, 4);
    sorter.bySelection(pagelle, 5);

    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("Save File"),
        QDir::homePath(), // Default directory (home)
        tr("Text document (*.txt *.xls)") // File filters
        );

    //dopo aver ordinato le pagelle le stampiamo su un file
    qInfo() << filePath;
    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << "Nome\tCognome\tMedia\n";
        stream << pagelle[0].name + "\t" + pagelle[0].surname + "\t" + QString::number(pagelle[0].media) + "\n";
        stream << pagelle[1].name + "\t" + pagelle[1].surname + "\t" + QString::number(pagelle[1].media) + "\n";
        stream << pagelle[2].name + "\t" + pagelle[2].surname + "\t" + QString::number(pagelle[2].media) + "\n";
        stream << pagelle[3].name + "\t" + pagelle[3].surname + "\t" + QString::number(pagelle[3].media) + "\n";
        stream << pagelle[4].name + "\t" + pagelle[4].surname + "\t" + QString::number(pagelle[4].media) + "\n";
    }
}
