#include "MainWindow.hpp"

#include <QPushButton>

MainWindow::MainWindow() {
    setupUi();
}

void MainWindow::setupUi() {
    resize(600, 400);

    mainLabel_.setText("Качалкин");
    urlInput_.setPlaceholderText("Вставьте URL:");
    qualityBox_.addItems({
        "Наивысшее качество",
        "2160p",
        "1440p",
        "1080p",
        "720p",
        "480p"
    });
    outputFormatBox_.addItems({
        "mp4",
        "webm"
    });
    downloadButton_.setText("Скачать");
}
