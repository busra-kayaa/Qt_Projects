#include "kursun.h"

kursun::kursun(QWidget *parent) : QLabel(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &kursun::animate);

    int startSpeed = 150;
    timer->start(startSpeed);
}

void kursun::animate() {
    setGeometry(x(),y()-10,width(),height());
}
