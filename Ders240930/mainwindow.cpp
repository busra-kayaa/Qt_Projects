#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->bayan->setChecked(true); //formdaki elemanlara ui üzerinden ulaşılır.
    konum = ui->pushButton_2->geometry();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    if(ui->bay->isChecked() != true && ui->bayan->isChecked() != true)
    {
        QMessageBox::information(this,"Uyarı","Adam gibi seçim yap.");
        return;
    }
    if (ui->bay->isChecked() == true) // if(ui->bay->isChecked())
         ui->sonuc->setText(ui->bay->text());
    else
        ui->sonuc->setText(ui->bayan->text());

    /*if (ui->bay->isChecked())
            ui->sonuc->setText(ui->bay->text());
    else if (ui->bayan->isChecked())
        ui->sonuc->setText(ui->bayan->text());
    else {
        QMessageBox::information(this,"Uyarı","Adam gibi seçim yap.");
    }*/
}


void MainWindow::on_pushButton_2_pressed()
{
    ui->pushButton_2->setGeometry(ui->pushButton_2->x(),ui->pushButton_2->y(),
                                  ui->pushButton_2->width()*1.25, ui->pushButton_2->height()*1.25);
}


void MainWindow::on_pushButton_2_released()
{
    ui->pushButton_2->setGeometry(konum);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->sag->isChecked())
    {
        ui->pushButton->setGeometry(ui->pushButton->x()+ ui->horizontalSlider->value(),
                                ui->pushButton->y(), ui->pushButton->width(),ui->pushButton->height());
    }
    else{
        ui->pushButton->setGeometry(ui->pushButton->x()- ui->horizontalSlider->value(),
                                    ui->pushButton->y(), ui->pushButton->width(),ui->pushButton->height());
    }

}

