#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>

class MainWindow : public QMainWindow {
public:
    MainWindow();

private:
    void setupUi();
    void setupConnections();

    QLabel mainLabel_;
    QLineEdit urlInput_;

    QComboBox qualityBox_;
    QComboBox outputFormatBox_;

    QCheckBox audioOnlyCheckBox_;
    QCheckBox subtitlesCheckBox_;

    QPushButton downloadButton_;
};