#include "blok.h"

blok::blok(QWidget *parent) : QLabel(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &blok::animate);

    int startSpeed = 200;
    timer->start(startSpeed);
}

void blok::animate() {
    setGeometry(x(), y() + 10, width(), height());

}
