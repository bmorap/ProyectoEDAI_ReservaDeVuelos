#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agregarciudad.h"
#include "agregarvuelo.h"
#include "eliminarciudad.h"
#include "eliminarvuelo.h"
#include <QMouseEvent>
#include <QTransform>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <QAbstractItemView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow { background-color:rgb(255, 255, 255); }");
    this->setFixedSize(ui->image->width() + 10, ui->image->height() + 200);


    // Lista de estados de EE. UU.
    QStringList estados = {
        "Alabama", "Alaska", "Arizona", "Arkansas", "California",
        "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
        "Hawaii", "Idaho", "Illinois"
    };

    // Agregar los estados al combo box
    ui->comboBox->addItems(estados);
    ui->comboBox_2->addItems(estados);
    ui->label->setStyleSheet("font-size: 11pt;");
    ui->label_2->setStyleSheet("font-size: 11pt;");
    QFont font("Helvetica", 11);
    qApp->setFont(font);
    qApp->setStyleSheet(
        "QPushButton {"
        "   background-color: #3498db;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 5px;"
        "   font-size: 12pt;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2980b9;"
        "}"
    );

    ui->comboBox->setStyleSheet(
        "QComboBox {"
        "    background-color: #ffffff;"
        "    border: 2px solid #2980b9;"
        "    border-radius: 4px;"
        "    padding: 2px;"
        "    font: 12pt 'Helvetica';"
        "    color: #222;"
        "}"
        "QComboBox:hover {"
        "    background-color: #f0f0f0"  // Fondo al pasar el cursor sobre el combo
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 30px;"
        "    border-left: 2px solid #2980b9;"
        "}"
    );
    
    ui->comboBox_2->setStyleSheet(
        "QComboBox {"
        "    background-color: #ffffff;"
        "    border: 2px solid #2980b9;"
        "    border-radius: 4px;"
        "    padding: 2px;"
        "    font: 12pt 'Helvetica';"
        "    color: #222;"
        "}"
        "QComboBox:hover {"
        "    background-color: #f0f0f0"  // Fondo al pasar el cursor sobre el combo
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 30px;"
        "    border-left: 2px solid #2980b9;"
        "}"
    );

        // Construir la ruta correcta a la imagen basada en la ubicación del ejecutable
    QString imagePath = QDir(QCoreApplication::applicationDirPath()).filePath("../src/vuelos/usamap.jpg");

    // Verificar si la imagen existe antes de intentar cargarla
    if (!QFile::exists(imagePath)) {
        qDebug() << "Error: No se encuentra la imagen en:" << imagePath;
    } else {
        if (!originalPix.load(imagePath)) {
            qDebug() << "Error: No se pudo cargar la imagen.";
        } else {
            qDebug() << "Imagen cargada correctamente desde:" << imagePath;
            ui->image->setPixmap(originalPix.scaled(ui->image->size(), Qt::KeepAspectRatio));
        }
    }
    
    ui->image->setPixmap(originalPix);

    // Inicializar las coordenadas de las ciudades
    // Estas son coordenadas aproximadas
    cities["Alabama"] = CityInfo{"Alabama", QPoint(320, 290)};
    cities["Alaska"] = CityInfo{"Alaska", QPoint(100, 100)};
    cities["Arizona"] = CityInfo{"Arizona", QPoint(150, 250)};
    cities["Arkansas"] = CityInfo{"Arkansas", QPoint(280, 270)};
    cities["California"] = CityInfo{"California", QPoint(100, 200)};
    cities["Colorado"] = CityInfo{"Colorado", QPoint(200, 220)};
    cities["Connecticut"] = CityInfo{"Connecticut", QPoint(380, 180)};
    cities["Delaware"] = CityInfo{"Delaware", QPoint(370, 210)};
    cities["Florida"] = CityInfo{"Florida", QPoint(350, 320)};
    cities["Georgia"] = CityInfo{"Georgia", QPoint(330, 280)};
    cities["Hawaii"] = CityInfo{"Hawaii", QPoint(130, 320)};
    cities["Idaho"] = CityInfo{"Idaho", QPoint(150, 160)};
    cities["Illinois"] = CityInfo{"Illinois", QPoint(300, 220)};


    // Agregar ciudades con coordenadas (x, y)
    grafo.agregarCiudad("Alabama", 320, 290);
    grafo.agregarCiudad("Alaska", 100, 100);
    grafo.agregarCiudad("Arizona", 150, 250);
    grafo.agregarCiudad("Arkansas", 280, 270);
    grafo.agregarCiudad("California", 100, 200);
    grafo.agregarCiudad("Colorado", 200, 220);
    grafo.agregarCiudad("Connecticut", 380, 180);
    grafo.agregarCiudad("Delaware", 370, 210);
    grafo.agregarCiudad("Florida", 350, 320);
    grafo.agregarCiudad("Georgia", 330, 280);
    grafo.agregarCiudad("Hawaii", 130, 320);
    grafo.agregarCiudad("Idaho", 150, 160);
    grafo.agregarCiudad("Illinois", 300, 220);

    // Agregar conexiones entre ciudades con su distancia
    grafo.agregarConexion("Alabama", "Georgia", 200);
    grafo.agregarConexion("Georgia", "Florida", 300);
    grafo.agregarConexion("Florida", "Alaska", 500);
    grafo.agregarConexion("Idaho", "California", 100);
    grafo.agregarConexion("Hawaii", "Georgia", 150);
    grafo.agregarConexion("Georgia", "Idaho", 770);
    grafo.agregarConexion("Delaware", "Colorado", 100);
    grafo.agregarConexion("Idaho", "Illinois", 190);

    // Conectar los eventos de cambio en los combobox
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    connect(ui->button_calcularRutaOptima, &QPushButton::clicked, this, &MainWindow::button_calcularRutaOptima);

}

