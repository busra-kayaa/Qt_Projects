#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionYeni_2_triggered();

    void on_actionFarkl_Kaydet_triggered();

    void on_action_Kaydet_triggered();

    void on_actionA_triggered();

private:
    Ui::MainWindow *ui;
    void kaydet(QString);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void Ac();
    QString yol;
};
#endif // MAINWINDOW_H
