#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int x = 100, y =50;

    for (int i=0; i<2; ++i){
        for (int k=0; k<3; ++k) {
            etiket *et = new etiket(this);
            et->setGeometry(x,y,100,100);
            x+=110;
        }
        x = 100;
        y+= 110;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

