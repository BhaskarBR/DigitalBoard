#ifndef DIGITALBOARD_H
#define DIGITALBOARD_H

#include <QQuickPaintedItem>
#include <QPainterPath>
#include <QImage>
#include <QPainter>

class DigitalBoard : public QQuickPaintedItem
{
    Q_OBJECT
public:
    DigitalBoard();

    void paint(QPainter *painter) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *) override;

signals:

public slots:

private:
    QPoint lastPos;
    QPainterPath pendingPath;
};

#endif // DIGITALBOARD_H
