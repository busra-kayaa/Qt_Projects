#include "etiket.h"
#include <QRandomGenerator>

Etiket::Etiket(QWidget *parent) : QLabel(parent)
{
    //QTimer *zamanlayici = new QTimer(); //global olmalı
    zamanlayici = new QTimer();
    connect(zamanlayici,SIGNAL(timeout()), this, SLOT(hareketlendir()));
    //zamanlayici->start(100);
}

void Etiket::hiziAyarla(int hiz)
{
    zamanlayici->stop();
    if (hiz!=0){
        zamanlayici->start(hiz);
    }
}

void Etiket::mousePressEvent(QMouseEvent *event)
{
    int secilen = QRandomGenerator::global()->bounded(10);
    QImage resim(":/res/image/"+QString::number(secilen)+".jpg");
    setScaledContents(true);
    setPixmap(QPixmap::fromImage(resim));
}

void Etiket::hareketlendir()
{
    setGeometry(x()+10,y(),width(),height());
}
