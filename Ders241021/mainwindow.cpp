#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    yol.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionYeni_2_triggered()
{
    ui->textEdit->clear();
    yol.clear();
}

void MainWindow::kaydet(QString yolu)
{
    QFile dosya(yolu);
    if(dosya.open(QFile::WriteOnly)){
        QTextStream yazilacak(&dosya);
        yazilacak << ui->textEdit->toPlainText();
        dosya.flush();
        dosya.close();
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> yollar = event->mimeData()->urls();
    if (!yollar.isEmpty()) {
        yol = yollar.first().toLocalFile();
        Ac();
    }
}

void MainWindow::Ac()
{
    QFile dosya(yol);
    if (dosya.open(QFile::ReadOnly)) {
        QTextStream okunacak(&dosya);
        QString okunan = okunacak.readAll();
        ui->textEdit->setText(okunan);
        dosya.close();
    }
}

void MainWindow::on_actionFarkl_Kaydet_triggered()
{
    QString yolu = QFileDialog::getSaveFileName(this, "Dosya Kaydet","/home/vahit","txt");
    if (yolu.isEmpty()) {
        return;
    }
    kaydet(yolu);
    yol = yolu;
}


void MainWindow::on_action_Kaydet_triggered()
{
    if (yol.isEmpty()) {
        yol = QFileDialog::getSaveFileName(this,"Dosya Kaydet","/home/vahit");
        if (yol.isEmpty()) {
            return;
        }
    }
    kaydet(yol);
}


void MainWindow::on_actionA_triggered()
{
    QString yolu = QFileDialog::getOpenFileName(this, "Dosya Aç","/home/vahit");
    if (yolu.isEmpty()) {
        return;
    }
    yol = yolu;
    Ac();
}

