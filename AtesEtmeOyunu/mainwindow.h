#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "blok.h"
#include "kursun.h"
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_getNumberButton_clicked();
    void on_getNumberButton2_clicked();
    void createBlok(int sayi);
    void checkCollisions();  // Çarpışma kontrol işlevi

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit;
    int vurulanBlok;
    int vurulmayanBlok;
    QLabel *label1;
    QLabel *label2;

    QList<blok*> *blocks;   // Blokları saklamak için liste
    QList<kursun*> *bullets; // Kurşunları saklamak için liste
};

#endif // MAINWINDOW_H
