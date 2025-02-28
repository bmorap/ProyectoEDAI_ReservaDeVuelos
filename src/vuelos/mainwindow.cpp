#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Lista de estados de EE. UU.
    QStringList estados = {
        "Alabama", "Alaska", "Arizona", "Arkansas", "California",
        "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
        "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas",
        "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts",
        "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana",
        "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico",
        "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma",
        "Oregon", "Pennsylvania", "Rhode Island", "South Carolina",
        "South Dakota", "Tennessee", "Texas", "Utah", "Vermont",
        "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"
    };

    // Agregar los estados al combo box
    ui->comboBox->addItems(estados);
    ui->comboBox_2->addItems(estados);

    // Cargar la imagen principal
    originalPix.load("/home/danna/ProyectoEDAI_ReservaDeVuelos/mapa.jpg");
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
    cities["Indiana"] = CityInfo{"Indiana", QPoint(310, 210)};
    cities["Iowa"] = CityInfo{"Iowa", QPoint(270, 200)};
    cities["Kansas"] = CityInfo{"Kansas", QPoint(240, 230)};
    cities["Kentucky"] = CityInfo{"Kentucky", QPoint(320, 230)};
    cities["Louisiana"] = CityInfo{"Louisiana", QPoint(280, 300)};
    cities["Maine"] = CityInfo{"Maine", QPoint(390, 150)};
    cities["Maryland"] = CityInfo{"Maryland", QPoint(360, 210)};
    cities["Massachusetts"] = CityInfo{"Massachusetts", QPoint(380, 170)};
    cities["Michigan"] = CityInfo{"Michigan", QPoint(310, 180)};
    cities["Minnesota"] = CityInfo{"Minnesota", QPoint(270, 170)};
    cities["Mississippi"] = CityInfo{"Mississippi", QPoint(300, 290)};
    cities["Missouri"] = CityInfo{"Missouri", QPoint(280, 240)};
    cities["Montana"] = CityInfo{"Montana", QPoint(180, 150)};
    cities["Nebraska"] = CityInfo{"Nebraska", QPoint(240, 200)};
    cities["Nevada"] = CityInfo{"Nevada", QPoint(130, 200)};
    cities["New Hampshire"] = CityInfo{"New Hampshire", QPoint(380, 160)};
    cities["New Jersey"] = CityInfo{"New Jersey", QPoint(370, 200)};
    cities["New Mexico"] = CityInfo{"New Mexico", QPoint(190, 260)};
    cities["New York"] = CityInfo{"New York", QPoint(360, 180)};
    cities["North Carolina"] = CityInfo{"North Carolina", QPoint(350, 250)};
    cities["North Dakota"] = CityInfo{"North Dakota", QPoint(230, 150)};
    cities["Ohio"] = CityInfo{"Ohio", QPoint(330, 210)};
    cities["Oklahoma"] = CityInfo{"Oklahoma", QPoint(240, 260)};
    cities["Oregon"] = CityInfo{"Oregon", QPoint(120, 160)};
    cities["Pennsylvania"] = CityInfo{"Pennsylvania", QPoint(350, 200)};
    cities["Rhode Island"] = CityInfo{"Rhode Island", QPoint(385, 175)};
    cities["South Carolina"] = CityInfo{"South Carolina", QPoint(340, 270)};
    cities["South Dakota"] = CityInfo{"South Dakota", QPoint(230, 180)};
    cities["Tennessee"] = CityInfo{"Tennessee", QPoint(310, 250)};
    cities["Texas"] = CityInfo{"Texas", QPoint(230, 290)};
    cities["Utah"] = CityInfo{"Utah", QPoint(160, 210)};
    cities["Vermont"] = CityInfo{"Vermont", QPoint(370, 160)};
    cities["Virginia"] = CityInfo{"Virginia", QPoint(350, 230)};
    cities["Washington"] = CityInfo{"Washington", QPoint(120, 130)};
    cities["West Virginia"] = CityInfo{"West Virginia", QPoint(340, 220)};
    cities["Wisconsin"] = CityInfo{"Wisconsin", QPoint(290, 180)};
    cities["Wyoming"] = CityInfo{"Wyoming", QPoint(190, 180)};

    // Conectar los eventos de cambio en los combobox
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::updateMapDisplay);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::updateMapDisplay);
}

void MainWindow::button()
{
    updateMapDisplay();
}

void MainWindow::updateMapDisplay()
{
    // Crear una copia del mapa original para dibujar encima
    QPixmap mapWithPoints = originalPix.copy();
    QPainter painter(&mapWithPoints);

    // Configurar el estilo de dibujo
    painter.setRenderHint(QPainter::Antialiasing);

    // Obtener las ciudades seleccionadas
    QString originCity = ui->comboBox->currentText();
    QString destCity = ui->comboBox_2->currentText();

    // Verificar si ambas ciudades existen en nuestro mapa
    if (cities.contains(originCity) && cities.contains(destCity)) {
        QPoint originPoint = cities[originCity].coordinates;
        QPoint destPoint = cities[destCity].coordinates;

        // Dibujar la línea entre origen y destino
        painter.setPen(QPen(Qt::blue, 3, Qt::DashLine));
        painter.drawLine(originPoint, destPoint);

        // Dibujar punto de origen (verde)
        painter.setPen(QPen(Qt::black, 1));
        painter.setBrush(QBrush(Qt::green));
        painter.drawEllipse(originPoint, 8, 8);

        // Dibujar punto de destino (rojo)
        painter.setBrush(QBrush(Qt::red));
        painter.drawEllipse(destPoint, 8, 8);

        // Opcional: Agregar etiquetas de texto para las ciudades
        painter.setPen(Qt::black);
        painter.drawText(originPoint + QPoint(10, 5), originCity);
        painter.drawText(destPoint + QPoint(10, 5), destCity);
    }

    // Actualizar la imagen en el label
    ui->image->setPixmap(mapWithPoints);
}


MainWindow::~MainWindow()
{
    delete ui;
}

