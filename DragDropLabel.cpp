#include "DragDropLabel.h"
#include <QDebug>)

DragDropLabel::DragDropLabel(QWidget *parent) : QLabel(parent)
{
     setAcceptDrops(true); // 启用拖放功能
     setAlignment(Qt::AlignLeft);
     setMinimumSize(400, 600);
}


void DragDropLabel::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction(); // 接受拖放事件
        qDebug() << "dragEnterEvent";
    }
}

void DragDropLabel::dropEvent(QDropEvent *event) {


        emit signaldropEvent(event);
    }
