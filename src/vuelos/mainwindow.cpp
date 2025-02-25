#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , zoomLevel(1.0) // Inicializar el nivel de zoom
{
    ui->setupUi(this);

    // Cargar la imagen principal
    originalPix.load("/home/danna/ProyectoEDAI_ReservaDeVuelos/map.png");
    ui->image->setPixmap(originalPix);

    // Configurar iconos en los botones
    ui->zoominbutton->setIcon(QIcon("/home/danna/ProyectoEDAI_ReservaDeVuelos/zoomin.jpeg"));
    ui->zoomoutbutton->setIcon(QIcon("/home/danna/ProyectoEDAI_ReservaDeVuelos/zoomout.jpeg"));

    // Asegurar que los iconos sean visibles
    ui->zoominbutton->setIconSize(QSize(32, 32));
    ui->zoomoutbutton->setIconSize(QSize(32, 32));
}

// Aumentar el zoom
void MainWindow::on_zoominbutton_clicked()
{
    zoomLevel /= 1.2; // Aumentar el nivel de zoom
    applyZoom();
}

// Reducir el zoom
void MainWindow::on_zoomoutbutton_clicked()
{
    zoomLevel *= 1.2; // Reducir el nivel de zoom
    applyZoom();
}

// Método para aplicar zoom en la imagen
void MainWindow::applyZoom()
{
    QPixmap zoomedPix = originalPix.scaled(originalPix.size() * zoomLevel, Qt::KeepAspectRatio);
    ui->image->setPixmap(zoomedPix);
}


MainWindow::~MainWindow()
{
    delete ui;
}


