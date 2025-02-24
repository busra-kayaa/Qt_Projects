#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDragEnterEvent>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionKaydet_triggered()
{
    if(yol.isEmpty()){
        yol = QFileDialog::getSaveFileName(this,"Dosya Kaydet", "/:C/Users/Busra");
        if(yol.isEmpty()) {
            return;
        }
    }
    kaydet(yol);
}

void MainWindow::on_actionFarkl_Kaydet_triggered()
{
    QString yolu = QFileDialog::getSaveFileName(this,"Dosya Kaydet","/:C/Users/Busra");
    if(yol.isEmpty()){
        return;
    }
    kaydet(yolu);
    yol = yolu;
}

void MainWindow::Ac() {
    QFile dosya(yol);
    if(dosya.open(QFile::ReadOnly)){
        QTextStream okunacak(&dosya);
        QString okunan = okunacak.readAll();
        ui->textEdit->setText(okunan);
        dosya.close();
    }
}

void MainWindow::on_actionA_triggered()
{
    QString yolu = QFileDialog::getOpenFileName(this,"Dosya Kaydet","/:C/Users/Busra");
    if(yolu.isEmpty()) {
        return;
    }
    yol = yolu;
    Ac();
}

void MainWindow::kaydet(QString path)
{
    QFile dosya(path);
    if(dosya.open(QFile::WriteOnly))
    {
        QTextStream yazilacak(&dosya);
        yazilacak <<ui->textEdit->toPlainText();
        dosya.flush();
        dosya.close();
    }
}

void MainWindow::on_actionYeni_triggered()
{
    ui->textEdit->clear();
    yol.clear();
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}
/*dragEnterEvent(QDragEnterEvent *event):

Bu fonksiyon, bir nesne (örneğin bir dosya) uygulamanın penceresi üzerine sürüklendiğinde tetiklenir.
event->accept() ifadesi, sürükleme olayının kabul edildiğini ve pencere üzerinde bırakılabileceğini belirtir. Bu, sürüklenen nesnenin bırakılabilir olduğunu kullanıcıya göstermek için bir görsel geri bildirim (örneğin, fare simgesinin değişmesi) sağlar.*/

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> yollar = event->mimeData()->urls();
    if(!yollar.isEmpty()) {
        yol = yollar.first().toLocalFile();
        Ac();
    }
}
