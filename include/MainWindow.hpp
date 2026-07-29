//
// Created by Леша Минов on 29.07.2026.
//

#pragma once
#include <QMainWindow>

class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    private slots:
        void buttonClicked();
private:
    QLabel* label;
    QPushButton* button;
};