#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Etiket *et = new Etiket(this);
    et->setScaledContents(true); //resmin tamamını görmemizi sağlıyor. Resmi labela tam sığdırıyor.
    et->setGeometry(100,100,100,100);
    QImage resim(":/res/image/10.jpg");
    if (resim.isNull()) {
        qDebug() << "Resim yüklenemedi!";
    } else {// prefix res
    //:(iki nokta) (dizin geçişi olmadığını prefix tanımlaması olduğunu gösterir)
        et->setPixmap(QPixmap::fromImage(resim));
    }
    et->setFrameShape(QFrame::Box);
    et->show();
    //QMessageBox::information(this,"Başlık","Yapıcı method oluşturuldu");
    labelim = et; //aynı adresi işraet ediyor.
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    labelim->hiziAyarla(1000-value);
}

