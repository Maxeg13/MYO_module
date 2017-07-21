#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "datacollector.h"
//#include <QSleep>
//#include <QTest>


DataCollector collector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
QObject::connect(&collector.qdc,SIGNAL(EMG(QVector<float>)),this,SLOT(getEMG(QVector<float>)));
    // If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
    if (!collector.myo)
    {
        qDebug() << "Unable to find a Myo";
    }
    qDebug() << "Connected to a Myo armband";

    while(1)
    {
        collector.kick(10);
    }
}
void MainWindow::getEMG(QVector<float> emg)
{
    qDebug()<<emg[0];
}
MainWindow::~MainWindow()
{
    delete ui;
}
