#include "mainwindow.h"
#include "xmldoc.h"
#include "allcalculate.h"
#include "ui_mainwindow.h"
#include "QMessageBox"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     if(!validate_input())
     {
         QMessageBox::information(0, "Message", "Введены некорректные данные");
     }
     else
     {
         QString text = ui->lineEdit->text();
         int value = text.toInt();
         XmlDoc::createXml(value);
         QMessageBox::information(0, "Message", "Файл сгенерирован!");
     }
}

bool MainWindow::validate_input()
{
    QString text = ui->lineEdit->text();
    bool ok;
    text.toInt(&ok);
    if (!ok) // not an integer
    {
        return false;
    }
    else
    {
        return true;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int countOfCoords = XmlDoc::getSize();
    QString **strArr;
    strArr = new QString*[countOfCoords];
    for (int i = 0; i< countOfCoords; i++)
    {
        strArr[i]=new QString[2];
    }
    XmlDoc::openXml(strArr, countOfCoords);
    drawPoints(strArr, countOfCoords);
    for (int i = 0; i< countOfCoords; i++)
    {
        delete []strArr[i];
    }
    delete []strArr;
}


void MainWindow::drawPoints(QString **strArr, int n)
{
        double rad = 1;
        QGraphicsScene *PalletScene = new QGraphicsScene(this);
        ui->graphicsView->setScene(PalletScene);
        QBrush br(Qt::red);
        QPen pen(Qt::black);
        for (int i=0; i<n;i++)
        {
            PalletScene->addEllipse(strArr[i][0].toInt(), strArr[i][1].toInt(), rad*3.0, rad*3.0, pen, br);
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    int countOfCoords = XmlDoc::getSize();
    QString **strArr;
    strArr = new QString*[countOfCoords];
    for (int i = 0; i< countOfCoords; i++)
    {
        strArr[i]=new QString[2];
    }
    XmlDoc::openXml(strArr, countOfCoords);
    AllCalculate::sorting(strArr, countOfCoords);
    drawLine(strArr, countOfCoords);
}

void MainWindow::drawLine(QString **strArr, int n)
{
    double rad = 1;
    QGraphicsScene *PalletScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(PalletScene);
    QBrush br(Qt::red);
    QPen pen(Qt::black);
    for (int i=0; i<n;i++)
    {
        PalletScene->addEllipse(strArr[i][0].toInt(), strArr[i][1].toInt(), rad*3.0, rad*3.0, pen, br);
    }
    if (n%2==1)
    {
        n=n-1;
    }
    for (int i=0;i<n;i+=2)
    {
        PalletScene->addLine(strArr[i][0].toInt(),strArr[i][1].toInt(),strArr[i+1][0].toInt(),strArr[i+1][1].toInt(),pen);
    }   
}

void MainWindow::on_pushButton_4_clicked()
{
    int countOfCoords = XmlDoc::getSize();
    QString **strArr;
    strArr = new QString*[countOfCoords];
    for (int i = 0; i< countOfCoords; i++)
    {
        strArr[i]=new QString[2];
    }

    XmlDoc::openXml(strArr, countOfCoords);
    AllCalculate::sorting(strArr, countOfCoords);
    float length = drawBrokenLine(strArr, countOfCoords);
    ui->label_2->setText(QString::number(length));

}

float MainWindow::drawBrokenLine(QString **strArr, int n)
{
    double rad = 1;
    float size =0;
    QGraphicsScene *PalletScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(PalletScene);
    QBrush br(Qt::red);
    QPen pen(Qt::black);
    for (int i=0; i<n;i++)
    {
        PalletScene->addEllipse(strArr[i][0].toInt(), strArr[i][1].toInt(), rad*3.0, rad*3.0, pen, br);
    }

    for (int i=0;i<n-1;i++)
    {
        PalletScene->addLine(strArr[i][0].toInt(),strArr[i][1].toInt(),strArr[i+1][0].toInt(),strArr[i+1][1].toInt(),pen);
        size += AllCalculate::minLenght(strArr[i][0],strArr[i][1],strArr[i+1][0],strArr[i+1][1]);
    }


    return size;
}

void MainWindow::on_pushButton_5_clicked()
{
    int countOfCoords = XmlDoc::getSize();
    QString **strArr;
    strArr = new QString*[countOfCoords];
    for (int i = 0; i< countOfCoords; i++)
    {
        strArr[i]=new QString[2];
    }

    XmlDoc::openXml(strArr, countOfCoords);
    AllCalculate::sorting(strArr, countOfCoords);
    AllCalculate::shortLine(strArr, 0, countOfCoords);
    float length = drawBrokenLine(strArr, countOfCoords);
    ui->label_2->setText(QString::number(length));
}

