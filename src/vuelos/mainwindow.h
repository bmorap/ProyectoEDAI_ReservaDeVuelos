#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_zoominbutton_clicked();
    void on_zoomoutbutton_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap originalPix;  // Imagen original
    QPixmap zoomedPix;    // Imagen con zoom
    double zoomLevel;     // Nivel de zoom
    void applyZoom();     // Función para aplicar zoom
};

#endif // MAINWINDOW_H
