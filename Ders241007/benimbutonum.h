#ifndef BENIMBUTONUM_H
#define BENIMBUTONUM_H

#include <QPushButton>
#include <QMouseEvent>

class benimbutonum : public QPushButton
{
    Q_OBJECT
public:
    explicit benimbutonum(QWidget *parent = nullptr);

private:
    void mousePressEvent(QMouseEvent*); //sistem tarafından var olan method, kendi sınıfında da uygulayabilirsin.
    void mouseMoveEvent(QMouseEvent*);
    QPoint ilkKonum;

signals:

public slots:
    void yerDegistir();
};

#endif // BENIMBUTONUM_H