void MainWindow::button_calcularRutaOptima()
{
    QString origen = ui->comboBox->currentText();
    QString destino = ui->comboBox_2->currentText();

    try {
        // Obtener la ruta óptima usando Dijkstra
        vector<string> ruta = dijkstra(grafo, origen.toStdString(), destino.toStdString());

        // Verificar si se encontró una ruta
        if (ruta.empty()) {
            ui->statusbar->showMessage("No se encontró una ruta entre " + origen + " y " + destino);
            return;
        }

        // Convertir la ruta de `vector<string>` a `QVector<QString>`
        QVector<QString> rutaQt;
        for (const string& ciudad : ruta) {
            rutaQt.append(QString::fromStdString(ciudad));
        }

        // Mostrar la ruta en la barra de estado
        QString rutaStr;
        for (int i = 0; i < rutaQt.size(); i++) {
            rutaStr += rutaQt[i];
            if (i < rutaQt.size() - 1) {
                rutaStr += " -> ";
            }
        }
        ui->statusbar->showMessage("Ruta óptima: " + rutaStr);

        // Dibujar la ruta en el mapa
        updateMapDisplay(rutaQt);
    } catch (const std::exception& e) {
        ui->statusbar->showMessage("Error al calcular la ruta: " + QString(e.what()));
    }
}

