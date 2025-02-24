#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void listele();

private slots:
    void on_Kaydet_clicked();

    void on_Guncelle_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_Sil_clicked();

private:
    Ui::MainWindow *ui;

    QSqlQuery *sorgu, *eklemeSorgu;
    QSqlQueryModel *model;

    QString num;
};
#endif // MAINWINDOW_H
