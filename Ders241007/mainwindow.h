#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "benimbutonum.h" // <> olunca sistemin kütüphane dosyasında arar.

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int sayac;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
