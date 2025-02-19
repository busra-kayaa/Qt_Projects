#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // bu satır sonrasında tanımladığımız şeyler yazılmalı
    sayac = 1;
}
// connect -> sinyallerle slotları buluşturuyor.
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    benimbutonum *btn = new benimbutonum(this); // this bu sınıfın adresini gönder demek
    btn->setText(QString::number(sayac));
    btn->show();
    btn->setGeometry(100,50,100,100);
    sayac++;
}

