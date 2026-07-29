#include "MainWindow.hpp"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    auto* central = new QWidget(this);
    auto* layout = new QVBoxLayout(central);

    label = new QLabel("Hello Qt!", this);
    button = new QPushButton("Click me", this);

    layout->addWidget(label);
    layout->addWidget(button);

    setCentralWidget(central);

    connect(button,
            &QPushButton::clicked,
            this,
            &MainWindow::buttonClicked);

    setWindowTitle("MyUtility");
    resize(400, 200);
}

void MainWindow::buttonClicked()
{
    label->setText("Button pressed!");
}