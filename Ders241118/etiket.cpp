#include "etiket.h"
#include <QMimeData>
#include <QDrag>

etiket::etiket(QWidget *parent) : QLabel(parent)
{
    setScaledContents(true);
    setFrameShape(QFrame::Box);
    setAcceptDrops(true); //bırakılabilmeyi sağlıyor
    show();
}

void etiket::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void etiket::dropEvent(QDropEvent *event)
{
    etiket *gelen = qobject_cast<etiket*>(event->source()); //gelen nesnenin adresi

    if(gelen && gelen !=this) //kendisi değilse ve dışarıdan gelmemişse
    {
        QImage birakilan(pixmap()->toImage());
        this->setPixmap(QPixmap::fromImage(gelen->pixmap()->toImage()));
        gelen->setPixmap(QPixmap::fromImage(birakilan));
    }
    QList<QUrl> yollar = event->mimeData()->urls();
    if(yollar.isEmpty())
    {
        return;
    }

    QString yol = yollar.first().toLocalFile();
    QImage resim(yol);
    setPixmap(QPixmap::fromImage(resim));
}

void etiket::mouseMoveEvent(QMouseEvent *)
{
    QMimeData *mdata = new QMimeData();
    mdata->setImageData(pixmap()->toImage());

    QDrag *suruklenen = new QDrag(this);
    suruklenen->setMimeData(mdata);
    suruklenen->setPixmap(mdata->imageData().value<QPixmap>());
    suruklenen->exec(Qt::MoveAction);
}
