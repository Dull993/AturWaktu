#ifndef ALARMCARDWIDGET_H
#define ALARMCARDWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include "toggleswitch.h"

class AlarmCardWidget : public QWidget {
    Q_OBJECT
public:
    AlarmCardWidget(const QString &timeStr, const QString &daysStr, bool isOn = true, QWidget *parent = nullptr)
        : QWidget(parent)
    {
        // 1. Container Utama (Card Putih)
        container = new QFrame(this);
        container->setObjectName("AlarmCard");
        container->setMinimumHeight(85);
        container->setStyleSheet(
            "QFrame#AlarmCard {"
            "   background-color: white;"
            "   border-radius: 16px;"
            "}"
            );

        // Efek Shadow Lembut
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
        shadow->setBlurRadius(12);
        shadow->setColor(QColor(0, 0, 0, 15));
        shadow->setOffset(0, 3);
        container->setGraphicsEffect(shadow);

        iconLabel = new QLabel("🔔", container);
        iconLabel->setFixedSize(42, 42);
        iconLabel->setAlignment(Qt::AlignCenter);

        // 3. Layout Teks Vertikal (Jam & Hari)
        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(4);
        textLayout->setContentsMargins(0, 2, 0, 2);

        timeLabel = new QLabel(timeStr, container);
        descLabel = new QLabel(daysStr, container);
        descLabel->setStyleSheet("font-size: 13px; color: #a09eaa; font-family: 'Segoe UI', 'Inter';");

        textLayout->addWidget(timeLabel);
        textLayout->addWidget(descLabel);

        // 4. Toggle Switch (Geser ke Kanan)
        toggleSwitch = new ToggleSwitch(container);
        toggleSwitch->setChecked(isOn);

        // 5. Tombol Hapus (Diletakkan di Samping Kanan Toggle Switch)
        btnDelete = new QPushButton("🗑", container);
        btnDelete->setFixedSize(36, 36);
        btnDelete->setCursor(Qt::PointingHandCursor);
        btnDelete->setStyleSheet(
            "QPushButton {"
            "   background-color: #fff0f3;" // Background pink soft
            "   color: #ff5c75;"              // Teks silang merah tegas
            "   border: none;"
            "   border-radius: 10px;"
            "   font-size: 14px;"
            "   font-weight: bold;"
            "   font-family: 'Segoe UI', Arial;"
            "   padding: 0px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #ff4d6d;"
            "   color: white;"
            "}"
            "QPushButton:pressed {"
            "   background-color: #c9184a;"
            "}"
            );


        QHBoxLayout *cardLayout = new QHBoxLayout(container);
        cardLayout->setContentsMargins(18, 12, 18, 12);
        cardLayout->setSpacing(14);

        cardLayout->addWidget(iconLabel);
        cardLayout->addLayout(textLayout);
        cardLayout->addStretch();
        cardLayout->addWidget(toggleSwitch);
        cardLayout->addWidget(btnDelete);      // Tombol delete berada tepat di paling kanan

        // 7. Layout Utama Widget Pembungkus
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(8, 4, 8, 4);
        mainLayout->addWidget(container);


        connect(toggleSwitch, &ToggleSwitch::toggled, this, &AlarmCardWidget::updateCardStyle);
        connect(btnDelete, &QPushButton::clicked, this, &AlarmCardWidget::deletePressed);

        updateCardStyle(isOn);
    }

    QString getTimeText() const { return timeLabel->text(); }
    QString getDaysText() const { return descLabel->text(); }
    bool isAlarmActive() const { return toggleSwitch->isChecked(); }


    QSize sizeHint() const override {
        return QSize(width(), 97);
    }

signals:
    void deletePressed();

private slots:
    void updateCardStyle(bool checked) {
        if (checked) {
            timeLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #14121e; font-family: 'Segoe UI', 'Inter';");
            iconLabel->setStyleSheet("background-color: #f6eeff; color: #8c73f2; font-size: 18px; border-radius: 12px;");
        } else {
            timeLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #b5b3bc; font-family: 'Segoe UI', 'Inter';");
            iconLabel->setStyleSheet("background-color: #f1f0f5; color: #b5b3bc; font-size: 18px; border-radius: 12px;");
        }
    }

private:
    QFrame *container;
    QLabel *iconLabel;
    QLabel *timeLabel;
    QLabel *descLabel;
    ToggleSwitch *toggleSwitch;
    QPushButton *btnDelete;
};

#endif // ALARMCARDWIDGET_H