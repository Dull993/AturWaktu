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
        container->setMinimumHeight(85); // Beri ruang vertikal yang cukup
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

        // 2. Icon Bel
        iconLabel = new QLabel("🔔", container);
        iconLabel->setFixedSize(42, 42);
        iconLabel->setAlignment(Qt::AlignCenter);

        // 3. Layout Teks Jam & Hari
        QVBoxLayout *textLayout = new QVBoxLayout();
        textLayout->setSpacing(2);
        textLayout->setContentsMargins(0, 4, 0, 4);

        timeLabel = new QLabel(timeStr, container);
        descLabel = new QLabel(daysStr, container);
        descLabel->setStyleSheet("font-size: 13px; color: #a09eaa; font-family: 'Segoe UI', 'Inter';");

        textLayout->addWidget(timeLabel);
        textLayout->addWidget(descLabel);

        // 4. Toggle Switch
        toggleSwitch = new ToggleSwitch(container);
        toggleSwitch->setChecked(isOn);


        // 5. Tombol Hapus (Dibuat kontras tinggi agar tidak samar/hilang)
        btnDelete = new QPushButton("Hapus", container);
        btnDelete->setFixedSize(36, 36);
        btnDelete->setCursor(Qt::PointingHandCursor);
        btnDelete->setStyleSheet(
            "QPushButton {"
            "   background-color: #ff4d6d;" // Merah solid cerah sebagai background
            "   color: white;"              // Teks silang warna PUTIH TEGAS
            "   border: none;"
            "   border-radius: 10px;"
            "   font-size: 16px;"           // Perbesar ukuran silang ke 16px
            "   font-weight: bold;"         // Buat huruf X menjadi tebal
            "   font-family: 'Segoe UI', Arial;"
            "}"
            "QPushButton:hover {"
            "   background-color: #ff758f;" // Merah agak terang saat di-hover
            "}"
            "QPushButton:pressed {"
            "   background-color: #c9184a;" // Merah tua saat diklik
            "}"
            );

        // 6. Susun Komponen ke dalam Layout Container (Horizontal)
        QHBoxLayout *cardLayout = new QHBoxLayout(container);
        cardLayout->setContentsMargins(16, 12, 16, 12);
        cardLayout->setSpacing(14);

        cardLayout->addWidget(iconLabel);
        cardLayout->addLayout(textLayout);
        cardLayout->addStretch();
        cardLayout->addWidget(toggleSwitch);
        cardLayout->addWidget(btnDelete);

        // 7. Layout Utama Widget
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(8, 6, 8, 6);
        mainLayout->addWidget(container);

        // Hubungkan Signal & Slot
        connect(toggleSwitch, &ToggleSwitch::toggled, this, &AlarmCardWidget::updateCardStyle);
        connect(btnDelete, &QPushButton::clicked, this, &AlarmCardWidget::deletePressed);

        updateCardStyle(isOn);
    }

    // Fungsi getter penampung data
    QString getTimeText() const { return timeLabel->text(); }
    QString getDaysText() const { return descLabel->text(); }
    bool isAlarmActive() const { return toggleSwitch->isChecked(); }

    // Memaksa QListWidget memberikan ruang vertikal yang lega
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