void MainWindow::updateMapDisplay(QVector<QString> ruta)
{
    QPixmap mapaActualizado = originalPix.copy();
    QPainter painter(&mapaActualizado);
    painter.setRenderHint(QPainter::Antialiasing);

    // Lista de ciudades originales
    QStringList ciudadesOriginales = {
        "Alabama", "Alaska", "Arizona", "Arkansas", "California",
        "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
        "Hawaii", "Idaho", "Illinois"
    };

    // Dibujar todas las ciudades primero
    for (const auto& ciudad : cities.keys()) {
        QPoint pos = cities[ciudad].coordinates;

        // Si es una ciudad original, dibujarla en rojo
        if (ciudadesOriginales.contains(ciudad)) {
            painter.setBrush(QBrush(Qt::red));
        }
        // Si es una ciudad agregada posteriormente, dibujarla en verde
        else {
            painter.setBrush(QBrush(Qt::green));
        }

        painter.setPen(Qt::black);
        painter.drawEllipse(pos, 8, 8);
        painter.drawText(pos.x() + 10, pos.y() + 5, ciudad);
    }

    // Dibujar conexiones conocidas manualmente
    // Este es un workaround ya que no podemos obtener todas las conexiones del grafo
    painter.setPen(QPen(Qt::darkGray, 2, Qt::DashLine));

    // Lista de conexiones conocidas
    // Puedes añadir más conexiones a esta lista conforme se vayan agregando al grafo
    struct ConexionInfo {
        QString origen;
        QString destino;
        double peso;
    };

    QVector<ConexionInfo> conexiones = {
        {"Alabama", "Georgia", 200},
        {"Georgia", "Florida", 300},
        {"Florida", "Texas", 500},
        {"Idaho", "California", 1000}
    };

    for (const auto& conexion : conexiones) {
        if (cities.contains(conexion.origen) && cities.contains(conexion.destino)) {
            QPoint p1 = cities[conexion.origen].coordinates;
            QPoint p2 = cities[conexion.destino].coordinates;
            painter.drawLine(p1, p2);

            // Dibujar el peso de la conexión
            QPoint midPoint((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2);
            painter.drawText(midPoint, QString::number(conexion.peso));
        }
    }

    // Dibujar la ruta calculada (si hay)
    if (!ruta.isEmpty()) {
        painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
        for (int i = 0; i < ruta.size() - 1; i++) {
            QPoint p1 = cities[ruta[i]].coordinates;
            QPoint p2 = cities[ruta[i + 1]].coordinates;
            painter.drawLine(p1, p2);
        }
    }

    ui->image->setPixmap(mapaActualizado);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_AgregarCiudad_clicked()
{
    AgregarCiudad *ventana2 = new AgregarCiudad(this);

    // Conectar la señal de la ventana secundaria con la función agregarCiudadDesdeVentana
    connect(ventana2, &AgregarCiudad::ciudadAgregada, this, &MainWindow::agregarCiudadDesdeVentana);

    ventana2->exec(); // Muestra la ventana de forma modal
}

void MainWindow::agregarCiudadDesdeVentana(QString nombre, int x, int y)
{
    if (grafo.agregarCiudad(nombre.toStdString(), x, y)) {
        // Agregar a los combobox
        ui->comboBox->addItem(nombre);
        ui->comboBox_2->addItem(nombre);

        // Agregar la ciudad al mapa de ciudades
        cities[nombre] = CityInfo{nombre, QPoint(x, y)};

        // Redibujar el mapa para mostrar la nueva ciudad
        updateMapDisplay(QVector<QString>()); // Redibuja sin ruta

        ui->statusbar->showMessage("Ciudad agregada exitosamente.");
    } else {
        ui->statusbar->showMessage("Error: La ciudad ya existe.");
    }
}

void MainWindow::on_button_AgregarConexion_clicked()
{
    // Obtener las ciudades seleccionadas en los combobox
    QString origen = ui->comboBox->currentText();
    QString destino = ui->comboBox_2->currentText();

    // Verificar que no se está intentando conectar una ciudad consigo misma
    if (origen == destino) {
        ui->statusbar->showMessage("Error: No se puede conectar una ciudad consigo misma.");
        return;
    }

    // Abrir ventana para especificar el peso/distancia
    agregarvuelo *ventana3 = new agregarvuelo(this);

    // Pasar las ciudades seleccionadas a la ventana
    ventana3->setCiudades(origen, destino);

    // Conectar la señal que se emitirá cuando se agregue la conexión
    connect(ventana3, &agregarvuelo::conexionAgregada, this, &MainWindow::agregarConexionDesdeVentana3);

    ventana3->exec(); // Mostrar la ventana de forma modal
}

void MainWindow::agregarConexionDesdeVentana3(QString origen, QString destino, double peso)
{
    // Intentar agregar la conexión al grafo
    if (grafo.agregarConexion(origen.toStdString(), destino.toStdString(), peso)) {
        ui->statusbar->showMessage("Conexión agregada correctamente: " + origen + " -> " + destino);

        // Crear una copia del mapa original
        QPixmap mapaActualizado = originalPix.copy();
        QPainter painter(&mapaActualizado);
        painter.setRenderHint(QPainter::Antialiasing);

        // Dibujar todas las ciudades primero
        QStringList ciudadesOriginales = {
            "Alabama", "Alaska", "Arizona", "Arkansas", "California",
            "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
            "Hawaii", "Idaho", "Illinois"
        };

        // Dibujar todas las ciudades
        for (const auto& ciudad : cities.keys()) {
            QPoint pos = cities[ciudad].coordinates;

            // Si es una ciudad original, dibujarla en rojo
            if (ciudadesOriginales.contains(ciudad)) {
                painter.setBrush(QBrush(Qt::red));
            }
            // Si es una ciudad agregada posteriormente, dibujarla en verde
            else {
                painter.setBrush(QBrush(Qt::green));
            }

            painter.setPen(Qt::black);
            painter.drawEllipse(pos, 8, 8);
            painter.drawText(pos.x() + 10, pos.y() + 5, ciudad);
        }

        // Dibujar solo la nueva conexión
        if (cities.contains(origen) && cities.contains(destino)) {
            painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
            QPoint p1 = cities[origen].coordinates;
            QPoint p2 = cities[destino].coordinates;
            painter.drawLine(p1, p2);

            // Dibujar el peso de la conexión
            QPoint midPoint((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2);
            painter.drawText(midPoint, QString::number(peso));
        }

        ui->image->setPixmap(mapaActualizado);
    } else {
        ui->statusbar->showMessage("Error: No se pudo agregar la conexión.");
    }
}


void MainWindow::on_button_EliminarCiudad_clicked()
{
    eliminarciudad *ventana4 = new eliminarciudad(this);
    connect(ventana4, &eliminarciudad::ciudadEliminada, this, &MainWindow::eliminarCiudadDesdeVentana4);
    ventana4->exec();
}

void MainWindow::eliminarCiudadDesdeVentana4(QString nombre)
{
    // Intentar eliminar la ciudad del grafo
    if (grafo.eliminarCiudad(nombre.toStdString())) {
        // Remover la ciudad del mapa cities de MainWindow
        if (cities.contains(nombre)) {
            cities.remove(nombre);
        }

        // Remover la ciudad de los ComboBox
        int index1 = ui->comboBox->findText(nombre);
        if (index1 != -1) ui->comboBox->removeItem(index1);

        int index2 = ui->comboBox_2->findText(nombre);
        if (index2 != -1) ui->comboBox_2->removeItem(index2);

        // Redibujar el mapa sin la ciudad eliminada
        updateMapDisplay(QVector<QString>());

        ui->statusbar->showMessage("Ciudad eliminada exitosamente.");
    } else {
        ui->statusbar->showMessage("Error: La ciudad no existe.");
    }
}

void MainWindow::on_button_EliminarVuelo_clicked()
{
    EliminarVuelo *ventana5 = new EliminarVuelo(this, getGraph());

    // Conectar la señal con la función para eliminar la conexión
    connect(ventana5, &EliminarVuelo::vueloEliminado, this, &MainWindow::eliminarConexionDesdeVentana5);

    ventana5->exec(); // Mostrar la ventana de forma modal
}

void MainWindow::eliminarConexionDesdeVentana5(QString origen, QString destino)
{
    if (grafo.eliminarConexion(origen.toStdString(), destino.toStdString())) {
        ui->statusbar->showMessage("Vuelo eliminado: " + origen + " -> " + destino);

        // Redibujar el mapa sin la conexión eliminada
        updateMapDisplay(QVector<QString>());

    } else {
        ui->statusbar->showMessage("Error: No se pudo eliminar la conexión.");
    }
}




