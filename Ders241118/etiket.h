#ifndef ETIKET_H
#define ETIKET_H

#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>

class etiket : public QLabel
{
    Q_OBJECT
public:
    explicit etiket(QWidget *parent = nullptr);

private:
    void dragEnterEvent(QDragEnterEvent*);
    void dropEvent(QDropEvent*);
    void mouseMoveEvent(QMouseEvent *);

signals:

};

#endif // ETIKET_H
