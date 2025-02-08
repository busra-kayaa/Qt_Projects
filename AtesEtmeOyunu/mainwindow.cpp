#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QImage>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QInputDialog>
#include <QTimer>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vurulanBlok(0) // Başlangıçta vurulan blok sayısını 0 yap
    , vurulmayanBlok(0) // Başlangıçta vurulmayan blok sayısını 0 yap
{
    ui->setupUi(this);

    // Kullanıcıdan bir sayı girmesini isteyen label oluştur
    QLabel *label = new QLabel("Bir sayı girin:", this);
    label->setGeometry(50, 10, 150, 30);
    label->show();

    // Kullanıcıdan girdi almak için bir QLineEdit oluştur
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(50, 40, 150, 30);
    lineEdit->show();

    // Sayıyı onaylamak için bir buton oluştur
    QPushButton *getNumberButton = new QPushButton("Sayıyı Onaylayın", this);
    getNumberButton->setGeometry(50, 100, 150, 30);
    getNumberButton->show();

    // Butona tıklandığında on_getNumberButton_clicked slotunu çağır
    connect(getNumberButton, &QPushButton::clicked, this, &MainWindow::on_getNumberButton_clicked);

    // İkinci bir sayı girişi için buton oluştur
    QPushButton *getNumberButton2 = new QPushButton("Bir Sayi Girin", this);
    getNumberButton2->setGeometry(300, 40, 150, 30);
    connect(getNumberButton2, &QPushButton::clicked, this, &MainWindow::on_getNumberButton2_clicked);

    // Blok ve kurşunları saklayacak listeleri başlat
    blocks = new QList<blok*>(); // Bloklar için liste
    bullets = new QList<kursun*>(); // Kurşunlar için liste

    // Çarpışma kontrolü için bir timer başlat
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkCollisions); // Timer her zaman çarpışma kontrol fonksiyonunu çağıracak
    timer->start(50);  // 50 ms'de bir çarpışma kontrolü yap

    // Vurulan blok sayısını gösterecek label1'i oluştur
    label1 = new QLabel(this);
    label1->setText("Vurulan Blok: 0");
    label1->setGeometry(300, 100, 200, 30);
    label1->show();

    // Vurulmayan blok sayısını gösterecek label2'yi oluştur
    label2 = new QLabel(this);
    label2->setText("Vurulmayan Blok: 0");
    label2->setGeometry(300, 130, 200, 30);
    label2->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    qDeleteAll(*blocks);
    qDeleteAll(*bullets);
    delete blocks;
    delete bullets;
}

// Fare tıklaması olayını yakala
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    kursun *k = new kursun(this); // Yeni bir kurşun oluştur
    k->setScaledContents(true);

    // Kurşun için resim ayarla
    QImage image(":/res/image/kursun.png");
    k->setPixmap(QPixmap::fromImage(image));
    int kursunSize = 50; // Kurşun boyutu
    k->setGeometry(event->x() - kursunSize / 2, event->y() - kursunSize / 2, kursunSize, kursunSize); // Kurşunun konumunu ayarla

    k->show(); // Kurşunu göster
    bullets->append(k);  // Kurşunu listeye ekle
}

// Belirtilen sayıda blok oluştur
void MainWindow::createBlok(int sayi)
{
    vurulmayanBlok += sayi; // Yeni oluşturulan blokları vurulmayan sayıya ekle

    // Belirtilen sayı kadar blok oluştur
    for (int i = 0; i < sayi; ++i)
    {
        int x = QRandomGenerator::global()->bounded(0, this->width() - 50); // Blok genişliği kadar sınır koyuyoruz
        blok *b = new blok(this);
        b->setScaledContents(true);
        int blokSize = 50; // Blok boyutu
        b->setGeometry(x, 0, blokSize, blokSize); // Blok konumunu ayarla
        QImage image(":/res/image/blok.png");
        b->setPixmap(QPixmap::fromImage(image));
        b->show(); // Bloğu göster
        blocks->append(b);  // Blokları listeye ekle
    }

    // Vurulmayan blok sayısını label'de güncelle
    label2->setText("Vurulmayan Blok: " + QString::number(vurulmayanBlok));
}

// Çarpışmaları kontrol et
void MainWindow::checkCollisions()
{
    // Tüm kurşunlar için döngü
    for (int i = bullets->size() - 1; i >= 0; --i) {
        kursun *bullet = bullets->at(i); // Mevcut kurşunu al

        // Tüm bloklar için döngü
        for (int j = blocks->size() - 1; j >= 0; --j) {
            blok *block = blocks->at(j); // Mevcut bloğu al

            // Kurşun ve blok arasındaki çarpışmayı kontrol et
            if (bullet->geometry().intersects(block->geometry())) {
                // Çarpışma gerçekleştiğinde
                vurulanBlok++;
                vurulmayanBlok--;
                // Vurulan ve vurulmayan blok sayısını label'de göster
                label1->setText("Vurulan Blok: " + QString::number(vurulanBlok));
                label2->setText("Vurulmayan Blok: " + QString::number(vurulmayanBlok));

                // Bloğu gizle ve listeden çıkar
                block->hide();
                blocks->removeAt(j);
                delete block; // Bloğu serbest bırak

                // Kurşunu gizle ve listeden çıkar
                bullet->hide();
                bullets->removeAt(i);
                delete bullet; // Kurşunu serbest bırak
                break;  // Bu kurşun başka bir blokla çarpışmayacağı için döngüden çıkıyoruz
            }
        }
    }
}

// Kullanıcıdan girdi almak için butona tıklandığında çağrılır
void MainWindow::on_getNumberButton_clicked()
{
    bool ok;
    int sayi = lineEdit->text().toInt(&ok); // QLineEdit'ten girdi al
    if (ok) {
        createBlok(sayi); // Blokları oluştur
    } else {
        // Geçerli bir sayı girilmezse uyarı ver
        QMessageBox::warning(this, "Uyarı", "Lütfen geçerli bir sayı girin!");
    }
}

// Kullanıcıdan ikinci bir sayı girişi almak için butona tıklandığında çağrılır
void MainWindow::on_getNumberButton2_clicked()
{
    bool ok;
    // QInputDialog ile kullanıcıdan sayı al
    int sayi = QInputDialog::getInt(this, "Sayı Gir", "Bir sayı girin:", 0, 0, 100, 1, &ok);
    if (ok) {
        createBlok(sayi); // Blokları oluştur
    }
}
