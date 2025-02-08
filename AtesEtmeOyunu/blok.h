#ifndef BLOK_H
#define BLOK_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class blok : public QLabel
{
    Q_OBJECT
public:
    explicit blok(QWidget *parent = nullptr);

private:
    QTimer *timer = new QTimer();

signals:

private slots:
    void animate();
};

#endif // BLOK_H
