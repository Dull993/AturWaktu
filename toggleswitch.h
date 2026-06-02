#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QCheckBox>
#include <QPainter>
#include <QMouseEvent>

class ToggleSwitch : public QCheckBox {
    Q_OBJECT
public:
    explicit ToggleSwitch(QWidget *parent = nullptr) : QCheckBox(parent) {
        setFixedSize(55, 28);
        setCursor(Qt::PointingHandCursor);
    }

protected:

    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            setChecked(!isChecked());
            event->accept();
        } else {
            QCheckBox::mouseReleaseEvent(event);
        }
    }

    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            event->accept();
        } else {
            QCheckBox::mousePressEvent(event);
        }
    }


    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QBrush brush = isChecked() ? QBrush(QColor("#b67bfb")) : QBrush(QColor("#e4e3e9"));
        int x_pos = isChecked() ? width() - 24 : 4;

        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(0, 0, width(), height(), 14, 14);
        painter.setBrush(QBrush(Qt::white));
        painter.drawEllipse(x_pos, 4, 20, 20);
    }
};

#endif // TOGGLESWITCH_H