#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QCheckBox>
#include <QPainter>

class ToggleSwitch : public QCheckBox {
    Q_OBJECT
public:
    explicit ToggleSwitch(QWidget *parent = nullptr) : QCheckBox(parent) {
        setFixedSize(55, 28);
        setCursor(Qt::PointingHandCursor);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QBrush brush;
        int x_pos;

        if (isChecked()) {
            brush = QBrush(QColor("#d66efd"));
            x_pos = width() - 24;
        } else {
            brush = QBrush(QColor("#e4e3e9"));
            x_pos = 4;
        }

        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(0, 0, width(), height(), 14, 14);

        painter.setBrush(QBrush(Qt::white));
        painter.drawEllipse(x_pos, 4, 20, 20);
    }
};

#endif // TOGGLESWITCH_H