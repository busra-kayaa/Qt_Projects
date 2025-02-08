#ifndef KURSUN_H
#define KURSUN_H

#include <QWidget>
#include <QTimer>
#include <QLabel>

class kursun : public QLabel
{
    Q_OBJECT
public:
    explicit kursun(QWidget *parent = nullptr);

private:
    QTimer *timer = new QTimer();
    void animate();

signals:

};

#endif // KURSUN_H
