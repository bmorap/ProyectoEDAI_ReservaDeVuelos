#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QMap>
#include <QPoint>
#include <QMouseEvent>
#include <QTransform>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void button(); // Tu función existente

private:
    Ui::MainWindow *ui;
    QPixmap originalPix; // Tu variable existente

    // Estructura para almacenar información de ciudades
    struct CityInfo {
        QString name;
        QPoint coordinates; // Coordenadas en el mapa
    };

    QMap<QString, CityInfo> cities; // Mapa para almacenar información de ciudades

    // Método para actualizar la visualización del mapa
    void updateMapDisplay();
};

#endif // MAINWINDOW_H
