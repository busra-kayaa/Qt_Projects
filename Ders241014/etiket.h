#ifndef ETIKET_H
#define ETIKET_H

#include <QLabel>
#include <QTimer>
#include<QMouseEvent>

class Etiket : public QLabel
{
    Q_OBJECT
public:
    explicit Etiket(QWidget *parent = nullptr);
    void hiziAyarla(int hiz);

private:
    QTimer *zamanlayici = new QTimer();
    void mousePressEvent(QMouseEvent*); // italik olması reinclement method olduğu anlamına gelir.

private slots:
    void hareketlendir();

signals:

};

#endif // ETIKET_H
