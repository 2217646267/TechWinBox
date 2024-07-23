#ifndef DRAGDROPLABEL_H
#define DRAGDROPLABEL_H

#include <QLabel>
#include <QEvent>
#include <QDragEnterEvent>
#include <QMimeData>

class DragDropLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DragDropLabel(QWidget *parent = nullptr);


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
signals:
    void signaldropEvent(QDropEvent *event);
public slots:
};

#endif // DRAGDROPLABEL_H
