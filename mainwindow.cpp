#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1250,600);
    this->setFixedSize(1250,600);
    escena = new QGraphicsScene();
    ui->Fondo->setScene(escena);
    escena->setSceneRect(0,0,0,0);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEscena()));
    timer->stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double Velocidad=0, Posicion=0, Ang=0, Radio=0, Masa=0;
    Velocidad = ui->lineEdit->text().toFloat(NULL);
    Radio = ui->lineEdit_2->text().toFloat(NULL);
    Posicion = ui->lineEdit_3->text().toFloat(NULL);
    Ang = ui->lineEdit_4->text().toFloat(NULL);
    Masa = ui->lineEdit_5->text().toFloat(NULL);

    particle = new Particula(Velocidad,Posicion,Ang,Radio,Masa);
    escena->addItem(particle);
    timer->start(100);
}

void MainWindow::actualizarEscena(void)
{
    particle->moverParticula(0.5, 0);
    particle->colisionParticula(500, 1000);
}
