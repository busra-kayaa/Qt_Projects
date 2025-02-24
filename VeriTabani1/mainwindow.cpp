#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Busra/okul.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Bağlantı Hatası!!", db.lastError().text());
    }
    else{
        QMessageBox::information(this,"Bilgi", "Veri Tabanına Başarıyla Bağlandı");
    }

    sorgu = new QSqlQuery(db);
    eklemeSorgu = new QSqlQuery(db);
    model = new QSqlQueryModel();

    listele();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listele()
{
    bool kontrol = sorgu->exec("select * from ogrenci");
    if(!kontrol)
    {
        QMessageBox::critical(this," Sorgu Hatası!!",sorgu->lastError().text());
    }
    model->setQuery(*sorgu);
    ui->tableView->setModel(model);
}


void MainWindow::on_Kaydet_clicked()
{
    eklemeSorgu->prepare("insert into ogrenci values(?, ?, ?)");

    eklemeSorgu->addBindValue(ui->numara->text());
    eklemeSorgu->addBindValue(ui->ad->text());
    eklemeSorgu->addBindValue(ui->soyad->text());

    if(!eklemeSorgu->exec()){
        QMessageBox::critical(this,"Sorgu Hatası!!",eklemeSorgu->lastError().text());
    }
    listele();
}


void MainWindow::on_Guncelle_clicked()
{
    eklemeSorgu->prepare("update ogrenci set ogrno = ?, adi = ?, soyadi = ? where ogrno = ?");

    eklemeSorgu->addBindValue(ui->numara->text());
    eklemeSorgu->addBindValue(ui->ad->text());
    eklemeSorgu->addBindValue(ui->soyad->text());

    eklemeSorgu->addBindValue(num);

    if(!eklemeSorgu->exec())
    {
        QMessageBox::critical(this, "Sorgu Hatası", eklemeSorgu->lastError().text());
    }
    listele();
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    num = model->index(index.row(),0).data().toString();

    ui->numara->setText(num);
    ui->ad->setText(model->index(index.row(),1).data().toString());
    ui->soyad->setText(model->index(index.row(),2).data().toString());

}

void MainWindow::on_Sil_clicked()
{
    eklemeSorgu->prepare("DELETE FROM ogrenci WHERE ogrno = ?");

    eklemeSorgu->addBindValue(num);
    if(!eklemeSorgu->exec())
    {
        QMessageBox::critical(this, "Sorgu Hatası", eklemeSorgu->lastError().text());
    }
    listele();
}

