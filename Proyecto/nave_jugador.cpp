
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear la ventana principal
    QWidget *window = new QWidget;
    window->setWindowTitle("Mi Interfaz Simple");

    // Crear un botón
    QPushButton *button = new QPushButton("Haz clic aquí");

    // Crear un layout y agregar el botón al layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);

    // Establecer el layout en la ventana principal
    window->setLayout(layout);

    // Mostrar la ventana principal
    window->show();

    // Ejecutar la aplicación
    return app.exec();
}
