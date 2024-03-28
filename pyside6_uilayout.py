# Author: DotykProboszcza
#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //  główne okno
    QWidget window;
    window.setWindowTitle("Przykład przycisków");
    window.setGeometry(100, 100, 300, 200);

    // Przycisk do zamykania okna
    QPushButton closeButton("Zamknij", &window);              tutaj mozesz pozmieniac
    closeButton.setGeometry(10, 10, 80, 30);
    QObject::connect(&closeButton, &QPushButton::clicked, &app, &QApplication::quit);

    // Przycisk do minimalizowania okna
    QPushButton minimizeButton("Minimalizuj", &window);
    minimizeButton.setGeometry(100, 10, 100, 30);
    QObject::connect(&minimizeButton, &QPushButton::clicked, &window, &QWidget::showMinimized);

    window.show();

    return app.exec();
}