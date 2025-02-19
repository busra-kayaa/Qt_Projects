#include "benimbutonum.h"

benimbutonum::benimbutonum(QWidget *parent) : QPushButton(parent)
{
    connect(this,SIGNAL(clicked(bool)),this,SLOT(yerDegistir()));
}

void benimbutonum::mousePressEvent(QMouseEvent *ev)
{
    ilkKonum = ev->pos();
    //setText("X: " + QString::number(ev->x())+ " Y: " + QString::number(ev->y()));
}

void benimbutonum::mouseMoveEvent(QMouseEvent *ev)
{
    setGeometry(ev->x() - ilkKonum.x() + x(),
                ev->y() - ilkKonum.y() + y(),
                width(),height()); // ev ve ilk konum mouseun xi ,  tek x butonun xi
}

void benimbutonum::yerDegistir()
{
    //this->setGeometry(this->x()+20,this->y(),
            // this->width(),this->height());
    setGeometry(x() + 20 ,y() , width(), height());
}

/*
void benimbutonum::yerDegistir()
{

}
*/
