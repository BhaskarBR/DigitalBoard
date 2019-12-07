#include "digitalboard.h"

DigitalBoard::DigitalBoard()
    : lastPos(QPoint(-1, -1))
{
    setAcceptedMouseButtons(Qt::AllButtons);
}

void DigitalBoard::paint(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawPath(pendingPath);
}

void DigitalBoard::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        //stroke started
        pendingPath.moveTo (event->pos());
        lastPos = event->pos();
    }
    else if(event->button() == Qt::RightButton){
        pendingPath.clear();
        update();
    }
}

void DigitalBoard::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && lastPos != QPoint(-1, -1)) {
        pendingPath.lineTo(event->pos());
        update();
        lastPos = event->pos();
    }
}

void DigitalBoard::mouseReleaseEvent(QMouseEvent */*event*/)
{
    //stroke completed
}
